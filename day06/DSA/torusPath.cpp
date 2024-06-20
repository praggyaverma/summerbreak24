#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& grid, int n){
	int sumAll = 0;
	
	int minAD = grid[0][n - 1];
	for(int i = 0; i < n; i++){
		minAD = min(minAD, grid[i][n - i - 1]);
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sumAll += grid[i][j];
		}
	}
	
	return sumAll - minAD;
}

int main() {
	int n;
	cin >> n;
	
	vector<vector<int>> grid(n, vector<int>(n, 0));
	
	int x;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> x;
			grid[i][j] = x;
		}
	}
	
	cout << solve(grid, n) << endl;
	
	return 0;
}
