#include <iostream>
#include <algorithm>

using namespace std;

size_t num_of_employee;

// function area
unsigned short max (unsigned short x, unsigned short y) {
	if (x > y) return x;
	else return y;
}
unsigned short min (unsigned short x, unsigned short y) {
	if (x < y) return x;
	else return y;
}
size_t idx (int a, int b) {
	size_t x =  a;
	size_t y =  b;
	return (x * (2 * num_of_employee - 2 - (x - 1))/2) + (y - x) - 1;
}


int main ()
{
	int x;
	try {
	x=0;
	// variables
	int queries;
	//scanf ("%lld%d", &num_of_employee, &queries);
	cin >> num_of_employee >> queries;
	x=-1;
	//int* salary = new int[num_of_employee];
	unsigned short* salary = new unsigned short[num_of_employee];
	x=-2;
	//int* min_arr = new int[(size_t) ((num_of_employee * num_of_employee - num_of_employee) / 2)];
	unsigned short *min_arr = new unsigned short[((size_t)(num_of_employee * num_of_employee) - num_of_employee) / 2];
	x=-3;
	//int* max_arr = new int[(size_t) ((num_of_employee * num_of_employee - num_of_employee) / 2)];
	unsigned short *max_arr = new unsigned short[((size_t)(num_of_employee * num_of_employee) - num_of_employee) / 2];
	x=1;
	// input employee salaries
	for (int k = 0; k < num_of_employee; k++) {
		cin >> salary[k];
	}
	x=2;
	// construct min/max array
	for (int i=  0; i < num_of_employee; i++)
		for (int j= i + 1; j < num_of_employee; j++) {
			if (j == i + 1) {
				min_arr[idx (i, j)] = min (salary[i], salary[j]);
				max_arr[idx (i, j)] = max (salary[i], salary[j]);
			}
			else {
				min_arr[idx (i, j)] = min (min_arr[idx (i, j-1)], salary[j]);
				max_arr[idx (i, j)] = max (max_arr[idx (i, j-1)], salary[j]);
			}
//			printf ("i = %d,  j = %d, min = %d, max = %d\n", i+1, j+1, min_arr[idx (i, j)], max_arr[idx (i, j)]);
		}
	x=3;
	// accept && answer queries
	int start, end;
	for (int k = 0; k < queries; k++) {
		cin >> start >> end;
		if (start == end) 
			cout << 0 << endl;
		else
			cout << max_arr[idx (start-1, end-1)] -  min_arr[idx (start-1, end-1)] << endl;
	}

	x=4;

	// free
	delete (salary);
	//delete (min_arr);
	//delete (max_arr);
  } catch (bad_array_new_length& e) {
    cout << x << ":" << e.what() << '\n';
  } catch (bad_alloc& e) {
    cout << x << ":" << e.what() << '\n';
  }

	
}
