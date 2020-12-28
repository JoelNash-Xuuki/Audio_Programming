#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const float sampleRate = 44100;
float coeff;
float currentLevel;
int count;

void init(float levelBegin, float levelEnd, float releaseTime) 
{
    currentLevel = levelBegin;

    coeff = (log(levelEnd) - log(levelBegin)) /
            (releaseTime * sampleRate);
}

inline void calculateEnvelope(int samplePoints) 
{
    for(int i = 0; i < samplePoints; i++) 
	{
        currentLevel += coeff * currentLevel;
		printf(" %.4lf %d\n", currentLevel, i);
	}
}

int main(int argc, char **argv)
{
	int samp;	
	int samplePoints = 640;

	init(80.001,20.08,6.0);

	calculateEnvelope(samplePoints);

	return 0;
}
