#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t, r, c;
	cin >> t;
	
	while(t--){
		cin >> r >> c;
		long long maxi = max({r, c});
		long long ii = 1 + maxi*(maxi - 1); // val of botton right corner
		
		if (r >= c) { // on border of rowsq
			if (r % 2 == 1) cout << ii - (r-c) << endl;
			else cout << ii + (r-c) << endl;
		}
		else { // on border of colsq
			if (c % 2 == 1) cout << ii + (c-r) << endl;
			else cout << ii - (c-r) << endl;
		}
	}

	return 0;
}
