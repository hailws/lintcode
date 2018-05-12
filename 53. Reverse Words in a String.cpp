/**
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Clarification
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
 */
/**
倒置单词顺序，并且取出开头和结尾的空格。相当于将每个单词倒序后再将字符串整体倒序。只要注意去除多余的空格即可。
i为遍历指针，j为去除多余空格后字符所该放置的位置，l单词开始位置。注意整体字符串逆序前需要将因空格而多余的位置去掉。
*/

class Solution {
public:

    // function to reverse any part of string from i to j (just one word or entire string)
    void reverseword(string &s, int i, int j){
        while(i<j){
            char t=s[i];
            s[i++]=s[j];
            s[j--]=t;
        }
    }

    string reverseWords(string &s) {

        int i=0, j=0;
        int l=0;
        int len=s.length();
        int wordcount=0;

        while(true){
            while(i<len && s[i] == ' ') i++;  // skip spaces in front of the word
            if(i==len) break;
            if(wordcount) s[j++]=' ';
            l=j;
            while(i<len && s[i] != ' ') {s[j]=s[i]; j++; i++;}
            reverseword(s,l,j-1);                // reverse word in place
            wordcount++;

        }

        s.resize(j);                           // resize result string
        reverseword(s,0,j-1);
        return s;// reverse whole string
    }
};

