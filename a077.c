#include <stdio.h>
#include <stdlib.h>

int distance (int x1, int y1, int x2, int y2) {
	return ((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

int main ()
{
	// variables
	int* x_arr;
	int* y_arr;
	int max, tmp;
	int test_cases;
	scanf ("%d", &test_cases);
	while (scanf ("%d", &test_cases) != EOF) {
		// alloc
		max = 0;
		x_arr = malloc (sizeof (int) * test_cases);
		y_arr = malloc (sizeof (int) * test_cases);

		// input
		for (int i = 0; i < test_cases; i++) 
			scanf ("%d%d", x_arr + i, y_arr + i);

		// process
		for (int i = 0 ; i < test_cases; i++) {
			for (int j = i; j < test_cases; j++) {
				tmp = distance (x_arr[i], y_arr[i], x_arr[j], y_arr[j]);
				if (max < tmp) max = tmp;
			}
		}

		// output
		printf ("%d\n", max);

		// free
		free (x_arr);
		free (y_arr);
	}
	

}
