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


/*
bool check(int row, int col, vector<vector<int>> &A) {
    if(row < 0 || row > 8 || col < 0 || col > 8 || A[row][col] == 'O' || A[row][col] == 'V') return false;
    return true;
}
*/

void setOX(int r, int c, vector<vector<char>> &A) {
    if(r-1>=0 && r < 8 && c < 8 && c-1 >=0 && A[r-1][c-1] == 'V') A[r-1][c-1] = 'X';
    if(r+1<8 && r >=0 && c<8 && c>=0 && A[r+1][c] == 'V') A[r+1][c] = 'X';
    if(r-1>=0 && r < 8 && c < 8 && c >=0 && A[r-1][c] == 'V') A[r-1][c] = 'X';
    if(r >=0 && r < 8 && c+1 < 8 && c >=0 && A[r][c+1] == 'V') A[r][c+1] = 'X';
    if(r>=0 && r < 8 && c < 8 && c-1 >=0 && A[r][c-1] == 'V') A[r][c-1] = 'X'; //
    if(r >=0 && r+1 < 8 && c+1< 8 && c >=0 && A[r+1][c+1] == 'V') A[r+1][c+1] = 'X';
    if(r>=0 && r+1 < 8 && c < 8 && c-1 >=0 && A[r+1][c-1] == 'V') A[r+1][c-1] = 'X';
    if(r-1>=0 && r < 8 && c+1 < 8 && c >=0 && A[r-1][c+1] == 'V') A[r-1][c+1] = 'X';
}

void solve() {
   int K;
   cin>>K;
   vector<vector<char>> A(8, vector<char>(8, 'V'));
   if(K<=0){
       for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(i==0 && j ==0) {
                    cout<<"O";
                }
                else{
                    cout<<".";
                }
            }
            cout<<endl;
        }
        return;
   }
   A[0][0] = 'O';
   K--;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++) {
            if(i==0 && j==0){
                continue;
            }
            else if(K>0){
                A[i][j] = '.';
                K--;
            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(A[i][j] == 'O' || A[i][j] == '.') {
                setOX(i, j, A);
            }
            else if(A[i][j] != 'X'){
                A[i][j] = '.';
            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<A[i][j];
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
