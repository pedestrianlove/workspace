#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main ()
{
	// variables
	int amount;
	cin >> amount;
	int * works = new int[amount];

	// input
	for (int i = 0; i < amount; i++) {
		cin >> works[i];
	}

	// process
	sort (works, works + amount);
	int right_sum = works[amount - 1], left_sum = 0;
	int index = amount - 2;
	while (index >= 0) {
		if (right_sum >= left_sum)
			left_sum += works[index];
		else
			right_sum += works[index];
		index --;
	}

	// output
	if (left_sum == right_sum)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	// free memory
	delete (works);
}
