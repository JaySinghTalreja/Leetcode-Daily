#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define mod (int) 998244353
#define MOD (int) 1e9+7
//#define ll long long
#define all(a) a.begin(),a.end()
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (long long i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define rloop(i,a,b) for (int i = a ; i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define maxpq priority_queue<long long int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define memos(x) memset(x, 0, sizeof(x))
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define sortall(x) sort(all(x))
#define umll unordered_map<ll, ll>exit
#define trav(it, a) for(auto it = a.begin(); it != a.end(); it++) cout<<*it<<" ";



void printReverse(vector<vector<int>> &MAT, int m, int n, int rows, int cols, stack<int> &varStack) {
    if(m > rows || n > rows) return;

    //Printing Row from left to right
    for(int i = m;i<=cols;i++) {
        varStack.push(MAT[m][i]);
    }
    //Printing Column for top to bottom
    for(int i=m+1;i<=rows;i++) {
        varStack.push(MAT[i][cols]);
    }


    //Printing Row from Right to left
    if(m < rows) {
        for(int i = cols-1;i>=n;i--) {
            varStack.push(MAT[rows][i]);
        }
    }

    if(n < cols) {
        for(int i = rows-1;i>m;i--) {
            varStack.push(MAT[i][n]);
        }
    }

    printReverse(MAT, m+1, n+1, rows-1, cols-1, varStack);

}



//Input
/*

{1, 2, 3, 4, 5, 6}, 
{7, 8, 9, 10, 11, 12}, 
{13, 14, 15, 16, 17, 18}

*/
void solve() {
    //Write Your Code Here
    vector<vector<int>> Mat{
                            {1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}
                        };
                            //Rows = 4, Cols = 4
    stack<int> reverseStack;
    printReverse(Mat, 0, 0, Mat.size()-1, Mat[0].size()-1, reverseStack);
    while(!reverseStack.empty()) {
        int var = reverseStack.top();
        reverseStack.pop();
        cout<<var<<" ";
    }
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast;
    tc(t) {
        solve();
    }
    return 0;
}