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

//Linear Time


//O(N^2) Solution

void findFactorial(vector<int> &A, int X) {
    int n = A.size();
    int carry = 0;
    for(int i=0;i<n;i++) {
        int indexProd = (A[i] * X) + carry;
        A[i] = indexProd % 10;
        carry = indexProd / 10;
    }
    while(carry) {
        A.push_back(carry%10);
        carry /= 10;
    }
}

void solve() {
    //Factorial of a large Number;
    int X = 10;
    if(X == 1) {
        cout<<1;
        return;
    }
    vector<int> result;
    result.push_back(1);
    for(int i=2;i<=X;i++) {
        findFactorial(result, i);
    }
    int n = result.size()-1;
    for(int i = n;i>=0;i--) {
        cout<<result[i];
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