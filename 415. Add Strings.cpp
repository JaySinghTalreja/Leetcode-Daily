class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        string ans = "";
        int carry = 0;
        int j = m-1;
        int i = n-1;
        while(i>=0 || j>=0 || carry) {
            int num = 0 ;
            if(i>=0) {
                num += num1[i] - '0';
                i--;
            }
            if(j>=0) {
                num += num2[j] - '0';
                j--;
            }
            num += carry;
            carry = num / 10;
            num = num % 10;
            ans += to_string(num);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//Better Solution
string addStrings(string num1, string num2) {
    int sum = 0, i = num1.length() - 1, j = num2.length() - 1;
    string str;
    while (i >= 0 || j >= 0 || sum > 0) {
        if (i >= 0) sum += (num1[i--] - '0');
        if (j >= 0) sum += (num2[j--] - '0');
        str.insert(0, 1, (sum % 10) + '0');
        sum /= 10;
    }
    return str;
}