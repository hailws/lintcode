/**
Given a non-overlapping interval list which is sorted by start point.

Insert a new interval into it, make sure the list is still in order and non-overlapping (merge intervals if necessary).

Have you met this question in a real interview?
Example
Insert (2, 5) into [(1,2), (5,9)], we get [(1,9)].

Insert (3, 4) into [(1,2), (5,9)], we get [(1,2), (3,4), (5,9)].
 */
/**
Subsets的有重复版本，只要在其基础上去重即可。对于递归方法，只要判断当前数字是否和之前数字相同，若相同且未被使用过，则说明之前有个已被使用的分支，需要跳过此种情况。对于迭代方法，如果当前数字和之前相同，则只能在已经出现过当前数字的子集中再插入新数字。
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    void dfs(vector<int>& nums,vector<bool>& used,int pos,vector<int>& ans,vector<vector<int>>& rst){
        int len=nums.size();
        rst.push_back(ans);
        for(int i=pos;i<len;i++){
            if(i>0 && nums[i]==nums[i-1] && used[i-1]==false) continue;
            ans.push_back(nums[i]);
            used[i]=true;
            dfs(nums,used,i+1,ans,rst);
            ans.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> rst;
        vector<int> ans;
        vector<bool> used(nums.size(),false);
        dfs(nums,used,0,ans,rst);
        return rst;// write your code here
    }
};

class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        int len=nums.size(),last=0,cur;
        vector<vector<int>> rst;
        sort(nums.begin(),nums.end());
        rst.push_back({});
        last=1;
        for(int i=0;i<len;i++){
            cur=rst.size();
            if(i>0 && nums[i]==nums[i-1]){
                for(int j=last;j<cur;j++){
                    vector<int> tmp=rst[j];
                    tmp.push_back(nums[i]);
                    rst.push_back(tmp);
                }
            }
            else{
                for(int j=0;j<cur;j++){
                    vector<int> tmp=rst[j];
                    tmp.push_back(nums[i]);
                    rst.push_back(tmp);
                }
            }
            last=cur;
        }
        return rst;// write your code here
    }
};