#include <stdio.h>
#include <stdlib.h>

int num_of_employee;

// function area
int max (int x, int y) {
	if (x > y) return x;
	else return y;
}
int min (int x, int y) {
	if (x < y) return x;
	else return y;
}
int idx (int x, int y) {
	return x*num_of_employee + y;
}


int main ()
{
	// variables
	int queries;
	scanf ("%d%d", &num_of_employee, &queries);
	int* salary = malloc (sizeof (int) * num_of_employee);
	int* min_arr = malloc (sizeof (int) * (num_of_employee * num_of_employee));
	int* max_arr = malloc (sizeof (int) * (num_of_employee * num_of_employee));

	// input employee salaries
	for (int k = 0; k < num_of_employee; k++) {
		scanf ("%d", salary+k);
	}
	
	// construct min/max array
	for (int i=  0; i < num_of_employee; i++)
		for (int j= i; j < num_of_employee; j++) {
			if (i == j) {
				min_arr[idx (i, j)] = salary[i];
				max_arr[idx (i, j)] = salary[i];
			}
			else {
				min_arr[idx (i, j)] = min (min_arr[idx (i, j-1)], salary[j]);
				max_arr[idx (i, j)] = max (max_arr[idx (i, j-1)], salary[j]);
			}
//			printf ("i = %d,  j = %d, min = %d, max = %d\n", i+1, j+1, min_arr[i][j], max_arr[i][j]);
		}
	free (salary);

	
	// accept && answer queries
	int start, end;
	for (int k = 0; k < queries; k++) {
		scanf ("%d%d", &start, &end);
		printf ("%d\n", max_arr[idx (start-1, end-1)] -  min_arr[idx (start-1, end-1)]);
	}



	// free
	free (min_arr);
	free (max_arr);

	
}
