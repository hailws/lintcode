/**
Write an algorithm which computes the number of trailing zeros in n factorial.

Example
11! = 39916800, so the out should be 2
 */
/**
求阶乘有几个尾数0。阶乘中2出现的次数多于5的次数，因此只要求有多少5即可。每5个连续的数有5个5，每25个连续的数有一个25，以此类推，只要对（N/（5^k））进行取整求和即可（k=1...)
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