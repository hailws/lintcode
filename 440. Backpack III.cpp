/**
 *
Given n kind of items with size Ai and value Vi( each item has an infinite number available) and a backpack with size m. What's the maximum value can you put into the backpack?

Notice
You cannot divide item into small pieces and the total size of items you choose should smaller or equal to m.

Example
Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4], and a backpack with size 10. The maximum value is 15.
 */
 
/**
��ȫ�������⣬����״̬ת�Ʒ���dp[i,j]=max(dp[i-1,j],dp[i,j-A[i]]+V[i]),
���У�dp[i,j]Ϊ����Ϊj�ı�����ǰi����Ʒ���룬���ܻ�õ�����ֵ��A[i]Ϊ��i����Ʒ��С��V[i]Ϊ��i����Ʒ��ֵ�����ڲ�Ҫ��װ��������������������Ŀձ�������һ���Ϸ�״̬�����dp����ĳ�ʼ��ֵȫΪ0��
*/

class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        int len=A.size();
        vector<int> dp(m+1,0);
        for(int i=0;i<len;i++){
            for(int j=A[i];j<=m;j++){
                dp[j]=max(dp[j],dp[j-A[i]]+V[i]);
            }
        }
        return dp[m];// write your code here
    }
};