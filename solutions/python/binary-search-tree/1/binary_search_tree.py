class TreeNode:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def __str__(self):
        return f'TreeNode(data={self.data}, left={self.left}, right={self.right})'

    def _insert_subtree(self, subtree):
        if subtree.data <= self.data:
            if self.left:
                self.left._insert_subtree(subtree)
            else:
                self.left = subtree
        else:
            if self.right:
                self.right._insert_subtree(subtree)
            else:
                self.right = subtree
 
    def _get_values(self):
        left = self.left._get_values() if self.left else []
        right = self.right._get_values() if self.right else []
        return left + [self.data] + right

class BinarySearchTree:
    def __init__(self, tree_data: [str]):
        self.root = TreeNode(tree_data[0])
        for value in tree_data[1:]:
            subtree = TreeNode(value)
            self.root._insert_subtree(subtree)

    def data(self):
        return self.root

    def sorted_data(self):
        return self.root._get_values()
        

           
