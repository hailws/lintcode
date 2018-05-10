/**
Write a function that add two numbers A and B. You should not use + or any arithmetic operators.

 Notice
There is no need to read data from standard input stream. Both parameters are given in function aplusb, you job is to calculate the sum and return it.

Clarification
Are a and b both 32-bit integers?

Yes.
Can I use bit operation?

Sure you can.
Example
Given a=1 and b=2 return 3
 */
/**
实现两数的加法。通过观察我们发现，a^b的结果就是a+b不包括进位的结果。a&b的结果向左移一位就是a+b进位结果。因此可以不停的进行（当前位XOR进位）的操作，直到进位为0时，XOR的结果就是a+b
*/

class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        int sum=a;
        int carry=b;
        int tmp;
        while(carry){
            tmp=sum^carry;
            carry=(sum&carry)<<1;
            sum=tmp;
        }
        return sum;// write your code here
    }
};