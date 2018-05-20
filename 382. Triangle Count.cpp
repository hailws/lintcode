/**
Given an array of integers, how many three numbers can be found in the array, so that we can build an triangle whose three edges length is the three numbers that we find?

Example
Given array S = [3,4,6,7], return 3. They are:

[3,4,6]
[3,6,7]
[4,6,7]
Given array S = [4,4,4,4], return 4. They are:

[4(1),4(2),4(3)]
[4(1),4(2),4(4)]
[4(1),4(3),4(4)]
[4(2),4(3),4(4)]
 */
/**
统计能够成三角形的情况。
最直接的三重循环会超时，因此考虑两重循环。先将输入数组进行排列。然后两重循环i=0,j=i+1确定两边，之后找到最大的能构成第三边的下标k,结果就是k-j的累加。
*/

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        int len=S.size(),rst=0;
        sort(S.begin(),S.end());
        for(int i=0;i<len-2;i++){
            int k=i+2;
            for(int j=i+1;j<len-1;j++){
                while(S[i]+S[j]>S[k] && k<len) k++;
                rst+=k-j-1;
            }
        }
        return rst;// write your code here
    }
};