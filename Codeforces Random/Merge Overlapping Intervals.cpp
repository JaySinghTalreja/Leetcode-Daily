class Solution {
public:
    static bool comporator(vector<int> &A, vector<int> &B) {
        return A[0] < B[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.size() <=1 ) return intervals;
        sort(intervals.begin(), intervals.end(), comporator);
        stack<vector<int>> S;
        S.push(intervals[0]);

        for(int i=1;i<intervals.size();i++) {
            vector<int> temp = S.top();
            if(temp[1] >= intervals[i][0]) {
                temp[1] = max(temp[1], intervals[i][1]);
                S.pop();
                S.push(temp);
            }
            else if(temp[1] < intervals[i][0]) {
                S.push(intervals[i]);
            }
        }

        vector<vector<int>> ans;

        while(!S.empty()) {
            ans.push_back(S.top());
            S.pop();
        }

        return ans;

    }

    //Without Extra Space
    vector<vector<int>> mergeWithoutExtraSpace(vector<vector<int>>& intervals) {

        if(intervals.size() <=1 ) return intervals;
        sort(intervals.begin(), intervals.end(), comporator);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++) {

            vector<int> &temp = ans.back();
            if(temp[1] >=  intervals[i][0]) {

                temp[0] = min(intervals[i][0], temp[0]);
                temp[1] = max(intervals[i][1], temp[1]);

            }
            else {

                ans.push_back(intervals[i]);

            }

        }
        return ans;
    }


};