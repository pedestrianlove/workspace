#include <iostream>
#include <algorithm>

using namespace std;

int num_of_employee;

// function area
int abs (int x) {
	if (x < 0)
		return -x;
	return x;
}
int max (int x, int y) {
	if (x > y) return x;
	else return y;
}
int min (int x, int y) {
	if (x < y) return x;
	else return y;
}
size_t idx (int a, int b) {
	size_t x =  a;
	size_t y =  b;
	return (x * (2 * num_of_employee - 2 - (x - 1))/2) + (y - x) - 1;
}
int eval (int target, int val) {
	return abs (val - target);
}


int main ()
{
	// variables
	int queries;
	scanf ("%d%d", &num_of_employee, &queries);
	int* salary = new int[num_of_employee];
	int* max_arr = new int[(num_of_employee * num_of_employee - num_of_employee) / 2];

	// input employee salaries
	for (int k = 0; k < num_of_employee; k++) {
		cin >> salary[k];
	}
	
	// construct min/max array
	for (int i=  0; i < num_of_employee; i++)
		for (int j= i + 1; j < num_of_employee; j++) {
			if (j == i + 1) {
				max_arr[idx (i, j)] = max (salary[i], salary[j]);
			}
			else {
				max_arr[idx (i, j)] = max (max_arr[idx (i, j-1)], salary[j]);
			}
//			printf ("i = %d,  j = %d, min = %d, max = %d\n", i+1, j+1, min_arr[idx (i, j)], max_arr[idx (i, j)]);
		}
	
	// accept && answer queries
	int start, end;
	for (int k = 0; k < queries; k++) {
		cin >> start >> end;
		if (start == end) 
			cout << 0 << endl;
		else
			cout << max_arr[idx (start-1, end-1)] -  min_arr[idx (start-1, end-1)] << endl;
	}



	// free
	delete (salary);
	delete (max_arr);

	
}
