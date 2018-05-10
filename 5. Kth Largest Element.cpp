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
最乃衣服的方法就是对原数列进行quicksort后取第n-1个元素，时间复杂度O(nlogn)。
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
另一种方法是利用quicksort里partition将pivot移到其排序后的位置的性质，如果partition后返回的位置i为n-1，则该位置的数就是最终结果。如果返回的位置在右边，则将partition的右边界改为i-1，再进行partition。如果返回的位置在左边，则将partition的左边界改为i+1，再进行partition。直到获得第n个值。
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
