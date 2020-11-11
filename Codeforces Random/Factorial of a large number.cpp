#include<bits/stdc++.h>
using namespace std;

void multiply(int &len, vector<int> &res, int i) {
    int carry = 0;
    for(int index=0;index<len;index++) {
        int num = (res[index] * i) + carry;
        res[index] = num % 10;
        carry = num / 10;
    }
    while(carry) {
        res.push_back(carry % 10);
        carry /= 10;
        len++;
    }
}

void solve() {
    vector<int> result;
    int x = 5;
    result.push_back(1);
    int len = 1;

    for(int i=2;i<=x;i++) {
        multiply(len, result, i);
    }
    
    for(int i = len - 1 ;i>=0;i--)  {
        cout<<result[i];
    }
    

}

int main()
{
    solve();
    return 0;
}