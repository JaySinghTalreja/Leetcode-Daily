class Solution {
public:
    int countDays(vector<int>& weight, int maxWeight) {
        int days = 1;
        int currentSum=0;
        for(auto i : weight) {
            currentSum += i;
            if(currentSum > maxWeight) {
                currentSum = i;
                days++;
            }
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int right = accumulate(weights.begin(), weights.end(), 0);
        int left=*max_element(weights.begin(), weights.end());
        //int ans = 0;
        while(left < right) {
            int mid = (left+right)/2;
            if(countDays(weights, mid) > D) {
                left = mid +1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};