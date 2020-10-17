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

void heapify(vector<int> &A, int size, int index) {
    int largest = index;
    int leftChild = 2*index + 1;
    int rightChild = 2*index + 2;

    if(leftChild < size && A[largest] < A[leftChild] ) largest = leftChild;
    if(rightChild < size && A[largest] < A[rightChild] ) largest = rightChild;

    if(largest != index) {
        swap(A[index], A[largest]);
        heapify(A, size, largest);
    }

}

void heapSort(vector<int> &A) {
    int n = A.size();
    //Why n/2-1 ?
    for(int i= n/2-1;i>=0;i--) {
        heapify(A, n, i);
    }

    for(int i=n-1;i>0;i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }

    for(auto C : A) {
        cout<<C<<" ";
    }
    cout<<endl;
}

void solve() {
    //Change the return type if necessary
    vector<int> A{12, 8, 3, 4, 6, 11, 10};
    heapSort(A);
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
