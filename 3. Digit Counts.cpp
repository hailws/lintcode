/**
Count the number of k's between 0 and n. k can be 0 - 9.

Example
if n = 12, k = 1 in

[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
we have FIVE 1's (1, 10, 11, 12)
 */

/**
计数题，统计0-n之间某个数字出现的次数。可以通过统计各个数位的出现次数来求和。先不考虑0的问题。举例n=121，如果统计第二位出现2的次数，结果是1*10+1+1，分别为，高位数*当前位数+低位数+低位数全为0的唯一可能。如果统计第二位出现3的次数，结果为1*10，即为高位数*当前位数。如果统计第二位出现1的次数，结果为（1+1）*10，为（高位数+1）*当前位数。从中发现规律，当某一位的数字小于i时，那么该位出现i的次数为：更高位数字*当前位数。当某一位的数字等于i时，那么该位出现i的次数为：更高位数字*当前位数+低位数字+1。当某一位的数字大于i时，那么该位出现i的次数为：(更高位数字+1)*当前位数。接下来考虑0的情况，上面的计数并没有考虑0不能出现在最高位的情况，因此当统计0的时候需要除去最高位个数的情况，但是当n只有一位的情况是，0允许出现在最高位，因此需要+1。
*/

class Solution {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
        int result=0;
        int base=1;
        while(n/base>0){
            int cur=(n/base);
            int low=n-(n/base)*base;
            int high=n/(base*10);
            if(cur==k){
                result+=high*base+low+1;
            } else if(cur<k){
                result+=high*base;
            } else{
                result+=(high+1)*base;
            }
            base*=10;
        }

        if (k==0){
            result-=base/10;
            if(base<=10){
                result+=1;
            }
        }
        return result;
    }// write your code here
};
