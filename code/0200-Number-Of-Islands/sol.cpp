class Solution {
public:
#include<bits/stdc++.h>
    void mark_visited(vector<vector<char>> & grid, int i, int j, int row_len, int col_len){
        if(i > row_len-1 || j > col_len-1 || i < 0 || j < 0 || grid[i][j] != '1')
            return;
        grid[i][j] = '2';
        mark_visited(grid,i+1,j,row_len,col_len);
        mark_visited(grid,i-1,j,row_len,col_len);
        mark_visited(grid,i,j+1,row_len,col_len);
        mark_visited(grid,i,j-1,row_len,col_len);
    }
    int numIslands(vector<vector<char>>& grid) {
        // For Faster IO
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int row_len = grid.size(), col_len = grid[0].size();
        if(row_len == 0)
            return 0;
        int res = 0;
        for(int i=0;i<row_len;i++){
            for(int j=0;j<col_len;j++){
                if(grid[i][j] == '1'){
                    mark_visited(grid,i,j,row_len,col_len);
                    res++;
                }
            }
        }
        return res;
        
    }
};