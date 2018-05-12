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
���ù�ϣ����������ÿ�������б�����������ڹ�ϣ���ҵ�taget-A[i]����A[i]��taget-A[i]����������������A[i]�����ϣ��ռ���ڴ�O(n)����ϣ�����ʱ�临�Ӷ�ΪO(1)�������ΪO(n)�����ʱ�临�Ӷ�ΪO(n)��
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

