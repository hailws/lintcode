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
��ȫ�������⣬Ҫ������Ϊǡ��װ�������Ĳ�ͬװ�������״̬ת�Ʒ���
dp[i,j]=dp[i-1,j]+dp[i,j-nums[i]],����dp[i,j]Ϊװǰi����Ʒʱ������Ϊj�ı������ܸպ�װ���Ĳ�ͬװ���������Ҫע����ǣ���ʼ��ʱdp[0]=1����Ϊ����0�ı���ʲô����װ����һ��װ���ķ�����
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