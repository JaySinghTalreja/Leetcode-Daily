#include <iostream>

using namespace std;

#define MAX_CHARS 127

void removeAlternateDups(char inp[], int len)
{
    // Keep an array of 127 size to store character occurrence.
    // As the size is constant, we can consider this as constant space.
    int dp[MAX_CHARS];
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (dp[inp[i]] == 1)
        {
            cnt++;
            dp[inp[i]]--;
        }
        else
        {
            dp[inp[i]] = 1;
            inp[i - cnt] = inp[i];
        }
    }
}

int main()
{
    char inp[] = "abcacdef";            //C Style Char Array
    int size = sizeof(inp) / sizeof(inp[0]);
    removeAlternateDups(inp, size);  // size is 9 as there is a \n at the end.
    cout << inp << endl;  //It's Size is still the same except a \n is added as the last character
    size = sizeof(inp) / sizeof(inp[0]);
    cout<<"\nSize:"<<size;
    return 0;
}