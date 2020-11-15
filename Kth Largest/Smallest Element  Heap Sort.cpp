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


//TIME COMPLEXITY
//->BEST  ==
//->WORST ==
//->AVERGAE ==

//SPACE COMPLEXITY
//-> 


void heapify(vector<int> &A, int heapSize, int index) {
    
    int leftChild = 2*index + 1;
    int rightChild = 2*index +2;
    int smallest = index;
    if(leftChild < heapSize && A[leftChild] < A[smallest] ) {
        smallest = leftChild;
    }
    if(rightChild < heapSize && A[rightChild] < A[smallest]) {
        smallest = rightChild;
    }
    if(smallest != index) {
        swap(A[smallest], A[index]);
        heapify(A, heapSize, smallest);
    }

}


int KthHeapSort(vector<int> &A, int K) {
    
    for(int i=A.size()/2-1;i>=0;i--) {
        heapify(A, A.size(), i);
    }
    for(int i = A.size()-1; i > 0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
        if(i == A.size() - K) break;
    }
    for(auto C: A) {
        cout<<C<<" ";
    }
    cout<<"\nELEMENT:";
    return A[A.size()-K];

}

void solve() {

    vector<int> A{7, 10, 4, 3, 20, 15};
    int K = 6;
    //Smallest Element
    cout<<KthHeapSort(A, K);

}

int main()
{
    solve();
    return 0;
}