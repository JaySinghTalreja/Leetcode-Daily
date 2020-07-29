class Solution {
    public:
    bool isPossible(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, int> sub;
        unordered_map<int, int> cnt;
        for(auto i : nums) {
            cnt[i]++;
        }
        for(auto i : nums) {
            if(cnt[i]==0) continue;
            cnt[i]--;
            if(sub[i-1]) {
                sub[i-1]--;
                sub[i]++;
            }
            else if(cnt[i+1] && cnt[i+2]) {
                cnt[i+2]--;
                cnt[i+1]--;
                sub[i+2]++;
            }
            else return false;
        }
        return true;
    }
};