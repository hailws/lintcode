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
�ҵ�n�����������ݳ�����ֵ��֪��ÿһ����������ǰ��ĳ������*2��*3��*5���á���ˣ�������ָ��ֱ��Ӧ*2��*3��*5���ӵ�һ��������ʼ���ֱ�*2��*3��*5����С�ļ������󣬶�Ӧ��ָ�����Ųһλ��ֱ����õ�n��������
�������Ҳ��������priority queue����ÿ�ν�queueͷ����ȡ������*2��*3��*5����queue��ֱ��ȡ����n������

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
