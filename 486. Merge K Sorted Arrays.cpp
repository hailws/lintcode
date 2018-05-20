/**
Given k sorted integer arrays, merge them into one sorted array.

Example
Given 3 sorted arrays:

[
  [1, 3, 5, 7],
  [2, 4, 6],
  [0, 8, 9, 10, 11]
]
return [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].

Challenge
Do it in O(N log k).

N is the total number of integers.
k is the number of arrays.
 */
/**
合并k个排序过的序列。时间复杂度要求为O(NlogK).
利用优先队列。将个队列的头元素压入比较，每次pop出最小的，然后将被弹出的数字所属队列的下一个压入优先队列。直到排序完成。如果重载比较大小的函数，可以将iterator作为元素压入，方便判断被弹出元素的所在队列是否到尽头。这里采用了个计数序列，记录各个队列的弹出情况。
*/

class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        int len=arrays.size();
        priority_queue<int,vector<int>,greater<int>> q;
        vector<int> count(len);
        vector<int> rst;
        for(int i=0;i<len;i++){
            if(count[i]<arrays[i].size()) q.push(arrays[i][count[i]]);
        }
        while(!q.empty()){
            int tmp=q.top();
            q.pop();
            for(int i=0;i<len;i++){
                if (arrays[i][count[i]]==tmp){
                    count[i]++;
                    if(count[i]<arrays[i].size()) q.push(arrays[i][count[i]]);
                    break;
                }
            }
            rst.push_back(tmp);
        }
        return rst;// write your code here
    }
};