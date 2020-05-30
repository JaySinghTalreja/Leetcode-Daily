class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int, int> count;
        int bull = 0, cow = 0;
        
        for (int i = 0; secret[i]; i ++) {
            if (secret[i] == guess[i]) bull ++;
            else {
                cow += (count[secret[i] - '0'] ++ < 0);
                //cout<<"cow 1:"<<cow<<" "<<"index:"<<i;
                cow += (count[guess[i] - '0'] -- > 0);
                //cout<<"cow 2:"<<cow<<" "<<"index:"<<i;
                //cout<<endl;
            }
        }
        
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};