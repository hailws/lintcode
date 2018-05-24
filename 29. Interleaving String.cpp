/**
Given three strings: s1, s2, s3, determine whether s3 is formed by the interleaving of s1 and s2.

Have you met this question in a real interview?
Example
        For s1 = "aabcc", s2 = "dbbca"

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
Challenge
O(n2) time or better
*/
/**
����1����̬�滮
dp[i][j]��ʾs1ǰi����s2ǰj����s3ǰi+j���Ƿ�interleaving string��
���ȳ�ʼ��������s1����ʼ�����е�dp[i][0]
�ٱ���s2����ʼ�����е�dp[0][j]
��s3�ĵ�i��j��1λ��s1�ĵ�iλ��ȣ���dp[i-1][j]�Ƿ�Ϊtrue��ͬ����s3��i+j-1λ��s2�ĵ�jλ��ȣ���dp[i][j-1]�Ƿ�Ϊtrue��ֻҪ��������е�����һ��Ϊtrue����dp[i][j]Ϊtrue��
����2��ת�������Թ���dfs/bfs��
�� s1 = "aab"  s2 = "abc" s3 = "aaabcb". ���������Թ�������ܹ��ӣ�0��0���ߵ���i��j������˵����interleaving�����������dfs��
*/

o--a--o--b--o--c--o
|     |     |     |
a     a     a     a
|     |     |     |
o--a--o--b--o--c--o
|     |     |     |
a     a     a     a
|     |     |     |
o--a--o--b--o--c--o
|     |     |     |
b     b     b     b
|     |     |     |
o--a--o--b--o--c--o

class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    bool isInterleave(string &s1, string &s2, string &s3) {
        int l1=s1.size(),l2=s2.size(),l3=s3.size();
        if(l1+l2!=l3) return false;
        vector<vector<bool>> dp(l1+1,vector<bool>(l2+1,false));
        dp[0][0]=true;
        for(int i=1;i<=l1;i++){
            dp[i][0]=dp[i-1][0] && (s1[i-1]==s3[i-1]);
        }
        for(int i=1;i<=l2;i++){
            dp[0][i]=dp[0][i-1] && (s2[i-1]==s3[i-1]);
        }
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                dp[i][j]=(dp[i-1][j] && (s1[i-1]==s3[i+j-1])) || (dp[i][j-1] && (s2[j-1]==s3[i+j-1]));
            }
        }
        return dp[l1][l2];// write your code here
    }
};

class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: A string
     * @param s3: A string
     * @return: Determine whether s3 is formed by interleaving of s1 and s2
     */
    void dfs(int x,int y,string& s1, string& s2, string &s3,int& l1,int& l2, int& l3,bool& rst){
        if(x==l1 && y==l2) {
            rst=true;
            return;
        }
        if(s1[x]==s3[x+y]) dfs(x+1,y,s1,s2,s3,l1,l2,l3,rst);
        if(s2[y]==s3[x+y]) dfs(x,y+1,s1,s2,s3,l1,l2,l3,rst);
    }
    bool isInterleave(string &s1, string &s2, string &s3) {
        bool rst=false;
        int l1=s1.size(),
                l2=s2.size(),
                l3=s3.size();
        if(l1+l2!=l3) return false;
        dfs(0,0,s1,s2,s3,l1,l2,l3,rst);
        return rst;// write your code here
    }
};