/*
Author: Ayush Agrawal, IIT Ropar
*/
#include <iostream>
//#include <bits/stdc++.h>
#include <cstdio>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <iomanip>
#include <limits.h>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>
#include <chrono>
#include <random>
#include <map>
#include <unordered_map>
#include <utility>
#define endl "\n"
#define deb(x) cout << ">>" << #x << " = " << x << endl;
#define deb2(x,y) cout << ">>" << #x << " = " << x << " , "<< #y << " = " << y << endl;
#define debhell cout<<"HELLO"<<endl;
#define all(x) (x).begin(), (x).end() 
#define sortall(x) sort(all(x))
#define ull unsigned long long int
#define ll long long int 
#define ld long double
#define random mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue <ll> 
#define ppq priority_queue <pll>
#define vi vector <int>
#define vb vector <bool>
#define vl vector <ll>
#define vpl vector <pll>
#define vc vector <char>
#define mmi multimap<int,int>
#define mml multimap<ll,ll>
#define mmc multimap<char,char>
#define mi map<int,int>
#define ml map<ll,ll>
#define mc map<char,char>
#define clr(a) memset(a,-1,sizeof(a))
#define fill_zero(a) memset(a,0,sizeof(a))
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define INF 1e+18
#define MAXN 1000000
using namespace std;
bool primecheck(ll a)
{
    bool check  = true;
 
    if(a==1)
        return(false);
 
    for(ll i=2;i<=sqrt(a);i++)
    {
        if(a%i==0){
            check = false;
            break;
        }
    }
 
    return(check);
}
vl primeFactors(ll n)  
{  
    // Print the number of 2s that divide n  
    vl sol;
    bool once = false;
    while (n % 2 == 0)  
    {  
        // cout << 2 << " ";  
        if(!once)
        {
            sol.pb(2);
            once = true;
        }
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        bool once = false;
        while (n % i == 0)  
        {  
            // cout << i << " ";
            if(!once)
            {
                sol.pb(i);
                once = true;
            }  
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        {
            sol.pb(n);
        } 
    return(sol);    
}  
vl printDivisors(ll n) 
{ 
    // Note that this loop runs till square root 
    vl sol;
    vl another;
    for (ll i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i){ 
                //printf("%d ", i);
               sol.pb(i); 
                 }
  
            else {
                sol.pb(i);
                another.pb(n/i);
            }// Otherwise print both 
                //printf("%d %d ", i, n/i); 
        } 
 
    } 
    for(ll i=another.size()-1;i>=0;i--)
    {
        sol.pb(another[i]);
    }
        
    return(sol);
}  
ll digits(ll a)
{
    return(floor(log10(a))+1);
}
ll bits(ll n) 
{ 
    return __builtin_popcount(n); 
}
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll modInverse(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        ll q = a / m; 
        ll t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x  
    if (x < 0) 
       x += m0; 
  
    return x; 
} 
// ll nCr(ll n,ll r)
// {
//     // fact needs to be pre-calculated
//     ll val1 = fact[n];
//     ll val2 = fact[n-r]*fact[r];
//     val2 = modInverse(val2,mod);
//     val1%=mod;
//     val2%=mod;
//     //cout<<val1<<" "<<val2<<endl;
//     return(val1*val2);
// }
int gcd(int a, int b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    // base case 
    if (a == b) 
        return a; 
   
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
}
ll lcm(ll a, ll b)  
 {  
    return (a*b)/gcd(a, b);  
 }
 void addEdge(vl adj[],ll u, ll v)
 {
    adj[u].pb(v);
    adj[v].pb(u);
 }
 vl path;
 void dfs(ll u, vl adj[], vb &visited, ll parent = -1)
 {
    visited[u] = true;
    path[u] = parent;
    // count<<u<<endl;
    for(ll i=0;i<adj[u].size();i++)
    {
        if(visited[adj[u][i]]==false)
        {
            dfs(adj[u][i],adj,visited,u);
        }
    }
 }
 // First element Ascending order and second element in descending order
 struct Comp {
  bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    if (a.first != b.first) {
      return a.first < b.first;
    }
    return a.second > b.second;
  }
 
};
// ll spf[MAXN];
// void sieve() 
// { 
//     spf[1] = 1; 
//     for (int i=2; i<MAXN; i++)  
//             spf[i] = i; 
 
//     for (int i=4; i<MAXN; i+=2) 
//         spf[i] = 2; 
  
//     for (int i=3; i*i<MAXN; i++) 
//     { 
//         if (spf[i] == i) 
//         { 
//             for (int j=i*i; j<MAXN; j+=i){ 
//                 if (spf[j]==j) 
//                     spf[j] = i; 
//             }
//         } 
//     } 
// }
 /*
__builtin_clz(x): This function is used to count the leading zeros of the integer. Note : clz = count leading zero’s 
__builtin_ctz(x): This function is used to count the trailing zeros of the given integer. Note : ctz = count trailing zeros.
unique(all(vec)); will remove all duplicate elements from the vector
find_by_order() - Returns an iterator to the k-th largest element (counting from zero) 
order_of_key()  - The number of items in a set that are strictly smaller than our item 
*max_element (first_iterator, last_iterator) – To find the maximum element of a vector.
*min_element (first_iterator, last_iterator) – To find the minimum element of a vector.
accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements
count(first_iterator, last_iterator,x) – To count the occurrences of x in vector.
find(first_iterator, last_iterator, x) – Points to last address of vector ((name_of_vector).end()) if element is not present in vector.
binary_search(first_iterator, last_iterator, x) – Tests whether x exists in sorted vector or not.
lower_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘x’.
upper_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘x’.
arr.erase(position to be deleted) – This erases selected element in vector and shifts and resizes the vector elements accordingly.
arr.erase(unique(arr.begin(),arr.end()),arr.end()) – This erases the duplicate occurrences in sorted vector in a single line.
next_permutation(first_iterator, last_iterator) – This modified the vector to its next permutation.
prev_permutation(first_iterator, last_iterator) – This modified the vector to its previous permutation.
goto terminal; will send execution to terminal: ; 
Sieve is used for fast factorization. pre-calculate smallest prime divisor for each number. each query is logn
 */
 
int main()
{
    fastio;
 
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
}