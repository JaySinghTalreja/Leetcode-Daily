class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=1;i<prices.size();i++) {
            profit += max(prices[i]-prices[i-1], 0); 
        }
        return profit;
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const size_t n = prices.size();
        int ans = 0;
        for (size_t i=1;i<n;i++)
            ans += max(0,prices[i]-prices[i-1]);
        return ans;
    }
}


//Tutorial - Errichto
https://medium.com/@punitkmr/best-time-to-buy-and-sell-stock-ii-7826845144eb
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/208241/Explanation-for-the-dummy-like-me.