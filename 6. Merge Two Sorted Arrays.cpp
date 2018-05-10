/**
Merge two given sorted integer array A and B into a new sorted integer array.

Have you met this question in a real interview?
Example
A=[1,2,3,4]

B=[2,4,5,6]

return [1,2,2,3,4,4,5,6]
 */
/**
�������뵽�ľ��Ǵ�ͷ��ʼ���������������Ȼ��С�������������飬�ٰѻ���ʣ��Ĳ���������ϡ�
*/

class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        int i=0,j=0,k;
        vector<int> C;
        while(i<A.size() && j<B.size()){
            if(A[i]>B[j]){
                C.push_back(B[j]);
                j++;
            }
            else
            {C.push_back(A[i]);
                i++;
            }
        }
        for (k=i;k<A.size();k++){
            C.push_back(A[k]);
        }
        for (k=j;k<B.size();k++){
            C.push_back(B[k]);
        }
        return C;
    }
};

