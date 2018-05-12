/**
Given a string and an offset, rotate string by offset. (rotate from left to right)

Example
Given "abcdefg".

offset=0 => "abcdefg"
offset=1 => "gabcdef"
offset=2 => "fgabcde"
offset=3 => "efgabcd"
 */
/**
字符串移位，字符串向右移动i位，实际上相当于将字符串的后i位直接拼接到字符串前端，利用substr()搞定
*/

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        if (str.size() == 0)
            return;

        offset = offset % str.size();
        str = str.substr(str.size() - offset, offset) +
              str.substr(0, str.size() - offset);
    }
};

