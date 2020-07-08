class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 0) continue;
                if(i == 0)  p++;
                if(j == 0)  p++;
                if(i == grid.size()-1)  p++;
                if(j == grid[0].size()-1)   p++;
                if((i-1 >= 0) and grid[i-1][j] == 0) p++;
                if((i+1 < grid.size()) and grid[i+1][j] == 0) p++;
                if((j-1 >= 0) and grid[i][j-1] == 0) p++;
                if((j+1 < grid[0].size()) and grid[i][j+1] == 0) p++;
            }
        }
        return p;
    }
};
