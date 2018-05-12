/**
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are zero-based.

 Notice
You may assume that each input would have exactly one solution

Example
numbers=[2, 7, 11, 15], target=9

return [0, 1]
 */
/**
利用哈希表，对数组中每个数进行遍历，如果能在哈希表找到taget-A[i]，则将A[i]和taget-A[i]当作结果输出，否则将A[i]存入哈希表。占用内存O(n)，哈希表查找时间复杂度为O(1)，最糟糕为O(n)，因此时间复杂度为O(n)。
*/

class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        int len=numbers.size();
        vector<int> res;
        unordered_map<int,int>mymap;
        for(int i=0;i<len;i++){
            int com=target-numbers[i];
            unordered_map<int,int>::iterator pos;
            pos=mymap.find(com);
            if(pos!=mymap.end()){
                res.push_back(mymap[com]);
                res.push_back(i);
                return res;
            }
            mymap[numbers[i]]=i;
        }// write your code here
    }
};

