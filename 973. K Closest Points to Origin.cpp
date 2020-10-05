class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int, pair<int, int>>> sortedDistance;
        vector<vector<int>> ans;
        for(int i=0;i<points.size();i++) {
            int x = points[i][0];
            int y = points[i][1];
            int distance = x*x + y*y;
            sortedDistance.push_back({distance, {x, y}});
        }
        sort(sortedDistance.begin(), sortedDistance.end(), [](pair<int, pair<int, int>> &A, pair<int, pair<int, int>> &B){
            return A.first < B.first;
        });
        for(int i=0;i<K;i++) {
            ans.push_back({sortedDistance[i].second.first, sortedDistance[i].second.second});
        }
        /*for(auto C: sortedDistance) {
            cout<<"\nD:"<<C.first<<" "<<"X:"<<C.second.first<<"Y:"<<C.second.second;
        }
        vector<int> P = {1, 2};
        ans.push_back(P);
        */
        return ans;
    }
};