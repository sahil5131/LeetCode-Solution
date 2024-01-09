# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafFinder(self, root: Optional[TreeNode], leaf_value):
        if not root:
            return 
        if(not root.left and not root.right):
            leaf_value.append(root.val)
        self.leafFinder(root.left, leaf_value)
        self.leafFinder(root.right, leaf_value)

    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        leaf_value1 = [] 
        leaf_value2 = [] 
        self.leafFinder(root1, leaf_value1)
        self.leafFinder(root2, leaf_value2)
        return leaf_value1==leaf_value2

    

        