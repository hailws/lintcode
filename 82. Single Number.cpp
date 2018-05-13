/**
Given 2*n + 1 numbers, every numbers occurs twice except one, find it.

Example
Given [1,2,2,1,3,4,3], return 4
 */
/**
��2n+1�����֣����г���һ���������⣬�����Ķ����ֹ����Σ��ҳ�������֡�����XOR����ֵi XOR i=0���������е�ÿ����������XOR���㣬���ս����ΪҪ�ҵ����֡�
*/

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        int len=A.size(),res=0;
        for(int i=0;i<len;i++){
            res^=A[i];
        }
        return res;// write your code here
    }
};

