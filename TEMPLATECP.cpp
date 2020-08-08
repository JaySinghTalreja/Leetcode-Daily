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
#define tc(t) unsigned int t; cin >> t; while (t--)
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
    int D, P;
    cin>>D>>P; 
    bool isPrime[D+1];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for(int i=2;i*i<=D;i++) {
        if(isPrime[i] == true) {
            for(int j = i*2;j<=D;j+=i) {
                isPrime[j] = false;
                //cout<<"D";
            }
        }
        //cout<<"M";
    }
    /*for(int i=2;i<=D;i++) {
        cout<<i<<" "<<isPrime[i]<<endl;
    }*/

    int K = D/P;
    int cnt=0;
    for(int i=2;i<=K;i++) {
        if(isPrime[i] == true) {
            int index = i;
            bool flag = true;
            while(index+K <= D) {
                index += K;
                if(!isPrime[index]) {
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                cnt++;
            }
        }
    }
    cout<<cnt;
}

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast;
    tc(t) {
        solve();
    }
    */
    solve();
    return 0;
}