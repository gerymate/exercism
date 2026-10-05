""" BinarySearchTree """

class TreeNode:
    """ A subtree in a BinarySearchTree """

    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def __str__(self):
        return f'TreeNode(data={self.data}, left={self.left}, right={self.right})'

    def insert_subtree(self, subtree):
        """ Place a subtree into this one """
        if subtree.data <= self.data:
            if self.left:
                self.left.insert_subtree(subtree)
            else:
                self.left = subtree
        else:
            if self.right:
                self.right.insert_subtree(subtree)
            else:
                self.right = subtree

    def get_values(self):
        """ Get all values in sorted order from the subtree """
        left = self.left.get_values() if self.left else []
        right = self.right.get_values() if self.right else []
        return left + [self.data] + right

class BinarySearchTree:
    """ A binary tree """
    def __init__(self, tree_data: [str]):
        self.root = TreeNode(tree_data[0])
        for value in tree_data[1:]:
            subtree = TreeNode(value)
            self.root.insert_subtree(subtree)

    def data(self):
        """ Return the tree """
        return self.root

    def sorted_data(self):
        """ Return all data in sorted order """
        return self.root.get_values()
