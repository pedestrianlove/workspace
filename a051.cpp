#include <iostream>

using namespace std;

int house (int current, int total) {
	if (total == 1 || total == 0)
		return 1;
	int methods = 0;
	for (int i = 1; i <= current; i+= 2)
		if (total >= i)
			methods += house (i, total - i);
	return methods;
}

// driver code
int main ()
{
	int test_cases;
	int num;
	cin >> test_cases;
	for (int i = 0 ;i < test_cases; i++) {
		cin >> num;
		cout << house (num, num) << endl;
	}
}