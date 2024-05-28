// TC - O(n)
// SC - O(1)

#include <bits/stdc++.h>
using namespace std;

void rotateK(vector<int>& arr, int k){
	k = k % arr.size();
	reverse(arr.begin(), arr.end());
	
	reverse(arr.begin(), arr.begin() + k);
	
	reverse(arr.begin() + k, arr.end());
}


int main() {
	int n;
	cin >> n;
	vector<int> vec;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		vec.push_back(x);
	}
	
	int k;
	cin >> k;
	
	rotateK(vec, k);
	
	for(int i = 0; i < n; i++){
		cout << vec[i] << " ";
	}	
	
	return 0;
}
