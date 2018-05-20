/**
Given a list of numbers with duplicate number in it. Find all unique permutations.

Example
For numbers [1,2,2] the unique permutations are:

[
  [1,2,2],
  [2,1,2],
  [2,2,1]
]
 */
/**
有重复数字的全排列，可以直接利用set的性质，将所有可能的排列（包括重复的）插入set，重复的插入操作会失败，最后遍历set存入vector即可。
借鉴无重复数字全排列的思想，为了去重，只要保证每个数位，相同的数字只出现一次。这里两种方法分别采用了在每层递归利用hash保证不重复和通过比较[idx, ... i - 1]，来确定没有重复。
还有一种去重方法是nums[i] == nums[i - 1] && isUsed[i - 1] == false，如果相同的数，前面没用过（说明当前数位已经使用过了），就不能用。
另外也可以先对数组排序后，用next_permutation做，很不幸的是自写的函数使用内存过多。
*/

class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    void dfs(vector<int>& nums,int pos, set<vector<int>>& rst){
        int len=nums.size();
        if(pos==len-1) {
            rst.insert(nums);
            return;
        }
        for(int i=pos;i<len;i++){
            swap(nums[i],nums[pos]);
            dfs(nums,pos+1,rst);
            swap(nums[i],nums[pos]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        set<vector<int>> rst;
        dfs(nums,0,rst);
        vector<vector<int>>ans;
        if(rst.empty()) ans.push_back(nums);
        for(auto i:rst){
            ans.push_back(i);
        }
        return ans;// write your code here
    }
};
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, res);
        return res;
    }
private:
    void dfs(vector<int>& nums, int idx, vector<vector<int>> &res) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            int j = i - 1;
            while (j >= idx && nums[j] != nums[i]) j--;
            if ( j == idx - 1) {
// if i == idx or nums[i] does not equal to any vals in nums[idx, ... i - 1]
                swap(nums[idx], nums[i]);
                dfs(nums, idx + 1, res);
                swap(nums[idx], nums[i]);
            }
        }
    }
};
class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    void dfs(unordered_map<int,int>& mp,int pos,vector<int>& ans,vector<vector<int>>& rst){
        if(pos<=0){
            rst.push_back(ans);
            return;
        }
        for(auto& i:mp){
            if(i.second==0) continue;
            else{
                i.second--;
                ans.push_back(i.first);
                dfs(mp,pos-1,ans,rst);
                i.second++;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        unordered_map<int,int> mp;
        for(int i:nums){
            if(mp.find(i)==mp.end()) mp[i]=1;
            else mp[i]++;
        }
        for(auto i:mp){
            cout<<i.first<<" "<<i.second<<endl;
        }
        vector<int> ans;
        vector<vector<int>> rst;
        dfs(mp,nums.size(),ans,rst);
        return rst;// write your code here
    }
};