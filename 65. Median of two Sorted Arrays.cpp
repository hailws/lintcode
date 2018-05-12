/**
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.

Example
Given A=[1,2,3,4,5,6] and B=[2,3,4,5], the median is 3.5.

Given A=[1,2,3] and B=[4,5], the median is 3.
 */
/**
最容易想到的就是排序后选取中位数，但是时间复杂度为O(N)，并不能达到要求。要求的是O(lgN)，这个复杂度就很容易联想到二分法，最终也确实用到了二分法。

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

//二分法，大致思路是插入'#'使两个序列的长度变为2N+1，切分两个序列相当于用'/'取代了'#'，如果切分落到了数字上，则相当于将一个数字分为两个和原数相等的部分，这也就避免了对数组数量为奇数偶数的讨论。计切分B数列的位置为j，则由中位数的性质可以计算得出切分A数列的位置i为Na+Nb-j。注意切分时从短的数列开始，因为如果是长数列开始切分，如果切分位置靠前，会出去超出短数列长度的情况，还需要额外限定长度的条件。切分后B数列左端最后的数字Bl为B[(j-1)/2]，数列右端最前的数字Br为B[j/2]，A数列同理。如果Bl<Ar且Al<Br，则说明刚好划分到中位数位置，只需要计算左端最大和右端最小的平均数即可。否则的话，如果Bl>Ar，说明需要将B的切分位置向前移，也就是high=mid-1。如果Al>Br，说明需要将B的切分位置向后移，也就是low=mid+1。边界问题也就是当切分落到B的最前和最后位置，这时只要在前后各插入一个极小和极大即可解决。具体英文解释详见 [4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation)
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
还有一种做法也是二分法思想，将问题转化为求第k大的数。具体做法(原文没考虑边界问题，不过思路可以参考）
[找两个排序数组的中位数](https://blog.csdn.net/woshi750814343/article/details/38948021)
*/