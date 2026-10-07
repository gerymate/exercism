""" Tree reconstructor """
def tree_from_traversals(preorder:list[str], inorder:list[str]):
    """ Rebuild a tree from preorder and inorder traversals """
    if len(preorder) != len(inorder):
        raise ValueError("traversals must have the same length")
    if set(preorder) != set(inorder):
        raise ValueError("traversals must have the same elements")
    if len(preorder) != len(set(preorder)):
        raise ValueError("traversals must contain unique items")
    if not preorder:
        return {}
    root = {}
    value = preorder[0]
    root['v'] = value
    n = inorder.index(value)
    # split inorder into two: left from inorder, right from inorder
    # let n be the length of left, m the length of right
    root['l'] = tree_from_traversals(preorder[1:n+1], inorder[:n])
    root['r'] = tree_from_traversals(preorder[n+1:], inorder[n+1:])

    return root
