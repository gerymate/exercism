""" Build a tree from database records """
import dataclasses

@dataclasses.dataclass
class Record:
    """ Database record. parent_id is always <= record_id """
    record_id: int
    parent_id: int
    def validate_parent_id(self):
        """ Ensure proper id ordering """
        if self.record_id == 0 and self.parent_id != 0:
            raise ValueError('Node parent_id should be smaller than its record_id.')
        if self.record_id < self.parent_id:
            raise ValueError('Node parent_id should be smaller than its record_id.')
        if self.record_id == self.parent_id and self.record_id != 0:
            raise ValueError('Only root should have equal record and parent id.')


@dataclasses.dataclass
class Node:
    """ A tree node """
    node_id: int
    children: [Node] = dataclasses.field(default_factory=list)

def BuildTree(records):
    """ Build a tree from the db records. Validate tree structure. """
    root = None
    records.sort(key=lambda x: x.record_id)
    ordered_ids = [i.record_id for i in records]
    if records:
        if ordered_ids[-1] != len(ordered_ids) - 1:
            raise ValueError('Record id is invalid or out of order.')
        if ordered_ids[0] != 0:
            raise ValueError('invalid')
    trees = []
    parent = {}
    for next_id in ordered_ids:
        for record in records:
            if next_id == record.record_id:
                record.validate_parent_id()
                trees.append(Node(next_id))
    for next_id in range(len(records)):
        parent = next(tree for tree in trees if tree.node_id == next_id)
        for record in records:
            if record.parent_id == next_id:
                for tree in trees:
                    if tree.node_id == 0:
                        continue
                    if record.record_id == tree.node_id:
                        child = tree
                        parent.children.append(child)
    if len(trees) > 0:
        root = trees[0]
    return root
