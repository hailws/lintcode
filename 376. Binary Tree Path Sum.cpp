/**
Given a binary tree, find all paths that sum of the nodes in the path equals to a given number target.

A valid path is from root node to any of the leaf nodes.

Example
Given a binary tree, and target = 5:

     1
    / \
   2   4
  / \
 2   3
return

[
  [1, 2, 2],
  [1, 4]
]
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
/**
利用先序dfs，因为要记录路径。需要注意的是要求的是到叶子节点的路径，中途不计入结果。
*/

class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */

    void traverse(TreeNode* root,int target,int sum,vector<int> ans,vector<vector<int>>& rst){
        if(root!=NULL) {
            sum+=root->val;
            ans.push_back(root->val);
            if(root->left==NULL && root->right==NULL) {
                if(sum==target){
                    rst.push_back(ans);
                }
            }
            if(root->left) traverse(root->left,target,sum,ans,rst);
            if(root->right) traverse(root->right,target,sum,ans,rst);
        }
    }
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        int sum=0;
        vector<int> ans;
        vector<vector<int>> rst;
        traverse(root,target,sum,ans,rst);
        return rst;// write your code here
    }
};