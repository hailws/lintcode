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
�ϲ�k������������С�ʱ�临�Ӷ�Ҫ��ΪO(NlogK).
�������ȶ��С��������е�ͷԪ��ѹ��Ƚϣ�ÿ��pop����С�ģ�Ȼ�󽫱������������������е���һ��ѹ�����ȶ��С�ֱ��������ɡ�������رȽϴ�С�ĺ��������Խ�iterator��ΪԪ��ѹ�룬�����жϱ�����Ԫ�ص����ڶ����Ƿ񵽾�ͷ����������˸��������У���¼�������еĵ��������
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