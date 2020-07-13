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
//#define um unordered_map<unsigned long int, unsigned long int>
#define trav(it, a) for(auto it = a.begin(); it != a.end(); it++) cout<<*it<<" ";

void solve() {
   //Change the return type if necessary
    long long N;cin>>N;
    long long minE = INT_MAX;
    long long temp=0;
    unordered_map<long long, long long> AM, BM;
    bool oddFlag = false;
    f0(i,N) {
        cin>>temp;
        AM[temp]++;
        minE = min(minE, temp);
    }
    f0(i,N) {
        cin>>temp;
        BM[temp]++;
        minE = min(minE, temp);
        if(AM[temp] > 0) {
            AM[temp]--;
            BM[temp]--;
        }
    }
    oddFlag = false;
    for(auto it=AM.begin();it!=AM.end();it++) {
        if((it->second + BM[it->first])%2 != 0) {
            oddFlag = true;
            break;
        }
        else {
            BM[it->first] /= 2;
            it->second /= 2;
        }
    }
    vector<long long> firstV, secondV;
    if(oddFlag == false) {
        for(auto it = AM.begin();it!=AM.end();++it) {
            while(it->second > 0) {
                firstV.push_back(it->first);
                it->second--;
            }
        }
        for(auto it = BM.begin();it!=BM.end();++it) {
            while(it->second > 0) {
                secondV.push_back(it->first);
                it->second--;
            }
        }
        if(!firstV.size()){
            cout<<"0"<<endl;
        }
        else {
            long long swaps = 0;
            sort(firstV.begin(), firstV.end());
            sort(secondV.begin(), secondV.end(), greater<>());
            for(long long i=0;i<firstV.size();i++) {
                swaps += min(2*minE, min(firstV[i], secondV[i]));
            }
            cout<<swaps<<endl;
        }
    }
    else{
        cout<<"-1";
        cout<<endl;
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
