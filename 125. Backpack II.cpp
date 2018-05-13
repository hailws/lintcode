/**
Given n items with size Ai and value Vi, and a backpack with size m. What's the maximum value can you put into the backpack?

 Notice
You cannot divide item into small pieces and the total size of items you choose should smaller or equal to m.

Example
Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4], and a backpack with size 10. The maximum value is 9.
 */
/**
01背包问题，dp[i,j]表示装前i种物品，容量位j的背包最多能装的价值大小。递推关系dp[i,j]=max{dp[i-1,j],dp[i-1,j-A[i]]+V[i]}。
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        int len=A.size();
        vector<int> dp(m+1);
        for(int i=0;i<len;i++){
            for(int j=m;j>=A[i];j--){
                dp[j]=max(dp[j],dp[j-A[i]]+V[i]);
            }
        }
        return dp[m];// write your code here
    }
};