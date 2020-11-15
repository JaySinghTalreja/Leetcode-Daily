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


//Funct Declarations


//Time O(N) - Best , If(Pivot is chosen wisely);
//Worst O(N^2)

int partition(vector<int> &A, int left, int right) {
    srand(time(NULL));
    int pivotIndex = left + rand() % (right-left);
    int start = left, end = left;
    swap(A[pivotIndex], A[right]);
    while(end<right) {

        if(A[end] <= A[right]) {
            swap(A[start], A[end]);
            start++;
        }
        end++;

    }
    swap(A[start], A[right]);
    return start;

}

int quickSelect(vector<int> &A, int K, int left, int right) {

    if(left == right) {
        return A[left];
    }
    else if(left>right) return INT_MAX;

    int pivot = partition(A, left, right);
    if(pivot == K - 1)
        return A[pivot];
    else if(pivot > K - 1) return quickSelect(A, K, left, pivot - 1);
    else return quickSelect(A, K, pivot+1, right);
    
}


void solve() {

    vector<int> A{7, 10, 4, 3, 20, 15};
    int K = 5;
    //Smallest Element
    cout<<quickSelect(A, K, 0, A.size()-1);
    cout<<endl;
    for(auto C: A) {
        cout<<C<<" ";
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