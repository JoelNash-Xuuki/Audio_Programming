#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>
#include <wave.h>

#define OSC_WRAPPHASE  if(p_osc->curphase > TWOPI) p_osc->curphase -= TWOPI;	\
						if(p_osc->curphase < 0.0) p_osc->curphase += TWOPI

OSCIL*   new_oscil(double srate)
{
	OSCIL* p_osc;

	p_osc = (OSCIL*) malloc(sizeof(OSCIL));
	if(p_osc==NULL)
		return NULL;
	p_osc->twopiovrsr = TWOPI / srate;
	p_osc->curfreq = 0.0;
	p_osc->curphase = 0.0;
	p_osc->incr = 0.0;
	return p_osc;
}

double sinetick(OSCIL* p_osc, double freq)
{
	double val;

	val = sin(p_osc->curphase);
	if(p_osc->curfreq != freq){
		p_osc->curfreq = freq;
		p_osc->incr = p_osc->twopiovrsr * freq;		
	}	
	p_osc->curphase += p_osc->incr;
	OSC_WRAPPHASE;
	return val;
}
