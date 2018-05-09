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
背包问题。要求的是录取概率。利用P_all=1-Π（1-P[i])来求录取概率。状态转移方程dp[i,j]=max(dp[i-1,j],1-(1-dp[i-1,j-prices[i]])*(1-probability[i]))，其中dp[i,j]为有j的预算下，报考前i所大学所能获得的最高录取概率。因为每所大学只能报考一次，因此为了避免重复，j从大往小进行循环计算。
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