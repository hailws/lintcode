/**
Find K-th largest element in an array.

 Notice
You can swap elements in the array

Example
In array [9,3,2,4,8], the 3rd largest element is 4.

In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.

Challenge
O(n) time, O(1) extra memory.
 */
/**
�����·��ķ������Ƕ�ԭ���н���quicksort��ȡ��n-1��Ԫ�أ�ʱ�临�Ӷ�O(nlogn)��
*/
class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int partition(vector<int> &nums, int left, int right){
        int pivot=nums[left];
        int i=left;
        for(int j=left+1; j<=right; j++){
            if (nums[j]>pivot){
                i++;
                swap(nums[j],nums[i]);
            }
        }
        swap(nums[left],nums[i]);
        return i;
    }
    void quicksort(vector<int> &nums, int left, int right){
        if(left<=right){
            int pos=partition(nums,left,right);
            quicksort(nums,left,pos-1);
            quicksort(nums,pos+1,right);
        }
    }
    int kthLargestElement(int n, vector<int> &nums) {
        int left=0,right=nums.size()-1;
        quicksort(nums,left,right);
        return nums[n-1];
    }// write your code here
};
/**
��һ�ַ���������quicksort��partition��pivot�Ƶ���������λ�õ����ʣ����partition�󷵻ص�λ��iΪn-1�����λ�õ����������ս����������ص�λ�����ұߣ���partition���ұ߽��Ϊi-1���ٽ���partition��������ص�λ������ߣ���partition����߽��Ϊi+1���ٽ���partition��ֱ����õ�n��ֵ��
*/
class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int partition(vector<int> &nums, int left, int right){
        int pivot=nums[left];
        int i=left;
        for(int j=left+1; j<=right; j++){
            if (nums[j]>pivot){
                i++;
                swap(nums[j],nums[i]);
            }
        }
        swap(nums[left],nums[i]);
        return i;
    }
    int kthLargestElement(int n, vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == n - 1) return nums[pos];
            if (pos > n - 1) right = pos - 1;
            else left = pos + 1;
        }
        }// write your code here
};
