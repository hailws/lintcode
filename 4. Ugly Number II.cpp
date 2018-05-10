/**
Ugly number is a number that only have factors 2, 3 and 5.

Design an algorithm to find the nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

Notice
Note that 1 is typically treated as an ugly number.

Example
If n=9, return 10.

Challenge
O(n log n) or O(n) time.
 */
/**
找第n个丑数，根据丑数性值可知，每一个丑数都是前面某个丑数*2、*3、*5所得。因此，用三个指针分别对应*2、*3、*5，从第一个丑数开始，分别*2、*3、*5，将小的计入结果后，对应的指针向后挪一位。直到获得第n个丑数。
另外此题也可以利用priority queue做，每次将queue头的数取出，将*2、*3、*5推入queue，直到取出了n个数。

class Solution {
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        vector<int> uglys(1,1);
        int p2=0,p3=0,p5=0;
        while(uglys.size()<n){
            int ugly2=uglys[p2]*2,ugly3=uglys[p3]*3,ugly5=uglys[p5]*5;
            int min_u=min(ugly2,min(ugly3,ugly5));
            if (min_u==ugly2){ p2++;}
            if (min_u==ugly3){p3++;}
            if (min_u==ugly5){p5++;}
            uglys.push_back(min_u);
        }
        return uglys[n-1];// write your code here
    }
};
