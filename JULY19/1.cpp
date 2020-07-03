#include <bits/stdc++.h>
using namespace std;
#define mod (int) 998244353
#define MOD (int) 1e9+7
#define ll long long
#define all(a) a.begin(),a.end()
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
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
#define trav(it, a) for(auto it = a.begin(); it != a.end(); it++)

void solve() {
    //Change the Return type if necessary
    unsigned long int N;
    cin>>N;
    vector<long int> S(N, 0);
    unsigned long int X=0;
    f0(i,N){
        cin>>X;
        S[i] = X;
    }
    if(N == 1){
        cout<<0<<endl;
        return;
    }
    int sum = 0;
    for(unsigned long int i=1;i<S.size();i++) {
        if(S[i] == S[i-1]) {
            continue;
        }
        int diff = abs(S[i] - S[i-1]);
        sum += (diff == 1) ? 0 : diff-1;
    }
    cout<<sum<<endl;
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