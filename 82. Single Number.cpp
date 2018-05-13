/**
Given 2*n + 1 numbers, every numbers occurs twice except one, find it.

Example
Given [1,2,2,1,3,4,3], return 4
 */
/**
有2n+1个数字，其中除了一个数字以外，其他的都出现过两次，找出这个数字。利用XOR的性值i XOR i=0，将数组中的每个数都进行XOR运算，最终结果即为要找的数字。
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

