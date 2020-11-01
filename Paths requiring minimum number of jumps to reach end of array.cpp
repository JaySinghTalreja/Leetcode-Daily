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

int minSize = INT_MAX;
vector<vector<int>> finalAns;

int allPaths(vector<int> &A, int index, vector<int> &tempPath, vector<int> &CACHE) {
    int key = index;

    if(CACHE[key] != INT_MIN) {
        cout<<"\nCache Hits";
        return CACHE[key];
    }

    if(index == A.size() - 1) {
        if(tempPath.size() < minSize && finalAns.size()) {
            finalAns.clear();
        }
        minSize = min(minSize, int(tempPath.size()));
        tempPath.push_back(index);
        finalAns.push_back(tempPath);
        tempPath.pop_back();
        return INT_MIN;

    }

    if(index >= A.size()) {
        return INT_MIN;
    }

    int varElement = A[index];

    tempPath.push_back(index);
    for(int i=varElement;i>=1;i--) {
        if(index + i <= A.size() - 1) {
            CACHE[key] = max(CACHE[key], allPaths(A, index+i, tempPath, CACHE) );
        }
    }
    tempPath.pop_back();
}

//9 8 7 6 5 4 3 2 1 0 
void solve() {
    //Write Your Code Here
    vector<int> A {3, 3, 0, 2, 1, 2, 4, 2, 0, 0};
    vector<int> tempPath;
    vector<int> CACHE{INT_MIN, A.size()};
    allPaths(A, 0, tempPath, CACHE);
    cout<<endl;
    for(auto vect : finalAns) {
        for(auto varElements: vect) {
            cout<<varElements<<" ";
        }
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


//Output 
/*

0 3 5 7 9 
0 3 5 6 9 

*/