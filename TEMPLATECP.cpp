#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define mod (int) 998244353
#define MOD (int) 1e9+7
#define ll long long
#define all(a) a.begin(),a.end()
#define f0(i, n) for (unsigned int i = 0; i < n; i++)
#define f1(i, n) for (unsigned int i = 1; i <= n; i++)
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
#define trav(it, a) for(auto it = a.begin(); it != a.end(); it++) cout<<*it<<" ";

int getIndex(vector<unsigned int> &AV, unsigned int element) {
    return lower_bound(AV.begin(), AV.end(), element)-AV.begin();
}

int doCalc(vector<unsigned int> &AV, unsigned int X, int index) {
    int right = (AV[index] > X) ? (X*2) : (AV[index]*2);
    int left = (AV[index+1] > X) ? (X*2) : (AV[index+1]*2);
    return (right >= left ? index : (index + 1));
}
void solve() {
   //Change the return type if necessary
    unsigned int N, X;
    cin>>N>>X;
    vector<unsigned int> AV(N, 0);
    //cout<<"LOOPING"<<endl;
    f0(i,N) {
        cin>>AV[i];
    }
    sort(all(AV));
    int dc=0;
    //cout<<"LOOPING"<<endl;
    int index = getIndex(AV, X);
    /*
    while(N) {
        index = index >= int(AV.size()) ? AV.size()-1 : index;
        //cout<<"index:"<<index<<" "<<"X:"<<X<<endl;
        //sleep(1);
        if(X == AV[index]) {
            AV[index] = 0,dc++,X *= 2,N--;
            AV.erase(AV.begin()+index);
            index = getIndex(AV, X);
        }
        else if(index == 0 && X < AV[index]) {
            X *= 2;
            dc++;
            //trav(it, AV);
        }
        else if(AV[index] > X && AV[index] - X < AV[index-1] &&index != 0) {
            index = (index == 0) ? index : --index;
            int temp = AV[index] - X;
            AV[index] = (temp <= 0) ? 0 : (temp)*2;
            X = (X<=temp+X) ? X*2 : (temp+X) * 2;
            dc++;
            if(AV[index] == 0) AV.erase(AV.begin()+index), N--;
            //cout<<"DD:";
            //trav(it, AV);
            index = getIndex(AV, X);
        }
        else{
            int temp = AV[index] - X;
            AV[index] = (temp <= 0) ? 0 : (temp)*2;
            X = (X<=temp+X) ? X*2 : (temp+X) * 2;
            //cout<<"TRAV:";
            //trav(it, AV);
            //cout<<endl;
            dc++;
            if(AV[index] == 0) AV.erase(AV.begin()+index), N--;
            index = getIndex(AV, X);
        }
        */
    while(N) {
        //cout<<"index:"<<index<<" "<<"X:"<<X<<endl;
        //sleep(1);
        if(X >= AV[index]/2) {
            int temp = AV[index] - X;
            AV[index] = (temp <= 0) ? 0 : temp*2;
            X = (temp <=0) ? () : (temp+X)
        }
    }
    cout<<dc<<endl; 
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
