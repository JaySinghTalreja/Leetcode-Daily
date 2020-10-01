class Solution {
public:
    int x[8] =  {0, 0, 1, -1, -1, 1, -1, 1};
    int y[8] =  {1, -1, 1, -1, 0, 0, 1, -1};
    
    bool check(vector<vector<int>> &grid, int r, int c, int rows, int cols) {
        if(r < 0 || r >= rows || c < 0 || c>= cols || grid[r][c] == 1) {
            return false;
        }
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(grid[0][0] == 1 || grid[rows-1][cols-1] == 1) {
            return -1;
        }
        queue<pair<int, pair<int, int>>> varQueue;
        varQueue.push({0, {0, 1}});
        int count = INT_MAX;
        while(!varQueue.empty()) {
            pair<int, pair<int, int>> temp = varQueue.front();
            varQueue.pop();
            if(temp.first == rows-1 && temp.second.first == cols-1) {
                count = min(count, temp.second.second);
            }
            for(int i=0;i<8;i++) {
                int newRow = temp.first + x[i];
                int newCol = temp.second.first + y[i];
                if(check(grid ,newRow, newCol, rows, cols)) {
                    varQueue.push({newRow, {newCol, 1+temp.second.second}});
                    grid[newRow][newCol] = 1;
                }
            }
        }
        return count == INT_MAX ? -1 : count; 
                 
    }
};

//Look How we are keeping track of count of the path size using a second pair.