class Solution {
#include<bits/stdc++.h>
public:
    void dfs(int i,int parent, vector<bool>& vis, vector<int>& dis,vector<int>& low,vector<vector<int>>& bridges, vector<vector<int>>& graph){
        vis[i] = true;
        low[i] = dis[i] = dis[parent] + 1;
        for(int j:graph[i]){
            if(!vis[j]){
                dfs(j,i,vis,dis,low,bridges,graph);
                // Update Parent's Lowest reachable node taking child into consideration
                low[i] = min(low[i],low[j]);
                // Checking if least ancestor of the i's child has a backedge
                // There will be a back edge if its least ancestor is lesser than its current depth.
                // So in this case removing that edge will not disturb the network
                // If there is a back edge from it's child to itself even then removing one edge will not disturb the network
                if(low[j] > dis[i])
                    bridges.push_back({i,j});
            }
            // Ignore Child to Parent Node
            else if (j != parent)
                // This is a backedge so updating low value
                low[i] = min(low[i],dis[j]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // For Faster IO
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Get Adjacency List
        vector<vector<int>> graph(n, vector<int>());
        for(auto i:connections){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        // low  -> Lowest id reachable node
        // dis  -> Depth
        vector <int> dis(n,-1), low(n,-1);
        // vis  -> visited
        vector <bool> vis(n,false);
        // We'll add all bridge forming pairs and return this
        vector <vector <int>> bridges;
        for(int i=0;i<n;i++)
            if(!vis[i])
                dfs(i,i,vis,dis,low,bridges,graph);
        return bridges;
    }
};