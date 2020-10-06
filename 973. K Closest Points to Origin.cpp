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

//Using Quick Select //O(NLogK)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int l = 0, r = points.size() - 1;
        while (true) {
            int p = partition(points, l, r);
            if (p == K - 1) {
                break;
            }
            if (p < K - 1) {
                l = p + 1;
            } else {
                r = p - 1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
private:
    bool farther(vector<int>& p, vector<int>& q) {
        return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
    }
    
    bool closer(vector<int>& p, vector<int>& q) {
        return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        int pivot = left, l = left + 1, r = right;
        while (l <= r) {
            if (farther(points[l], points[pivot]) && closer(points[r], points[pivot])) {
                swap(points[l++], points[r--]);
            }
            if (!farther(points[l], points[pivot])) {
                l++;
            }
            if (!closer(points[r], points[pivot])) {
                r--;
            }
        }
        swap(points[pivot], points[r]);
        return r;
    }
};