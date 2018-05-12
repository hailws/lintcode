/**
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.

Example
Given A=[1,2,3,4,5,6] and B=[2,3,4,5], the median is 3.5.

Given A=[1,2,3] and B=[4,5], the median is 3.
 */
/**
�������뵽�ľ��������ѡȡ��λ��������ʱ�临�Ӷ�ΪO(N)�������ܴﵽҪ��Ҫ�����O(lgN)��������ӶȾͺ��������뵽���ַ�������Ҳȷʵ�õ��˶��ַ���

class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    void merge(std::vector<int>& a,int low,int mid,int high){
        int N=high-low+1,left=low,right=mid+1,idx=0;
        std::vector<int> b(N);
        while(left<=mid && right<=high){
            b[idx++]=(a[left]<=a[right]) ? a[left++] : a[right++];
        }
        while(left<=mid){
            b[idx++]=a[left++];
        }
        while(right<=high){
            b[idx++]=a[right++];
        }
        for(int i=low;i<=high;i++){
            a[i]=b[i-low];
        }
    }
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        vector<int> res;
        res.reserve(A.size()+B.size());
        res.insert(res.end(),A.begin(),A.end());
        res.insert(res.end(),B.begin(),B.end());
        int low=0,mid=A.size()-1,high=mid+B.size();
        merge(res,low,mid,high);
        int len=res.size();
        double med;
        if(len%2==0) med=(double(res[int(len/2)])+double(res[int(len/2)-1]))/2;
        else med=res[int(len/2)];
        return med;// write your code here
    }
};

//���ַ�������˼·�ǲ���'#'ʹ�������еĳ��ȱ�Ϊ2N+1���з����������൱����'/'ȡ����'#'������з��䵽�������ϣ����൱�ڽ�һ�����ַ�Ϊ������ԭ����ȵĲ��֣���Ҳ�ͱ����˶���������Ϊ����ż�������ۡ����з�B���е�λ��Ϊj��������λ�������ʿ��Լ���ó��з�A���е�λ��iΪNa+Nb-j��ע���з�ʱ�Ӷ̵����п�ʼ����Ϊ����ǳ����п�ʼ�з֣�����з�λ�ÿ�ǰ�����ȥ���������г��ȵ����������Ҫ�����޶����ȵ��������зֺ�B���������������BlΪB[(j-1)/2]�������Ҷ���ǰ������BrΪB[j/2]��A����ͬ�����Bl<Ar��Al<Br����˵���պû��ֵ���λ��λ�ã�ֻ��Ҫ������������Ҷ���С��ƽ�������ɡ�����Ļ������Bl>Ar��˵����Ҫ��B���з�λ����ǰ�ƣ�Ҳ����high=mid-1�����Al>Br��˵����Ҫ��B���з�λ������ƣ�Ҳ����low=mid+1���߽�����Ҳ���ǵ��з��䵽B����ǰ�����λ�ã���ʱֻҪ��ǰ�������һ����С�ͼ��󼴿ɽ��������Ӣ�Ľ������ [4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation)
*/

class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        int la=A.size(), lb=B.size();
        if(la<lb) return findMedianSortedArrays(B,A);
        int low=0,high=2*lb;
        while(low<=high){
            int mid2=(low+high)/2;
            int mid1=la+lb-mid2;
            double l1,l2,r1,r2;
            l1=(mid1==0) ? INT_MIN: A[(mid1-1)/2];
            l2=(mid2==0) ? INT_MIN: B[(mid2-1)/2];
            r1=(mid1==2*la) ? INT_MAX: A[mid1/2];
            r2=(mid2==2*lb) ? INT_MAX: B[mid2/2];
            if(l1>r2) low=mid2+1;
            else if(l2>r1) high=mid2-1;
            else return (max(l1,l2)+min(r1,r2))/2;
        }// write your code here
    }
};

/**
����һ������Ҳ�Ƕ��ַ�˼�룬������ת��Ϊ���k���������������(ԭ��û���Ǳ߽����⣬����˼·���Բο���
[�����������������λ��](https://blog.csdn.net/woshi750814343/article/details/38948021)
*/