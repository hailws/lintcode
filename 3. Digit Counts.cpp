/**
Count the number of k's between 0 and n. k can be 0 - 9.

Example
if n = 12, k = 1 in

[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
we have FIVE 1's (1, 10, 11, 12)
 */

/**
�����⣬ͳ��0-n֮��ĳ�����ֳ��ֵĴ���������ͨ��ͳ�Ƹ�����λ�ĳ��ִ�������͡��Ȳ�����0�����⡣����n=121�����ͳ�Ƶڶ�λ����2�Ĵ����������1*10+1+1���ֱ�Ϊ����λ��*��ǰλ��+��λ��+��λ��ȫΪ0��Ψһ���ܡ����ͳ�Ƶڶ�λ����3�Ĵ��������Ϊ1*10����Ϊ��λ��*��ǰλ�������ͳ�Ƶڶ�λ����1�Ĵ��������Ϊ��1+1��*10��Ϊ����λ��+1��*��ǰλ�������з��ֹ��ɣ���ĳһλ������С��iʱ����ô��λ����i�Ĵ���Ϊ������λ����*��ǰλ������ĳһλ�����ֵ���iʱ����ô��λ����i�Ĵ���Ϊ������λ����*��ǰλ��+��λ����+1����ĳһλ�����ִ���iʱ����ô��λ����i�Ĵ���Ϊ��(����λ����+1)*��ǰλ��������������0�����������ļ�����û�п���0���ܳ��������λ���������˵�ͳ��0��ʱ����Ҫ��ȥ���λ��������������ǵ�nֻ��һλ������ǣ�0������������λ�������Ҫ+1��
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
