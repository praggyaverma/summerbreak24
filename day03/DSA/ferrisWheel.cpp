#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	vector<int> c;
	
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		c.push_back(x);
	}
	
	int count = 0;
	sort(c.begin(), c.end());
	int i = 0, j = n - 1;
	
	while (i <= j){
		if (c[i] + c[j] <= x){
			count++;
			i++;
			j--;
		} else {
			count++;
			j--;
		}
	}
	cout << count << endl;
	return 0;
}
