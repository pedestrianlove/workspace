#include <stdio.h>
#include <stdlib.h>

int find_min (int start, int end, int* list) {
	int min = list[start];
	for (int i = start + 1; i < end; i++)
		if (list[i] < min) min = list[i];
	return min;
}
int find_max (int start, int end, int* list) {
	int max = list[start];
	for (int i = start + 1; i < end; i++)
		if (list[i] > max) max = list[i];
	return max;
}
int max_diff (int start, int end, int* list) {
	return find_max(start, end, list) - find_min (start, end, list);
}

int main ()
{
	// variables
	int num_of_employee;
	scanf ("%d", &num_of_employee);
	int* salary = malloc (sizeof (int) * num_of_employee);
	int queries;
	scanf ("%d", &queries);


	// input employee salaries
	int tmp;
	scanf ("%d", salary);
	for (int i = 1; i < num_of_employee; i++) {
		scanf ("%d", salary + i);
		salary[i] -= salary[0];
	}

	// accept && answer queries
	int start, end;
	for (int i = 0; i < queries; i++) {
		scanf ("%d%d", &start, &end);
		printf ("%d\n", max_diff (start-1, end-1, salary));
	}



	
}
