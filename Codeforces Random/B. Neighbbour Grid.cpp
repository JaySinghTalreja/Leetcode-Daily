#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define mod (int) 998244353
#define MOD (int) 1e9+7
//#define ll long long
#define all(a) a.begin(),a.end()
#define f0(i, n) for (long long i = 0; i < n; i++)
#define f1(i, n) for (long long i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define rloop(i,a,b) for (int i = a ; i>=b;i--)
#define tc(t) int t; cin >> t; while (t--)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define memos(x) memset(x, 0, sizeof(x))
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define sortall(x) sort(all(x))
#define umll unordered_map<ll, ll>
#define trav(it, a) for(auto it = a.begin(); it != a.end(); it++) cout<<*it<<" ";

bool check(int row, int col, int i , int j) {
    return(i>=0 && i<row && j<col && j >=0);
}

int X[] = {0, -1, 0, 1};
int Y[] = {-1, 0, 1, 0};

void solve() {
    //Change the return type if necessary
    int n, m;
    cin>>n>>m;
    vector<vector<int>> P(n, vector<int>(m, 0));
    string ans[] = {"NO\n", "YES\n"};
    int temp;
    int init = 1;
    int rows = P.size();
    int cols = P[0].size();
    for(int i=0;i<P.size();i++, ans[1]+="\n")
    for(int j=0;j<P[i].size();j++) {
        cin>>temp;
        int check = (i>0) + (i<rows-1) + (j>0) + (j<cols-1);
        if(check>=temp)
            ans[1] +=  to_string(check) + " ";
        else
            init = 0;
    }
    cout<<ans[init];
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
