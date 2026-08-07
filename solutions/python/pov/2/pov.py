"""A module for reorienting a tree and finding paths in it"""

from itertools import pairwise
from json import dumps


class Tree:
    """A Tree node"""

    def __init__(self, label, children=None):
        self.label = label
        self.children = children if children is not None else []

    def __dict__(self):
        return {self.label: [c.__dict__() for c in sorted(self.children)]}

    def __str__(self, indent=None):
        return dumps(self.__dict__(), indent=indent)

    def __lt__(self, other):
        return self.label < other.label

    def __eq__(self, other):
        return self.__dict__() == other.__dict__()

    def from_pov(self, from_node):
        """Reorient the Tree so 'from_node' becomes the root"""
        if self.label == from_node:
            return self
        path_to_target_node = self.find_descendant(from_node)
        if not path_to_target_node:
            raise ValueError("Tree could not be reoriented")

        for first, second in pairwise(path_to_target_node):
            first.children.remove(second)
            second.children.append(first)

        return path_to_target_node[-1]

    def path_to(self, from_node, to_node):
        """Find a path in the Tree from 'from_node' to 'to_node'"""
        origin = self.from_pov(from_node)
        route = origin.find_descendant(to_node)
        if not route:
            raise ValueError("No path found")
        return [node.label for node in route]

    def find_descendant(self, target_label):
        """Find a node with 'target_label' in the Tree"""
        current_path = []
        stack = [self]
        while stack:
            node = stack.pop()
            if current_path and node == current_path[-1]:
                # We have already inspected this node so discard it
                current_path.pop()
                continue
            current_path.append(node)
            if node.label == target_label:
                return current_path
            if node.children:
                stack += [node] + current_path[-1].children.copy()
            else:
                current_path.pop()
        return None
