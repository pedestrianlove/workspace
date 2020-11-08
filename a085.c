#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
	int times;
	cin >> times;
	int * price_array;
	int tmp_sum, sizeof_arr, budget, member_count;
	for (int i =0; i < times; i++) {
		// input
		cin >> budget >> member_count >> sizeof_arr;
		price_array  = new int[sizeof_arr];
		for (int j = 0; j < sizeof_arr; j++)
			cin >> price_array[j];

		sort (price_array, price_array + sizeof_arr);
		tmp_sum = 0;
		for (int j = 0; j < member_count; j++) {
			tmp_sum += price_array[j];
			if (tmp_sum > budget) break;
		}
		if (tmp_sum > budget) printf ("Impossible\n");
		else printf ("%d\n", tmp_sum);

		delete (price_array);
	}


}
