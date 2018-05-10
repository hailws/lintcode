/**
Write an algorithm which computes the number of trailing zeros in n factorial.

Example
11! = 39916800, so the out should be 2
 */
/**
��׳��м���β��0���׳���2���ֵĴ�������5�Ĵ��������ֻҪ���ж���5���ɡ�ÿ5������������5��5��ÿ25������������һ��25���Դ����ƣ�ֻҪ�ԣ�N/��5^k��������ȡ����ͼ��ɣ�k=1...)
*/

class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long n) {
        long sum=0;
        while(n){
            sum+=n/5;
            n/=5;
        };
        return sum;// write your code here, try to do it without arithmetic operators.
    }
};