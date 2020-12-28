#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	int i, nsteps;
	double A, constant, x;	
	double dur;

	if(argc != 4)
	{
		printf("%s A Time Steps\n", argv[0]);
		return 1;
	}
	
 	A = atof(argv[1]);
	constant = atof(argv[2]);
	x = atoi(argv[3]);
	

	step = 0.0;
	for(i = 0; i < nsteps; i++)
	{
		printf(" %.4lf\t%.8lf\n", step, x);
		x = a * x;
		step += k;
	}

	return 0;
}
