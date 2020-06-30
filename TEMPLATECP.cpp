#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
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

string convertToBase7(int n) {
    deb(n);deb(n%7);
    string ans ="";
    int flag = false;
    if(n < 0) {
            n = abs(n);
            flag = true;
    }
    while(n>0) {
        ans += to_string(n%7);
        n /= 7;
    }
    if(flag) ans+="-";
    reverse(all(ans));
    return ans;
}

int main()
{
    int v = -4509;
    string c = convertToBase7(v);
    deb(c);
    return 0;
}