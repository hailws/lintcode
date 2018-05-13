/**
Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack?

 Notice
You can not divide any item into small pieces.

Example
If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, we can select [2, 3, 5], so that the max size we can fill this backpack is 10. If the backpack size is 12. we can select [2, 3, 7] so that we can fulfill the backpack.

You function should return the max size we can fill in the given backpack.
 */
/**
01背包问题，dp[i,j]表示装前i种物品，容量位j的背包最多能装的容量大小。递推关系dp[i,j]=max{dp[i-1,j],dp[i-1,j-A[i]]+A[i]}。
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        int len=A.size();
        vector<int> dp(m+1,0);
        for(int i=0;i<len;i++){
            for(int j=m;j>=A[i];j--){
                dp[j]=max(dp[j],dp[j-A[i]]+A[i]);
            }
        }
        return dp[m];// write your code here
    }
};