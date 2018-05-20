/**
Given a string, find all permutations of it without duplicates.

Example
Given "abb", return ["abb", "bab", "bba"].

Given "aabb", return ["aabb", "abab", "baba", "bbaa", "abba", "baab"].
 */
/**
这里利用了next_permutation进行操作。也可以利用16 permutation2 里的方法照做，只是数字被替换成了字母。
*/

class Solution {
public:
    /**
     * @param str: A string
     * @return: all permutations
     */
    // Function to find lexicographically next permutations of a
    // string. It returns true if the string could be rearranged as
    // a lexicographically greater permutation else it returns false
    bool next_permutation(string &str, int n)
    {
        if(n<=1) return false;
        // Find largest index i such that str[i - 1] is less than str[i]
        int i = n - 1;
        while (str[i - 1] >= str[i])
        {
            // if i is first index of the string, that means we are already at
            // highest possible permutation i.e. string is sorted in desc order
            if (--i == 0)
                return false;
        }

        // if we reach here, substring str[i..n) is sorted in descending order
        // i.e. str[i-1] < str[i] >= str[i+1] >= str[i+2] >= ... >= str[n-1]

        // Find highest index j to the right of index i such that
        // str[j] > str[i-1]
        int j = n - 1;
        while (j > i && str[j] <= str[i - 1])
            j--;

        // Swap characters at index i-1 with index j
        swap(str[i - 1], str[j]);

        // Reverse the substring str[i..n) and return true
        reverse (str.begin() + i, str.end());

        return true;
    }

    vector<string> stringPermutation2(string &str) {
        sort(str.begin(),str.end());
        vector<string> rst;
        while(1){
            rst.push_back(str);
            if(!next_permutation(str,str.size())) break;
        }
        return rst;// write your code here
    }
};