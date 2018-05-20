/**
For a given source string and a target string, you should output the first index(from 0) of target string in source string.

If target does not exist in source, just return -1.

Clarification
Do I need to implement KMP Algorithm in a real interview?

Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure you confirm with the interviewer first.
Example
If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.
 */
/**
暴力方法复杂度O(MN),需要注意指针为空以及字符串为空的边界情况。
利用KMP算法的复杂度为O(M+N)；
算法说明参考[http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/]
代码说明参考[https://www.cnblogs.com/c-cloud/p/3224788.html]
*/

class Solution {
public:
    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    int strStr(const char *source, const char *target) {
        int i=0;
        if(!source || !target) return -1;
        if(target[i]=='\0') return 0;
        while(source[i]!='\0'){
            int j=0;
            while(target[j]!='\0' && source[i+j]!='\0' &&source[i+j]==target[j]){
                j++;
            }
            if(target[j]=='\0') return i;
            i++;
        }
        return -1;// write your code here
    }
};

class Solution {
public:
    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    int strStr(const char *source, const char *target) {
        if(!source || !target) return -1;
        if(strlen(target)==0) return 0;
        int k=0;
        vector<int> next(strlen(target));
        for(int i=1;i<strlen(target);i++){
            while(k>0 && target[i]!=target[k]){
                k=next[k-1];
            }
            if(target[i]==target[k]) k++;
            next[i]=k;
        }
        int p=0;
        for(int i=0;i<strlen(source);i++){
            while(p>0 && target[p]!=source[i]){
                p=next[p-1];
            }
            if(target[p]==source[i]) p++;
            if(p==strlen(target)) return i-strlen(target)+1;
        }
        return -1;// write your code here
    }
};