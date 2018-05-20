/**
Given a set of distinct integers, return all possible subsets.

 Notice
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

Example
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */
/**
方法一为递归法，元素数目为i+1的子集是通过元素数目为i的子集增加一个元素构成的，因此对元素数目递归。比如[1]->[1,2]->[1,2,3],[2]->[2,3],[3]。注意补上空集。

方法二为迭代法，
This problem can also be solved iteratively. Take [1, 2, 3] in the problem statement as an example. The process of generating all the subsets is like:
Initially: [[]]
Adding the first number to all the existed subsets: [[], [1]];
Adding the second number to all the existed subsets: [[], [1], [2], [1, 2]];
Adding the third number to all the existed subsets: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]].
通过上例可知，i+1个元素的所有子集是i个元素的所有子集并上i个元素所有子集都添上第i+1的元素的集合。

方法三为利用数位的方法。This is the most clever solution that I have seen. The idea is that to give all the possible subsets, we just need to exhaust all the possible combinations of the numbers. And each number has only two possibilities: either in or not in a subset. And this can be represented using a bit.

There is also another a way to visualize this idea. That is, if we use the above example, 1 appears once in every two consecutive subsets, 2 appears twice in every four consecutive subsets, and 3 appears four times in every eight subsets, shown in the following (initially the 8 subsets are all empty):

[], [], [], [], [], [], [], []

[], [1], [], [1], [], [1], [], [1]

[], [1], [2], [1, 2], [], [1], [2], [1, 2]

[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
*/

class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    void rec(vector<int>& nums,int l,vector<int> &ans,vector<vector<int>>& rst){
        int len=nums.size();
        rst.push_back(ans);
        for(int i=l;i<len;i++){
            ans.push_back(nums[i]);
            rec(nums,i+1,ans,rst);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> rst;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        rec(nums,0,ans,rst);
        return rst;// write your code here
    }
};

class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        int len=nums.size();
        vector<vector<int>> rst;
        rst.push_back({});
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++){
            int n=rst.size();
            for(int j=0;j<n;j++){
                vector<int> tmp=rst[j];
                tmp.push_back(nums[i]);
                rst.push_back(tmp);
            }
        }
        return rst;
        // write your code here
    }
};

class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> rst(pow(2,len),vector<int>());
        for(int i=0;i<len;i++){
            for(int j=0;j<pow(2,len);j++){
                if((j>>i)&1) rst[j].push_back(nums[i]);
            }
        }
        return rst;// write your code here
    }
};