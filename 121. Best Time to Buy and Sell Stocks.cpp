//Kadane's Algorithm
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int maxCurrent = 0;
        int maxGlobal = 0;
        for(int i=1;i<n;i++){
            maxCurrent = max(0, (maxCurrent+prices[i]-prices[i-1]));
            maxGlobal = max(maxCurrent, maxGlobal);
        }
        return maxGlobal;
    }
};
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        //vector<int> dp[n+1][n+1] = {0};
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[i].size();j++) {
                if(j<i){
                    dp[i][j] = 0;
                }
                else if(i==j){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                else{
                    dp[i][j] = max(prices[j-1]-prices[i-1], max(dp[i-1][j], dp[i][j-1]));
                }
            }
        }
        return dp[n][n];
    }
};
*/


//MUST SEE
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/39038/Kadane's-Algorithm-Since-no-one-has-mentioned-about-this-so-far-%3A)-(In-case-if-interviewer-twists-the-input)