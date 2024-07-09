//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& path){
        vis[node] = 1;
        path[node] = 1;
        
        for(auto it : adj[node]){
            if (!vis[it]){ // it is NOT visited!
                if (dfs(it, adj, vis, path))
                    return true;
            } else if (path[it]) // it IS visted and IS in path
                return true;
        }
        
        // if cycle not found, then forgot path and return false
        path[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        
        for(int i = 0; i < V; i++){
            if (!vis[i]){
                if (dfs(i, adj, vis, path))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
