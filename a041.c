#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* max_critical;
int max_count;
int* min_critical;
int min_count;
int num_of_employee;

// function area
int find_max (int start, int end, int* list) {
	int max = list[start];
	if (list[end] > max) max = list[end];
	for (int i = 0; i < max_count; i++) {
		if (max_critical[i] >= start && max_critical[i] <= end && list[max_critical[i]] > max) {
			max = list[max_critical[i]];
		}
	}
	return max;
}
int find_min (int start, int end, int* list) {
	int min = list[start];
	if (list[end] < min) min = list[end];
	for (int i = 0; i < min_count; i++){ 
		if (min_critical[i] >= start && min_critical[i] <= end && list[min_critical[i]] < min) {
			min = list[min_critical[i]];
		}
	}
	return min;
}
int max_diff (int start, int end, int* list) {
	int max = find_max (start, end, list);
	int min = find_min (start, end, list);
	return max - min;
}

int main ()
{
	// variables
	int queries;
	scanf ("%d%d", &num_of_employee, &queries);
	int* salary = malloc (sizeof (int) * num_of_employee);
	int* diff_sal = malloc (sizeof (int) * num_of_employee);
	max_critical = malloc (sizeof (int) * num_of_employee);
	min_critical = malloc (sizeof (int) * num_of_employee);

	// input employee salaries
	int tmp;
	scanf ("%d", salary);
	diff_sal[0] = 0;
	max_count = 0;
	min_count = 0;
	for (int i = 1; i < num_of_employee; i++) {
		scanf ("%d", salary + i);
		diff_sal[i] = salary[i] - salary[i-1];
		if (diff_sal[i-1] > 0 && diff_sal[i] < 0)
			max_critical[max_count++] = i - 1;
		if (diff_sal[i-1] < 0 && diff_sal[i] > 0)
			min_critical[min_count++] = i - 1;

	}
	// accept && answer queries
	int start, end;
	for (int i = 0; i < queries; i++) {
		scanf ("%d%d", &start, &end);
		printf ("%d\n", max_diff (start-1, end-1, salary));
	}

	// free
	free (salary);
	free (diff_sal);
	free (max_critical);
	free (min_critical);

	
}
