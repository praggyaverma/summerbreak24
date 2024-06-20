#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	int n;
	
	while (t--){
		cin >> n;
		
		if (n <= 3){
			for(int i = 1; i <= n; i++){
				cout << i << " ";
			}
			cout << endl;
			continue;
		}
		
		int x = n / 2;
		
		for(int i = x; i >= 1; i--){
			cout << i << " " << (i + x) << " ";
		}
		if (n % 2 != 0) cout << n;
		cout << endl;
	}
	
	return 0;
}
