#include <stdio.h>
#include <stdlib.h>

int* critical;
int counter;

// function area
int max_diff (int start, int end, int* list) {
	int min = list[start];
	int max = list[start];
	for (int i = start + 1; i <= end; i++) {
		if (list[i] < min) min = list[i];
		if (list[i] > max) max = list[i];
	}
	return max - min;
}

int main ()
{
	// variables
	int num_of_employee, queries;
	scanf ("%d%d", &num_of_employee, &queries);
	int* salary = malloc (sizeof (int) * num_of_employee);
	int* diff_sal = malloc (sizeof (int) * num_of_employee);
	int* critical = malloc (sizeof (int) * num_of_employee);

	// input employee salaries
	int tmp;
	scanf ("%d", salary);
	for (int i = 1; i < num_of_employee; i++) {
		scanf ("%d", salary + i);
		diff_sal[i] = salary[i] - salary[i-1];
	}
	diff_sal[0] = 0;

	// accept && answer queries
	int start, end;
	for (int i = 0; i < queries; i++) {
		scanf ("%d%d", &start, &end);
		printf ("%d\n", max_diff (start-1, end-1, diff_sal));
	}

	// free
	free (salary);
	free (diff_sal);
	free (critical);

	
}
