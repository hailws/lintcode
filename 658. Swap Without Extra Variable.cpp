/**
 *
Given two variables, x and y, swap two variables without using a third variable.

Example
Given x = 10, y = 5
Return 15.
 */
/**
������ӣ��������ʵ�����ݽ�������Ҫע����ǣ�һ��x��yָ����ͬһ����ַ���÷����ᵼ�·���ֵΪ0�������Ҫע��˲���ֵ�Ƿ���ͬ�����⡣
*/

class Solution {
public:
    /*
     * @param x: An integer
     * @param y: An integer
     * @return: nothing
     */
    void swap(int& x, int& y) {
        x=x+y;
        y=x-y;
        x=x-y;// write your code here
    }
};