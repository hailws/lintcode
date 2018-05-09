/**
 *
You have a total of 10 * n thousand yuan, hoping to apply for a university abroad. The application is required to pay a certain fee. Give the cost of each university application and the probability of getting the University's offer, and the number of university is m. If the economy allows, you can apply for multiple universities. Find the highest probability of receiving at least one offer.

 Notice
0<=n<=10000,0<=m<=10000

Example
Given:
n = 10
prices = [4,4,5]
probability = [0.1,0.2,0.3]

Return:0.440
 */

/**
�������⡣Ҫ�����¼ȡ���ʡ�����P_all=1-����1-P[i])����¼ȡ���ʡ�״̬ת�Ʒ���dp[i,j]=max(dp[i-1,j],1-(1-dp[i-1,j-prices[i]])*(1-probability[i]))������dp[i,j]Ϊ��j��Ԥ���£�����ǰi����ѧ���ܻ�õ����¼ȡ���ʡ���Ϊÿ����ѧֻ�ܱ���һ�Σ����Ϊ�˱����ظ���j�Ӵ���С����ѭ�����㡣
*/

class Solution {
public:
    /**
     * @param n: Your money
     * @param prices: Cost of each university application
     * @param probability: Probability of getting the University's offer
     * @return: the  highest probability
     */
    double backpackIX(int n, vector<int> &prices, vector<double> &probability) {
        int len=prices.size();
        vector<double> dp(n+1,0.0);
        for(int i=0;i<len;i++){
            for(int j=n;j>=prices[i];j--){
                double mlt=1-dp[j-prices[i]];
                mlt*=(1-probability[i]);
                dp[j]=max(dp[j],1-mlt);
            }
        }
        return dp[n];// write your code here
    }
};