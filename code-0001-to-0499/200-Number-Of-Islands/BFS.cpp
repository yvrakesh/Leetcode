class Solution {
public:
#include<bits/stdc++.h>
    int numIslands(vector<vector<char>>& grid){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int m = grid.size(), n = grid[0].size(), res = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1'){
                    res++;
                    grid[i][j] = '2';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        // Explore in four directions and make them visited
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '2';
                                q.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};