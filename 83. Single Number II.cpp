/**
Given 3*n + 1 numbers, every numbers occurs triple times except one, find it.

Example
Given [1,1,2,3,3,3,2,2,4,1] return 4
 */
/**
用哈希表的时间复杂度为O(n)，但是空间复杂度也是O(n)。

一种针对k*n+1的问题做法是，记录二进制数字31位每个位上1出现的次数，将最终次数对k取余，再加起来就是唯一的数。

本题特殊做法是用三种状态表现某个数出现的次数情况，00对应出现3的整数倍次，01对应出现3*n+1次，10对应出现3*n+2次。转换关系00->01->10->00。用数电知识导出两个数位的关系，不加赘述。
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