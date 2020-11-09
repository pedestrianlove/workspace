#include <stdio.h>
#include <stdlib.h>

int factorSum (int n)
{
	int range, sum = 0;
	if (n % 2 == 0)
		range = n / 2;
	else
		range = n / 3;
	for (int i = 1; i <=range; i++)
		if (n % i == 0)
			sum += i;
	return sum;
}



int main ()
{
	int input;
	while (scanf ("%d", &input) != EOF) {
		if (input == 0) break;

		int SUM = factorSum (input);
		if (input == SUM)
			printf ("=%d\n", input);
		else if (input == factorSum (SUM))
			printf ("%d\n", SUM);
		else
			printf ("0\n");
	}
}
