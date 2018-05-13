/**
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example
Given a binary tree as follow:

  1
 / \
2   3
   / \
  4   5
The maximum depth is 3.
 */
/**
计算数的层数，最直接的想法就是dfs递归做法。也可以用bfs层层迭代找出层数。
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode * root) {
        if(root!=NULL){
            return 1+max(maxDepth(root->left),maxDepth(root->right));
        }
        else return 0;// write your code here
    }

int maxDepth(TreeNode *root)
{
    if(root == NULL)
        return 0;

    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        ++ res;
        for(int i = 0, n = q.size(); i < n; ++ i)
        {
            TreeNode *p = q.front();
            q.pop();

            if(p -> left != NULL)
                q.push(p -> left);
            if(p -> right != NULL)
                q.push(p -> right);
        }
    }

    return res;
}
};
