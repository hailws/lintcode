/**
 *
An array A contains all the integers from 0 to n, except for one number which is missing. In this problem, we cannot access and entire integer in A with a single operation. The elements of A are represented in binary, and the only operation we can use to access them is "fetch the jth bit of A[i]", which takes constant time. Write code to find the missing integer. Can you do it in O(n) time?

Example
array=[4,3,2,0,5] return 1
array=[0,1,2,3,4,7,6] return 5
array=[0,1,2,3] return 4
 */

/**
 * Definition of BitInteger:
 * class BitInteger {
 * public:
 *     static int INTEGER_SIZE;
 *     int fetch(int j) {
 *         .... // return 0 or 1, fetch the jth bit of this number
 *     }
 * }
 * int BitInteger::INTEGER_SIZE = 31;
 */
 
/**
���������е����־��洢Ϊ��������ʽ��ÿ�ν���ȡ�������������е�һλ��
��ȡ���Ƚ�ÿ�����������ָ���ʮ���ƣ�Ȼ������XOR�����ԣ�
��������ÿ�������Լ�1-n��������������XOR���㣬�ó�ȱʧ��������
ʱ�临�Ӷ�O(n)
*/

class Solution {
public:
    /**
     * @param str a BitInteger list
     * @return an integer
     */
    int findMissing(vector<BitInteger>& array) {
        int len=array.size();
        int ans=0;
        for (int i=0;i<len;i++){
            int tmp=0;
            for(int j=0;j<31;j++){
                tmp+=pow(2,j)*array[i].fetch(j);
            }
            ans^=(i+1)^tmp;
        }
        return ans;// Write your code here
    }
};