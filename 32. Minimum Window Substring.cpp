/**
Given a string source and a string target, find the minimum window in source which will contain all the characters in target.

Example
For source = "ADOBECODEBANC", target = "ABC", the minimum window is "BANC"

Challenge
Can you do it in time complexity O(n) ?
*/
/**
�ҳ���С���ڣ�ʹ�����е�source�ַ���Ƭ�ΰ�������target�ַ��������ظ��ģ��������ⷨ����O(n^3)�����г�����target���ϵ��ַ���Ū������ͨ��map����target���бȽϣ��鿴�Ƿ񱻰�����������ǿ���AC��
Ҳ����������vector��256������¼�����ַ����ִ�����һ����¼target��ģ�һ����¼source��ġ�ʹ����������ָ�룬��ָ���������source�ַ�����ÿ����һ���ַ����ͽ�source��Ķ�Ӧ�ַ�����+1�������ָ�뵱ǰ���ʵ��ַ�������target�����target����ִ���>=��ǰsourceͳ������ֵĴ�������˵����ԣ���Գ���+1������Գ���=target���ȣ���˵����Գɹ�����ʱ��ʼ��������window���ȣ�����ǰsourceͳ�ƽ����source[left]���ֵĴ�������target�г��ִ�������˵����ǰλ���࣬��left���ơ���ָ���ƶ��������ƶ�ʱ�������ڳ���С��֮ǰֵ�����¼��ָ��λ�ü����ڳ��ȡ�����ָ���������Լ���ָ������ȥ������������source.substr(minleft,minlength)��Ϊ��������

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