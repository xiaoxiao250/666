#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
	} else if (n == 2) {
		cout << 2 << endl;
	} else {
		int a = 1;
		int b = 2;
		int sum = 0;
		for (int i = 3; i <= n; i++) {
			sum = a + b; 
			a = b;       
			b = sum;     
		}
		cout << sum << endl;
	}
	return 0;
}
