/**
Given a string source and a string target, find the minimum window in source which will contain all the characters in target.

Example
For source = "ADOBECODEBANC", target = "ABC", the minimum window is "BANC"

Challenge
Can you do it in time complexity O(n) ?
*/
/**
找出最小窗口，使窗口中的source字符串片段包括所有target字符（包括重复的）；暴力解法就是O(n^3)把所有长度在target以上的字符串弄出来，通过map来和target进行比较，查看是否被包括。惊奇的是可以AC。
也可以用两个vector（256）来记录所有字符出现次数，一个记录target里的，一个记录source里的。使用左右两个指针，右指针遍历整个source字符串，每访问一个字符，就将source里的对应字符个数+1。如果右指针当前访问的字符出现在target里，并且target里出现次数>=当前source统计里出现的次数，则说明配对，配对长度+1。若配对长度=target长度，则说明配对成功，此时开始尝试缩减window长度，若当前source统计结果中source[left]出现的次数大于target中出现次数，则说明当前位冗余，将left右移。左指针移动至不可移动时，若窗口长度小于之前值，则记录左指针位置及窗口长度。待右指针遍历完毕以及左指针右移去除冗余后，输出的source.substr(minleft,minlength)即为所需结果。

class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        unordered_map<char,int> mp;
        int len=target.size();
        for(auto i:target){
            if(mp.find(i)==mp.end()) mp[i]=0;
            mp[i]++;
        }
        for(int i=len;i<=source.size();i++){
            for(int j=i;j<=source.size();j++){
                bool rst=true;
                unordered_map<char,int> tmp;
                for(int k=j-i;k<j;k++){
                    if(tmp.find(source[k])==tmp.end()) tmp[source[k]]=0;
                    tmp[source[k]]++;
                }
                for(auto t:mp){
                    if(tmp.find(t.first)==tmp.end()){
                        rst=false;
                        break;
                    }
                    if(tmp[t.first]<mp[t.first]){
                        rst=false;
                        break;
                    }
                }
                if(rst){
                    return source.substr(j-i,i);
                }
            }
        }
        return "";// write your code here
    }
};

class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        vector<int> tag(256,0);
        vector<int> sour(256,0);
        int count=0,minwin=INT_MAX,minstart;
        bool goal=false;
        for(int i=0;i<target.size();i++){
            tag[target[i]]++;
        }
        int left=0,
            right=0,
            len=0;
        for(;right<source.size();right++){
            sour[source[right]]++;
            if(tag[source[right]]>0 && sour[source[right]]<=tag[source[right]]){
                count++;
            }
            if(count==target.size()){
                while(sour[source[left]]>tag[source[left]]){
                    sour[source[left]]--;
                    left++;
                }
                goal=true;
                if(right-left+1<minwin){
                    minwin=right-left+1;
                    minstart=left;
                }
            }
        }
        if(!goal) return "";
        else return source.substr(minstart,minwin);// write your code here
    }
};