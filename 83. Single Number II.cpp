/**
Given 3*n + 1 numbers, every numbers occurs triple times except one, find it.

Example
Given [1,1,2,3,3,3,2,2,4,1] return 4
 */
/**
�ù�ϣ���ʱ�临�Ӷ�ΪO(n)�����ǿռ临�Ӷ�Ҳ��O(n)��

һ�����k*n+1�����������ǣ���¼����������31λÿ��λ��1���ֵĴ����������մ�����kȡ�࣬�ټ���������Ψһ������

��������������������״̬����ĳ�������ֵĴ��������00��Ӧ����3���������Σ�01��Ӧ����3*n+1�Σ�10��Ӧ����3*n+2�Ρ�ת����ϵ00->01->10->00��������֪ʶ����������λ�Ĺ�ϵ������׸����
*/

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A) {
        unordered_map<int,int>mp;
        int len=A.size();
        unordered_map<int,int>::iterator it;
        for(int i=0;i<len;i++){
            it=mp.find(A[i]);
            if(it==mp.end()){
                mp[A[i]]=1;
            }
            else mp[A[i]]++;
        }
        for(it=mp.begin();it!=mp.end();it++){
            if(it->second==1) return it->first;
        }
        // write your code here
    }
};

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A) {
        int one=0,two=0,len=A.size();
        for(int i=0;i<len;i++){
            one=(one^A[i]) & ~two;
            two=(two^A[i]) & ~one;
        }
        return one;// write your code here
    }
};