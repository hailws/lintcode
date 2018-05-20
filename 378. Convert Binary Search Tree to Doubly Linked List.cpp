/**
Convert a binary search tree to doubly linked list with in-order traversal.

Example
Given a binary search tree:

    4
   / \
  2   5
 / \
1   3
return 1<->2<->3<->4<->5
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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
/**
�Ѷ���������ת����˫����������ĿҪ����dfs�����������Ϊ�˷���������ȱ��������ݴ���vector�������vector����˫������
*/

class Solution {
public:
    /*
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    void traverse(TreeNode* root,vector<int>& ans){
        if(root==nullptr) return;
        if(root->left) traverse(root->left,ans);
        ans.push_back(root->val);
        if(root->right) traverse(root->right,ans);
    }
    DoublyListNode * bstToDoublyList(TreeNode * root) {
        vector<int> ans;
        traverse(root,ans);
        int len=ans.size();
        DoublyListNode* head;
        if(len==0) return NULL;
        else head=new DoublyListNode(ans[0]);
        DoublyListNode* curr=head,*pre=nullptr;
        for(int i=1;i<len;i++){
            pre=curr;
            curr->next=new DoublyListNode(ans[i]);
            curr=curr->next;
            curr->prev=pre;
        }
        return head;// write your code here
    }
};