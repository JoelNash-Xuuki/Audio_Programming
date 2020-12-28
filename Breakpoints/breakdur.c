#include <stdio.h>
#include "breakpoint.h"

int main(int argc, char* argv[])
{
	long size;
	double dur;
	BREAKPOINT point, *points;
	FILE* fp;

	printf("breakdur: find duration of breakpoint file\n");
	if(argc < 2)
	{
		printf("usage: breakdur infile.txt \n");
		return 0;
	}
	fp = fopen(argv[1],"r");

	if(fp == NULL)
	{
		return 0;
	}

	size = 0;
	points = get_breakpoints(fp, &size);

	if(points == NULL)
	{
		printf("No breakpoints read. \n");
		fclose(fp);
		return 1;
	}

	if(size < 2)
	{
		printf("Error: at least two breakpoints required\n");
		free(points);
		fclose(fp);
		return 1;
	}

	if(points[0].time != 0.0)
	{
		printf("Error in breakpoint data: first time must be 0.0\n");
		free(points);
		fclose(fp);
		return 1;
	}
	
	printf("read %d breakpoints\n", size);
	dur = points[size-1].time;
	printf("duration: %f seconds\n", dur);
	point = maxpoint(points, size);
	printf("maximum value: %f at %f secs\n", point.value, point.time);
	free(points);
	fclose(fp);

	return 0;
}
		

		
