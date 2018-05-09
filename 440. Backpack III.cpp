/**
 *
Given n kind of items with size Ai and value Vi( each item has an infinite number available) and a backpack with size m. What's the maximum value can you put into the backpack?

Notice
You cannot divide item into small pieces and the total size of items you choose should smaller or equal to m.

Example
Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4], and a backpack with size 10. The maximum value is 15.
 */
 
/**
完全背包问题，利用状态转移方程dp[i,j]=max(dp[i-1,j],dp[i,j-A[i]]+V[i]),
其中，dp[i,j]为容量为j的背包，前i个物品放入，所能获得的最大价值。A[i]为第i件物品大小，V[i]为第i件物品价值。由于不要求装满背包，因此任意容量的空背包都是一个合法状态，因此dp数组的初始化值全为0。
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