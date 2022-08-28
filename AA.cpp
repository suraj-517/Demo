#include<bits/stdc++.h>
using namespace std;

void dfs(int vertex, vector<pair<int, int>> g[], vector<bool> &vis, int &ans, int &n)  // T = O(V+E)
{
    /* Take action on vertex after entering the vertex */

    vis[vertex] = true;
    for(auto child : g[vertex])
    {   
        /* Take action on child before entering the child node */
        if(vis[child.first] == true) continue;
        ans = min(ans, child.second);
        if(child.first == n){
            n = 0;
            return;
        }
        dfs(child.first, g, vis, ans, n);
        /* Take action on child after exiting child node */
    }
    /* Take action on vertex before exiting the vertex */
    return;
}
int findMaxFlow(int n, int m, vector<vector<int>> &pipes)
{
    vector<pair<int,int>> g[n+1];
    vector<bool> vis(n+1, 0);
    for(int i = 0; i < m; i++)
    {
        int u = pipes[i][0], v = pipes[i][1], val = pipes[i][2];
        g[u].push_back({v, val});
        g[v].push_back({u, val});
    }
    int ans = INT_MAX;
    dfs(1, g, vis, ans, n);
    if(n == 0) return 0;
    return ans;
}