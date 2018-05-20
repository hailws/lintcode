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
���ظ����ֵ�ȫ���У�����ֱ������set�����ʣ������п��ܵ����У������ظ��ģ�����set���ظ��Ĳ��������ʧ�ܣ�������set����vector���ɡ�
������ظ�����ȫ���е�˼�룬Ϊ��ȥ�أ�ֻҪ��֤ÿ����λ����ͬ������ֻ����һ�Ρ��������ַ����ֱ��������ÿ��ݹ�����hash��֤���ظ���ͨ���Ƚ�[idx, ... i - 1]����ȷ��û���ظ���
����һ��ȥ�ط�����nums[i] == nums[i - 1] && isUsed[i - 1] == false�������ͬ������ǰ��û�ù���˵����ǰ��λ�Ѿ�ʹ�ù��ˣ����Ͳ����á�
����Ҳ�����ȶ������������next_permutation�����ܲ��ҵ�����д�ĺ���ʹ���ڴ���ࡣ
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