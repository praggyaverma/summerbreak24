//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool cycleDetect(int src, vector<int> adj[], vector<int>& vis){
        // child, parent
        queue<pair<int, int>> q;
        q.push({src, -1}); // src has no parent
        vis[src] = 1;
        
        while (!q.empty()){
            int child = q.front().first;
            int parent = q.front().second;
            q.pop();
            vis[child] = 1;
            
            for(auto it : adj[child]){
                if (!vis[it]){ // if it is NOT visited
                    vis[it] = 1;
                    q.push({it, child});
                } else if (it != parent){ // if it IS visted
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        
        // for connected components
        for (int i = 0; i < V; i++){
            if (!vis[i]){
                if (cycleDetect(i, adj, vis)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
