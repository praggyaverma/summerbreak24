//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int topoCount = 0;
        
        int indegree[V] = {0};
        for(int i = 0; i < V; i++){
            for(auto itr : adj[i]){
                indegree[itr]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }
        
        while (!q.empty()){
            int node = q.front();
            q.pop();
            topoCount++;
            
            for(auto itr : adj[node]){
                if (indegree[itr] > 0){
                    indegree[itr]--;
                }
                if (indegree[itr] == 0){
                    q.push(itr);
                }
            }
        }
        
        return (topoCount != V); // they are not equall => CYCLE!
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
