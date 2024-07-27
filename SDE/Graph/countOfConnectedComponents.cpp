class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;

        for(auto child : adj[node]){
            if (!visited[child]){
                dfs(child, adj, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();

        vector<vector<int>> adj(cities);

        for(int i = 0; i < cities; i++){
            for(int j = 0; j < cities; j++){
                if (isConnected[i][j] == 1)
                adj[i].push_back(j);
            }
        }

        int countOfProvinces = 0;

        vector<int> visited(cities, 0);
        for(int i = 0; i < cities; i++){
            if (!visited[i]){
                dfs(i, adj, visited);
                countOfProvinces++;
            }
        }

        return countOfProvinces;       
    }
};
