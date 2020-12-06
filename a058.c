#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min (int x, int y) {
	if (x < y)	return x;
	else		return y;
}

int BIAS (int x, int y) {
	if (x == y) return 0;
	else if (x < y) return 1;
	else return -1;
}
int count (int* x_arr, int x_n, int* y_arr, int y_n) {
	//printf ("---------------------------------\n");
	if (x_n * y_n == 0) return 0;
	int x_count = 0, y_count = 0;
	int* x_val = malloc (sizeof (int) * x_n);
	int* y_val = malloc (sizeof (int) * y_n);
	int x_prev = 0, y_prev = 0;
	//printf ("x_val = ");
	for (int i =0 ;i < x_n; i++)
		if (x_prev != x_arr[i]) {
	//		printf ("%d ", x_arr[i]);
			x_val[x_count++] = x_arr[i];
			x_prev = x_arr[i];
		}
	//printf ("\n");
	//printf ("y_val = ");
	for (int i =0 ;i < y_n; i++)
		if (y_prev != y_arr[i]) {
	//		printf ("%d ", y_arr[i]);
			y_val[y_count++] = y_arr[i];
			y_prev = y_arr[i];
		}
	//printf ("\n");

	// find intersection
	int inter_count = 0;
	for (int i =0; i < x_count; i++) {
		for (int j = 0; j < y_count; j++) {
			if (x_val[i] == y_val[j])
				inter_count ++;
		}
	}

	// free
	free (x_val);
	free (y_val);
	//printf ("%d %d %d\n", x_count, y_count, inter_count);
	return min (x_count, y_count) - inter_count;
}
int distance (int* x_arr, int x_n, int* y_arr, int y_n) 
{
	printf ("---------------------------------\n");
	if (x_n * y_n == 0) return 0;
	int x_idx = 0;
	int y_idx = 0;
	int x_val = 0, y_val = 0;
	int x_count = 0, y_count = 0;
	int bias = 2;
	while (x_idx < x_n || y_idx < y_n) {
		if (x_idx >= x_n)
			if (bias == 0 || y_val == y_arr[y_idx]) {
				bias = BIAS (x_val, y_arr[y_idx]);
				y_idx++;
			}
			else {
				if (bias * BIAS(x_val, y_arr[y_idx] == -1)) {
					y_val = y_arr[y_idx++];
					y_count ++;
					bias = BIAS (x_val, y_val);
					printf ("     y: %d\n", y_val);
				}
			}
		else if (y_idx >= y_n)
			if (bias == 0|| x_val == x_arr[x_idx]){
				bias = BIAS (x_arr[x_idx], y_val);
				x_idx++;
			}
			else {
				if (bias * BIAS (x_arr[x_idx], y_val) == -1) {
					x_val = x_arr[x_idx++];
					x_count ++;
					bias = BIAS (x_val, y_val);
					printf ("x: %d\n", x_val);
				}
			}
		else{
			if (x_val == x_arr[x_idx]) {
				x_idx++;
			
			}
			else {
				x_val = x_arr[x_idx++];
				x_count ++;
			printf ("x: %d\n", x_val);
			}
		}	
		
	}
	printf ("%d %d\n", x_count, y_count);
	return min (x_count, y_count);
}

int main ()
{
	// variables
	int* x_arr;
	int* y_arr;
	int max;
	int size_x, size_y;
	
	// game start
	while (scanf ("%d%d", &size_x, &size_y) != EOF) {
		if (size_x == 0 && size_y == 0) break;
		// alloc
		max = 0;
		x_arr = malloc (sizeof (int) * size_x);
		y_arr = malloc (sizeof (int) * size_y);

		// input
		for (int i = 0; i < size_x; i++) 
			scanf ("%d", x_arr + i);
		for (int i = 0; i < size_y; i++) 
			scanf ("%d", y_arr + i);

		// process
		max = count (x_arr, size_x, y_arr, size_y);

		// output
		printf ("%d\n", max);

		// free
		free (x_arr);
		free (y_arr);
	}
	

}
