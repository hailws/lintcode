/**
 *
Given n items with size nums[i] which an integer array and all positive numbers, no duplicates. An integer target denotes the size of a backpack. Find the number of possible fill the backpack.

Each item may be chosen unlimited number of times

Example
Given candidate items [2,3,6,7] and target 7,

A solution set is:
[7]
[2, 2, 3]
return 2
 */

/**
完全背包问题，要求的输出为恰好装满背包的不同装填方法数。状态转移方程
dp[i,j]=dp[i-1,j]+dp[i,j-nums[i]],其中dp[i,j]为装前i件物品时，容量为j的背包所能刚好装满的不同装填方法数。需要注意的是，初始化时dp[0]=1，因为容量0的背包什么都不装算是一种装满的方法。
*/

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        int len=nums.size();
        vector<int> dp(target+1,0);
        dp[0]=1;
        for(int i=0;i<len;i++){
            for(int j=nums[i];j<=target;j++){
                dp[j]=dp[j]+dp[j-nums[i]];
            }
        }
        return dp[target];// write your code here
    }
};