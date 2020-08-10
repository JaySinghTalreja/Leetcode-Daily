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

void solve() {
    //Change the return type if necessary
    string S, P;
    cin>>S>>P;
    unordered_map<char, long int> cnt;

    for(long int i=0;i<S.size();i++){
        cnt[S[i]]++;
    }

    for(long int i=0; i<P.size();i++) {
        cnt[P[i]]--;
    }

    //long int prevCount=0, fCount=0;
    //long int fLength = P.size();
    string prev = "", equal = "", post = "";
    for(auto &A: cnt) {
        if(A.second <=0) continue;
        if(A.first < P[0]) {
            while(A.second != 0) {
                prev += A.first;
                A.second--;
            }
        }
        else if(A.first == P[0]) {
            while(A.second != 0) {
                equal += A.first;
                A.second--;
            }
        }
        else{
            while(A.second != 0) {
                post += A.first;
                A.second--;
            }
        }
    }

    sort(prev.begin(), prev.end());
    sort(equal.begin(), equal.end());
    sort(all(post));
    string ans = min((prev+equal+P+post), (prev+P+equal+post));
    cout<<ans<<endl;
    /*sort(P.begin(), P.begin()+prevCount);
    sort(P.begin()+prevCount+fLength, P.end());
    */;
    //cout<<P<<endl;
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


//Time Complexity O(m*o) = M is the range (r - l) and o is the length of string having our final produc
//Space Compleixty O(o)