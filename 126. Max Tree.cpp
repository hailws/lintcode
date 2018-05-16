/**
Given an integer array with no duplicates. A max tree building on this array is defined as follow:

The root is the maximum number in the array
The left subtree and right subtree are the max trees of the subarray divided by the root number.
Construct the max tree by the given array.

Example
Given [2, 5, 6, 0, 3, 1], the max tree constructed by this array is:

    6
   / \
  5   3
 /   / \
2   0   1
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
��������������ֱ�Ӱ��ն��壬���϶���ʹ�õݹ鷽�����Ļ���ʱ�临�Ӷ�O(n^2)����ͬ����2���ֶΣ�vector���������������������зֻ���Ӿ�����˹����˲���vector�����ղ��Խ��Ҳ���ڴ�ռ�ù��ࡣ
����1���ǲ����˵����ݼ�ջ����ջ��ÿ��Ԫ�ض������ұߵ�Ԫ�ش󡣾��巽�����£�
1) �������һ�������ȶ�ջ������������С������������Ϊһ�������Ľڵ�ѹ���ջ��
2) ���򣬲��ϴӶ�ջ�ﵯ�������µ��������Ծɵ�������Ϊ������������������ֱ��Ŀǰ��ջ��������������������������Ȼ�󣬵�������Щ�����Ѿ��γ���һ���µ������������Ϊ�½ڵ���������������������ѹ���ջ��
�����Ķ�ջ�ǵ����ݼ��ģ�Խ������ջ������ԽС��ջ�д洢�Ķ��������ĸ����Ҷ�ֻ��������û���������� ���Ҫ���գ�2���ķ���������������������ÿ��������Ϊ��������������
*/

class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode * maxTree(vector<int> &A) {
        int len=A.size();
        if(len==0) return NULL;
        TreeNode* node=new TreeNode(A[0]);
        stack<TreeNode*> s;
        s.push(node);
        for(int i=1;i<len;i++){
            if(A[i]<s.top()->val){
                TreeNode* tmp=new TreeNode(A[i]);
                s.push(tmp);
            }
            else {
                TreeNode* n1=s.top();
                s.pop();
                while(!s.empty() && A[i]>s.top()->val){
                    TreeNode* n2=s.top();
                    n2->right=n1;
                    n1=n2;
                    s.pop();
                }
                TreeNode* n=new TreeNode(A[i]);
                n->left=n1;
                s.push(n);
            }
        }
        TreeNode* root=s.top();
        s.pop();
        while(!s.empty()){
            s.top()->right=root;
            root=s.top();
            s.pop();
        }
        return root;// write your code here
    }
};

class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    int findidx(vector<int>& A){
        int max=INT_MIN,idx=0;
        for(int i=0;i<A.size();i++){
            if(max<A[i]){
                max=A[i];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> slc(vector<int>& A,int left,int right){
        int len=A.size();
        vector<int> rst;
        for(int i=left;i<=right;i++){
            rst.push_back(A[i]);
        }
        return rst;
    }
    TreeNode * maxTree(vector<int> &A) {
        int len=A.size();
        if(len==0) return NULL;
        int idx=findidx(A);
        TreeNode* node=new TreeNode(A[idx]);
        if(idx>0){
            vector<int> left=slc(A,0,idx-1);
            node->left=maxTree(left);
        }
        if(idx<len-1){
            vector<int> right=slc(A,idx+1,len-1);
            node->right=maxTree(right);
        }
        return node;// write your code here
    }
};