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
    int N;
    cin>>N;
    unsigned long int A, B;
    int winA=0, winB=0;
    f0(i,N) {
        cin>>A;
        cin>>B;
        if(A > B){
            sumA++;
        }
        else if(A<B){
            sumB++;
        }
        else{
            sumA++;sumB++;
        }
    }
    if(sumA == sumB){
        cout<<"2 "<<sumA;
    }
    else if(sumA > sumB){
        cout<<"0 "<<sumA;
    }
    else{
        cout<<"1 "<<sumB;
    }
    cout<<endl;
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