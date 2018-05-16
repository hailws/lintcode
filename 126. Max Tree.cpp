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
构造最大树，如果直接按照定义，从上而下使用递归方法做的话，时间复杂度O(n^2)。如同方法2的手段，vector操作不熟练，不清楚如何切分获得子矩阵，因此构造了不少vector，最终测试结果也是内存占用过多。
方法1就是采用了单调递减栈，即栈中每个元素都比其右边的元素大。具体方法如下：
1) 如果新来一个数，比堆栈顶的树根的数小，则把这个数作为一个单独的节点压入堆栈。
2) 否则，不断从堆栈里弹出树，新弹出的树以旧弹出的树为右子树，连接起来，直到目前堆栈顶的树根的数大于新来的数。然后，弹出的那些数，已经形成了一个新的树，这个树作为新节点的左子树，最后把这个新树压入堆栈。
这样的堆栈是单调递减的，越靠近堆栈顶的数越小。栈中存储的都是子树的根，且都只有左子树没有右子树。 最后还要按照（2）的方法，把所有树弹出来，每个旧树作为新树的右子树。
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