/**
 *
Description: Given a number n, return the double factorial of the number.In mathematics,
the product of all the integers from 1 up to some non-negative integer n that have the same parity (odd or even) as n is called the double factorial.

Notice
We guarantee that the result does not exceed long.
n is a positive integer

Example
Given n = 5, return 15.

Explanation:
5!! = 5 * 3 * 1 = 15
Given n = 6, return 24.

Explanation:
6!! = 6 * 4 * 2 = 24
 */

class Solution {
public:
    /**
     * @param n: the given number
     * @return:  the double factorial of the number
     */
    long long doubleFactorial(int n) {
        long long res=1;
        while(n>2){
            res*=n--;
            --n;
        }
        if (n==2) res*=2;
        return res;// Write your code here
    }
};