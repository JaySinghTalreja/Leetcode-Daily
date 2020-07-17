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

void solve() {
    //Change the return type if necessary
    string source, target;
    cin>>source>>target;
    //cout<<"Source:"<<source<<endl;
    //cout<<"Target:"<<target<<endl;
    int s = source.length();
    int t = target.length();
    int totalCount=0;

    for(int i=0;i<t;) {
        bool isPresent = false;
        for(int j=0;j<s;j++) {
            if(i < t && source[j] == target[i]) {
                isPresent=true;
                i++;
            }
        }
        if(!isPresent) {
            cout<<"-1";
            return;
        }
        totalCount++;
    }

    cout<<totalCount<<endl;
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
