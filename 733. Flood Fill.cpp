class Solution {
public:
    bool bcheck(int sr, int sc, int rows,int cols) {
        if(sr<0 || sr >= rows || sc < 0 || sc >=cols) return false;
        return true;
    }
    void dofloodFill(vector<vector<int>> &image, int sr, int sc, int newColor, int rows, int cols, int source) {
        if(!bcheck(sr, sc, rows, cols)){
            return;
        }
        else if(image[sr][sc] != source || image[sr][sc] == newColor) {
            return;
        }
        image[sr][sc] = newColor;
        dofloodFill(image, sr+1, sc, newColor, rows, cols, source);
        dofloodFill(image, sr-1, sc, newColor, rows, cols, source);
        dofloodFill(image, sr, sc+1, newColor, rows, cols, source);
        dofloodFill(image, sr, sc-1, newColor, rows, cols, source);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(!bcheck(sr, sc, image.size(), image[0].size())){
            return image;
        }
        dofloodFill(image, sr, sc, newColor, image.size(), image[0].size(), image[sr][sc]);
        return image;
    }
};

//Time -O(M*N)

//BFS
int row[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int col[] = { -1,  0,  1, -1, 1, -1, 0, 1 };

// check if it is possible to go to pixel (x, y) from
// current pixel. The function returns false if the pixel
// has different color or it is not a valid pixel
bool isSafe(char mat[M][N], int x, int y, char target)
{
	return (x >= 0 && x < M && y >= 0 && y < N)
		&& mat[x][y] == target;
}

// Flood fill using BFS
void floodfill(char mat[M][N], int x, int y, char replacement)
{
	// create a queue and enqueue starting pixel
	queue<pair<int, int>> q;
	q.push({x, y});

	// get target color
	char target = mat[x][y];

	// run till queue is not empty
	while (!q.empty())
	{
		// pop front node from queue and process it
		pair<int, int> node = q.front();
		q.pop();

		// (x, y) represents current pixel
		int x = node.first, y = node.second;

		// replace current pixel color with that of replacement
		mat[x][y] = replacement;

		// process all 8 adjacent pixels of current pixel and
		// enqueue each valid pixel
		for (int k = 0; k < 8; k++)
		{
			// if adjacent pixel at position (x + row[k], y + col[k]) is
			// a valid pixel and have same color as that of current pixel
			if (isSafe(mat, x + row[k], y + col[k], target))
			{
				// enqueue adjacent pixel
				q.push({x + row[k], y + col[k]});
			}
		}
	}
}

//Time O(M*N)
