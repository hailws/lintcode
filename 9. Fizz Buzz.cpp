/**
Given number n. Print number from 1 to n. But:

when number is divided by 3, print "fizz".
when number is divided by 5, print "buzz".
when number is divided by both 3 and 5, print "fizz buzz".

Example
If n = 15, you should return:

[
  "1", "2", "fizz",
  "4", "buzz", "fizz",
  "7", "8", "fizz",
  "buzz", "11", "fizz",
  "13", "14", "fizz buzz"
]
 */
/**
if语句的运用，注意分情况讨论即可
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        vector<string> str(n);
        for(int i=1;i<=n;i++){
            if(i%3==0) str[i-1]+="fizz";
            if(i%15==0) str[i-1]+=" ";
            if(i%5==0) str[i-1]+="buzz";
            if(str[i-1].empty()) str[i-1]=to_string(i);
        }
        return str;// write your code here
    }
};

