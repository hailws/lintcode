/**
Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using one call to isSubstring.

Example
waterbottle is a rotation of erbottlewat.
apple is not a rotation of ppale.
 */
/**
检查一个字符串是否为另一个的轮转。字符串轮转就是把前半段移动到后半段，利用substr实现。
*/

class Solution {
public:
    /**
     * @param s1: the first string
     * @param s2: the socond string
     * @return: true if s2 is a rotation of s1 or false
     */
    bool isRotation(string &s1, string &s2) {
        int l1=s1.size(),l2=s2.size();
        if(l1!=l2) return false;
        for(int i=0;i<l1;i++){
            if(s1.substr(i,l1-i)+s1.substr(0,i)==s2) return true;
        }
        return false;// write your code here
    }
};