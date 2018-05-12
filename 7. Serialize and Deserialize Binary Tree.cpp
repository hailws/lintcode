/**
Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.

 Notice
There is no limit of how you deserialize or serialize a binary tree, LintCode will take your output of serialize as the input of deserialize, it won't check the result of serialize.

Example
An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote the following structure:

  3
 / \
9  20
  /  \
 15   7
Our data serialization use bfs traversal. This is just for when you got wrong answer and want to debug the input.

You can use other method to do serializaiton and deserialization.
 */
/**
二叉树的序列化和重组。考察的是bfs。可以采用递归和迭代。其中迭代借助了队列queue，迭代的重组采用了二级指针，可以避免root的特例。
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


class Solution{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }
    string serialize(TreeNode* root){
        queue<TreeNode*> myque;
        string str;
        myque.push(root);
        while(!myque.empty()){
            TreeNode* tmp=myque.front();
            if(tmp==nullptr) str+="#,";
            else {
                str=str+to_string(tmp->val)+',';
                myque.push(tmp->left);
                myque.push(tmp->right);
            }
            myque.pop();
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        queue<TreeNode**> q;
        q.push(&root);
        string::iterator first = data.begin();
        while (first != data.end()) {
            TreeNode** pp = q.front();
            if (*first == '#') {
                first+=2;
            } else {
                string::iterator last = find(first, data.end(), ',');
                int val = stoi(string(first, last));
                *pp = new TreeNode(val);
                q.push(&((*pp)->left));
                q.push(&((*pp)->right));
                first = next(last);
            }
            q.pop();
        }
        return root;
    }
    
    TreeNode* deserialize(string data) {
        return mydeserialize(data);
    }
    TreeNode* mydeserialize(string& data) {
        if (data[0]=='#') {
            if(data.size() > 1) data = data.substr(2);
            return nullptr;
        } else {
            TreeNode* node = new TreeNode(helper(data));
            node->left = mydeserialize(data);
            node->right = mydeserialize(data);
            return node;
        }
    }

private:
    int helper(string& data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }
};

