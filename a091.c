#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int square_sum (int x) {
	return (x * (x + 1) * (2*x + 1))/6;
}

int main ()
{
	// variables
	int queries;
	int start, end;
	scanf ("%d", &queries);


	// input and accept test
	for (int i = 0; i < queries; i++) {
		scanf ("%d%d", &start, &end);
		start = ceil (sqrt(start));
		end = floor (sqrt (end));
		printf ("Case %d: %d\n", i+1, square_sum(end) - square_sum(start - 1));

	}




}
