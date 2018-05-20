/**
Given two strings, write a method to decide if one is a permutation of the other.

Example
abcd is a permutation of bcad, but abbe is not a permutation of abe


 */
/**
����ַ����Ƿֻ�Ϊĳһ�����������ֻҪͳ�Ƹ�����ĸ���ֵ���Ŀ���ɡ���Ŀ��ͬ���ǡ�
*/

class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: a boolean
     */
    bool Permutation(string &A, string &B) {
        unordered_map<char,int> mp;
        unordered_map<char,int>::iterator it;
        int l1=A.size(),l2=B.size();
        if(l1!=l2) return false;
        for(int i=0;i<l1;i++){
            it=mp.find(A[i]);
            if(it==mp.end()) mp[A[i]]=1;
            else mp[A[i]]++;
        }
        for(int i=0;i<l2;i++){
            it=mp.find(B[i]);
            if(it==mp.end()) return false;
            else if(mp[B[i]]==1) mp.erase(B[i]);
            else mp[B[i]]--;
        }
        return true;// write your code here
    }
};