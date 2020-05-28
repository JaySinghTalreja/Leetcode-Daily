class Solution {
public:
    vector<int> plusOne(vector<int>& digits){
        int l = digits.size();
        int carry = 1;
        vector<int> result;
        for(int i=l-1;i>=0;i--) {
            int sum = carry + digits[i];
            if(sum < 10) {
                carry = 0;
            }
            result.push_back(sum % 10);
        }
        if(carry != 0) {
            result.push_back(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};