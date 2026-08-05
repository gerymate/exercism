"""This module implements an IOU REST API to be used among friends"""

import json
from operator import itemgetter


class User:
    """User model encompassing lending and borrowing"""

    def __init__(self, name=None, from_dict=None):
        if from_dict:
            self.name = from_dict["name"]
            self.owes = from_dict["owes"]
            self.owed_by = from_dict["owed_by"]
            self.balance = from_dict["balance"]
        else:
            self.name = name
            self.owes = {}
            self.owed_by = {}
            self.balance = 0.0

    def lend(self, borrower, amount):
        """Transfer 'amount' to 'borrower'"""
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
        """Receive 'amount' from 'lender'"""
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
        """Render User as a dict"""
        return {
            "name": self.name,
            "owes": self.owes,
            "owed_by": self.owed_by,
            "balance": self.balance,
        }

    @staticmethod
    def json_encoder(obj):
        """Encode user as JSON"""
        if isinstance(obj, User):
            return obj.as_dict()
        raise TypeError("Cant do it")


class Database:
    """Simple storage backend"""

    def __init__(self, database=None):
        self.database = database if database else {}

    def get_all(self, table):
        """Get all data in a table"""
        if table not in self.database:
            raise ValueError(f"No such table: {table}")
        return self.database[table]

    def get(self, table: str, key, pk="name"):
        """Search 'table' for an entry where 'pk' is equal to 'key'"""
        if table not in self.database:
            raise ValueError(f"No such table: {table}")
        data = self.database[table]
        for item in data:
            if item.get(pk) == key:
                return item
        return None

    def store(self, table: str, new_item, pk="name"):
        """Store 'new_item' in 'table' where 'pk' provides identity"""
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
    """REST API for the IOU system"""

    def __init__(self, database=None):
        self.database = Database(database)

    def get(self, url, payload=None):
        """Without 'payload' list all users. With it list users named in 'payload'"""
        if url == "/users":
            if payload:
                usernames = json.loads(payload)["users"]
                users = [self.database.get("users", name) for name in usernames]
            else:
                users = self.database.get_all("users")
            users.sort(key=itemgetter("name"))
            return json.dumps({"users": users})

    def post(self, url, payload=None):
        """/add: Add new user provided in 'payload'.
        /iou: Conduct an IOU transaction described in 'payload'.
        """
        my_load = json.loads(payload)

        if url == "/add":
            user = User(my_load["user"])
            self.database.store("users", user.as_dict())
            return json.dumps(user, default=User.json_encoder)

        if url == "/iou":
            lender = User(from_dict=self.database.get("users", my_load["lender"]))
            borrower = User(from_dict=self.database.get("users", my_load["borrower"]))
            amount = my_load["amount"]
            lender.lend(borrower.name, amount)
            borrower.borrow(lender.name, amount)
            users = sorted(
                [
                    self.database.store("users", lender.as_dict()),
                    self.database.store("users", borrower.as_dict()),
                ],
                key=itemgetter("name"),
            )
            return json.dumps({"users": users}, default=User.json_encoder)
