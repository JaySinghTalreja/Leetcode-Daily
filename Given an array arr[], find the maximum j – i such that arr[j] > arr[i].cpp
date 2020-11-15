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


//Funct Declarationss

void solve() {

    vector<int> A{6, 5, 4, 3, 2, 1};
    vector<int> rightMax(A.size());
    vector<int> leftMin(A.size());
    rightMax[rightMax.size()-1] = A[A.size()-1];
    for(int i = A.size()-2;i>=0;i--) {
        rightMax[i] = max(A[i], rightMax[i+1]);
    }
    int count = INT_MIN;
    int j = 0;
    for(int i=0;i<A.size() && j < rightMax.size();i++) {
        while(j < rightMax.size() && A[i] < rightMax[j]) {
            j++;
        }
        count = max(count, j-i-1);
    }
    count == 0 ? cout<<-1 : cout<<count;
    return;
    
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