#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv)
{
	int i, nsteps;
	double breakpoint1, breakpoint2;
	double dur, step, start, end, thisstep;
	double fac, valrange, offset;
	const double verysmall = 1.0e-4;

	if(argc != 5)
	{
		fprintf("Usage: %s 
			duration1 duration2 npoints 
			breakpoint1 breakpoint2\n", argv[0]);
		return 1;
	}
		
	dur = atof(argv[1]);
	
	if(dur1 <= 0.0)
	{
		fprintf(stderr, 
				"Error: duration must be positive.\n");
		return 1;
	}

	dur = atof(argv[2]);

	if(dur2 <= 0.0)
	{
		fprintf(stderr, 
				"Error: duration must be positive.\n");
		return 1;
	}
	
	npoints = atoi(argv[3]);
	
	if(npoints <= 0)
	{
		fprintf(stderr, 
				"Error: npoints must be positive!\n");
		return 1;
	}
	
	step = (dur1+dur2) / nsteps;
	
	breakpoint1 = atof(argv[4]);
	breakpoint2 = atof(argv[5]);

	valrange = breakpoint1 - breakpoint2;

	if(valrange == 0.0)
	{
		fprintf(stderr, 
		"warning: start and end values are the same!\n");
	}
	
	if(breakpoint1 > breakpoint2)
	{
		start = 1.0;
		end = verysmall;
		valrange = -valrange;
		offset = endval;
	}

	else
	{
		start = verysmall;
		end = 1.0;
		offset = startval;
	}

	thisstep = 0.0;
	
	fac = pow(end / start, 1.0 / npoints);
	
	for(i = 0; i < npoints; i++)
	{
		fprintf(stdout, "%.4lf\t%.8lf\n",
			thisstep, offset + (start * valrange));

		start *= fac;
		thisstep += step;
	}

	fprintf(stdout, "%.4lf\t%.8lf\n", 
		thisstep, offset + (start * valrange));

	fprintf(stderr, "done\n");
	return 0;
}
