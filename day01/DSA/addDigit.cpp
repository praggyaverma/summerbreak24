// TC - O(1)
// SC - O(1)
// for both approaches

#include <bits/stdc++.h>
using namespace std;

int addDigit(int num){
	if (num % 9 == 0 && num != 0) return 9;
    else return num % 9;
}

int addDigit1(int num){
	if (num == 0) return 0;
	return ((num - 1) % 9) + 1;
}

int main() {
	int num;
	cin >> num;
	
	cout << addDigit1(num) << endl;
  cout << addDigit2(num) << endl;
	
	return 0;
}
