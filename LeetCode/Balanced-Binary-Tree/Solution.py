1#Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7
8from typing import Optional
9
10class Solution:
11    def isBalanced(self, root: Optional[TreeNode]) -> bool:
12        """
13        Determines if a binary tree is height-balanced.
14        A height-balanced tree is defined as a tree where the depth of the two subtrees 
15        of every node never differs by more than 1.
16      
17        Args:
18            root: The root node of the binary tree
19          
20        Returns:
21            True if the tree is balanced, False otherwise
22        """
23      
24        def calculate_height(node: Optional[TreeNode]) -> int:
25            """
26            Calculates the height of a subtree while checking if it's balanced.
27          
28            Args:
29                node: Current node being processed
30              
31            Returns:
32                The height of the subtree if balanced, -1 if unbalanced
33            """
34            # Base case: empty node has height 0
35            if node is None:
36                return 0
37          
38            # Recursively calculate heights of left and right subtrees
39            left_height = calculate_height(node.left)
40            right_height = calculate_height(node.right)
41          
42            # Check if any subtree is unbalanced or if current node violates balance condition
43            if (left_height == -1 or 
44                right_height == -1 or 
45                abs(left_height - right_height) > 1):
46                return -1  # Return -1 to indicate unbalanced tree
47          
48            # Return height of current subtree (1 + maximum height of children)
49            return 1 + max(left_height, right_height)
50      
51        # Tree is balanced if height calculation doesn't return -1
52        return calculate_height(root) >= 0
53