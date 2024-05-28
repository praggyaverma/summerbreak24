#include <bits/stdc++.h>
using namespace std;

void reverse(int i, int j, vector<int>& arr){
	if (i >= j) return;
	
	while (i < j){
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
}

void rotateK(vector<int>& arr, int k){
	k = k % arr.size();
	reverse(0, arr.size(), arr);
	
	reverse(0, k, arr);
	
	reverse(k, arr.size(), arr);
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
