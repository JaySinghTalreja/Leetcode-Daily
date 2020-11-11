#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Find maximum profit earned from at most k stock transactions
// Input to the function are stock prices of n days and positive number k
int maxProfit(vector<int>& price, int k)
{
	// get number of days n
	int n = price.size();

	// profit[i][j] stores the maximum profit gained by doing
	// at most i transactions till j'th day
	int profit[k+1][n];

	// fill profit[][] matrix in bottom-up fashion
	for (int i = 0; i <= k; i++)
	{
		// initialize prev diff to minus infinity
		int prev_diff = INT_MIN;

		for (int j = 0; j < n; j++)
		{
			// profit is 0 when:
			// i = 0 i.e. for 0'th day
			// j = 0 i.e. no transaction is being performed

			if (i == 0 || j == 0) {
				profit[i][j] = 0;
			}
			else
			{
				prev_diff = max(prev_diff, profit[i - 1][j - 1] - price[j - 1]);
				profit[i][j] = max(profit[i][j - 1], price[j] + prev_diff);
			}
		}
	}

    cout<<endl;
    for(int i=0;i<=k;i++) {
        for(int j=0;j<n;j++) {
            cout<<profit[i][j]<<" ";
        }
        cout<<endl;
    }
	return profit[k][n - 1];
    
}

int main()
{
	vector<int> price { 1, 5, 2, 3, 7, 6, 4, 5 };
	int k = 3;

	cout << "The maximum possible profit is: " << maxProfit(price, k);

	return 0;
}