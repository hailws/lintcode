/**
 *
Given two variables, x and y, swap two variables without using a third variable.

Example
Given x = 10, y = 5
Return 15.
 */
/**
利用相加，再相减来实现数据交换。需要注意的是，一旦x和y指向了同一个地址，该方法会导致返回值为0，因此需要注意核查数值是否相同的问题。
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