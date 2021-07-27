#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
#include<bits/stdc++.h>
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // Four possible directions to spoil the fresh fruits
        const vector<pair<int, int>> directions{{0, 1}, {1, 0},{0, -1}, {-1, 0}};
        // To count number of fresh fruits
        int count = 0;
        queue<tuple<int, int, int>> q;
        for (int r=0;r<grid.size();r++) {
            for (int c=0;c<grid[r].size();c++) {
                if (grid[r][c] == 2)
                    q.emplace(r, c, 0);
                else if (grid[r][c]  == 1)
                    ++count;
            }
        }
        int result = 0, r, c;
        // BFS queue to find out the depth of the tree (i.e. time to make all fruits rotten)
        while(!q.empty()){
            tie(r,c,result) = q.front(); 
            q.pop();
            for (const auto d : directions){
                int nr = r + d.first, nc = c + d.second;
                if(nr<0 || nc<0 || nr>m-1 || nc>n-1)
                    continue;
                // If one of it's neighbour fruit is fresh then it will be rotten
                if(grid[nr][nc] == 1) {
                    --count;
                    grid[nr][nc] = 2;
                    q.emplace(nr, nc, result + 1);
                }
            }
        }
        // If there are fresh fruits left it is impossible, so return -1
        return (count == 0) ? result : -1;
    }
};