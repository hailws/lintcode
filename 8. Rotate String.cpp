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
�ַ�����λ���ַ��������ƶ�iλ��ʵ�����൱�ڽ��ַ����ĺ�iλֱ��ƴ�ӵ��ַ���ǰ�ˣ�����substr()�㶨
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

