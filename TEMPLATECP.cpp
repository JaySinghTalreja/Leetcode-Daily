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


int binarySearch(vector<int> &temp, int element) {


    int left = 0, right = temp.size()-1;
    while(left <= right) {
        if(left >= right) {
            return temp[left];
        }

        int mid = left + (right-left)/2;
        if(temp[mid] == element) return element;
        if(temp[mid] < element) left = mid+1;
        else right = mid; 
    }


}

void solve() {
    pair<int, pair<int, int>> finalOutput;
    int maxDiff = INT_MAX;
    vector<int> A{20, 24, 100}, B{2, 19, 22, 79, 800}, C{10, 12, 23, 24, 119};
    for(int i = 0;i<A.size();i++) {
        int bVar = binarySearch(B, A[i]);
        int cVar = binarySearch(C, A[i]);
        int diffCount = max( abs(A[i] - bVar), max( abs(bVar - cVar), abs(cVar - A[i])));
        if(diffCount < maxDiff) {

            maxDiff = diffCount;
            finalOutput = {A[i], {bVar, cVar}};

        }
    }
    cout<<finalOutput.first<<" "<<finalOutput.second.first<<" "<<finalOutput.second.second;
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