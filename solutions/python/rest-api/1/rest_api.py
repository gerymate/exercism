import json
from operator import itemgetter

class User:
    def __init__(self, name=None, from_dict=None):
        if from_dict:
            self.name = from_dict['name']
            self.owes = from_dict['owes']
            self.owed_by = from_dict['owed_by']
            self.balance = from_dict['balance']
        else:
            self.name = name
            self.owes = dict()
            self.owed_by = dict()
            self.balance = 0.0

    def lend(self, borrower, amount):
        self.balance += amount
        if borrower in self.owes:
            diff = self.owes[borrower] - amount
            if diff <= 0.0:
                del self.owes[borrower]
                amount = -diff
            else:
                self.owes[borrower] -= amount
                amount = 0.0
        if amount > 0.0:
            self.owed_by[borrower] = self.owed_by.get(borrower, 0.0) + amount

    def borrow(self, lender, amount):
        self.balance -= amount
        if lender in self.owed_by:
            diff = self.owed_by[lender] - amount
            if diff <= 0:
                del self.owed_by[lender]
                amount = -diff
            else:
                self.owed_by[lender] -= amount
                amount = 0.0
        if amount > 0.0:            
            self.owes[lender] = self.owes.get(lender, 0.0) + amount

    def as_dict(self):
        return {
            'name': self.name,
            'owes': self.owes,
            'owed_by': self.owed_by,
            'balance': self.balance
        }

    def json_encoder(obj):
        if isinstance(obj, User):
            return obj.as_dict()
        else:
            raise ValueError('Cant do it')


class Database:
    def __init__(self, database=None):
        self.database = database if database else dict()

    def get_all(self, table):
        if table not in self.database:
            raise ValueError(f"No such table: {table}")
        return self.database[table]

    def get(self, table: str, key, pk='name'):
        if table not in self.database:
            raise ValueError(f"No such table: {table}")
        data = self.database[table]
        for item in data:
            if item.get(pk) == key:
                return item
        return None

    def store(self, table: str, new_item, pk='name'):
        if table not in self.database:
            raise ValueError(f"No such table: {table}")
        data = self.database[table]
        for item in data:
            if item.get(pk) == new_item.get(pk):
                item.update(new_item)
                return new_item
        data.append(new_item)
        return new_item


class RestAPI:
    def __init__(self, database=None):
        self.database = Database(database)

    def get(self, url, payload=None):
        if url == '/users':
            if payload:
                usernames = json.loads(payload)['users']
                users = [self.database.get('users', name) for name in usernames]
            else:
                users = self.database.get_all('users')
            users.sort(key=itemgetter('name'))
            return json.dumps({'users': users})

    def post(self, url, payload=None):
        my_load = json.loads(payload)
        
        if url == '/add':
            user = User(my_load['user'])
            self.database.store('users', user.as_dict())
            return json.dumps(user, default=User.json_encoder)

        if url == '/iou':
            lender = User(from_dict= self.database.get('users', my_load['lender']))
            borrower = User(from_dict= self.database.get('users', my_load['borrower']))
            amount = my_load['amount']
            lender.lend(borrower.name, amount)
            borrower.borrow(lender.name, amount)
            users = sorted([
                self.database.store('users', lender.as_dict()),
                self.database.store('users', borrower.as_dict())
            ], key=itemgetter('name'))
            return json.dumps({'users': users}, default=User.json_encoder)

