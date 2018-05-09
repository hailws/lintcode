/**
 *
You have a total of n yuan. Merchant has three merchandises and their prices are 150 yuan, 250 yuan and 350 yuan. And the number of these merchandises can be considered as infinite. After the purchase of goods need to be the remaining money to the businessman as a tip, finding the minimum tip for the merchant.

Example
Given: n = 900
Return: 0
 */

/**
��ȫ�������⣬״̬ת�Ʒ���
dp[i,j]=max(dp[i-1,j],dp[i,j-price[i]]+price[i])������dp[i,j]Ϊ��jԪǮ������£���ǰi����Ʒ�����õ������Ǯ����Ҫ���С�Ѽ�Ϊn-dp[i,j]��
*/

class Solution {
public:
    /**
     * @param n: the money you have
     * @return: the minimum money you have to give
     */
    int backPackX(int n) {
        int len=3;
        vector<int> price={150,250,350};
        vector<int> dp(n+1);
        for(int i=0;i<len;i++){
            for(int j=price[i];j<=n;j++){
                dp[j]=max(dp[j],dp[j-price[i]]+price[i]);
            }
        }
        return n-dp[n];// write your code here
    }
};