/**
Singleton is a most widely used design pattern. If a class has and only has one instance at every moment, we call this design as singleton. For example, for class Mouse (not a animal mouse), we should design it in singleton.

You job is to implement a getInstance method for given class, return the same instance of this class every time you call this method.

Example
In Java:

A a = A.getInstance();
A b = A.getInstance();
a should equal to b.
 */
/**
单例，这里采用的是饿汉模式。无法保证初始化顺序。详细讲解及优化见[https://blog.csdn.net/crayondeng/article/details/24853471]
*/

class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    Solution(){}
    ~Solution(){}
    static Solution* s;
    static Solution* getInstance() {
        if(s==NULL) s=new Solution();// write your code here
        return s;
    }
};
Solution* Solution::s = NULL;