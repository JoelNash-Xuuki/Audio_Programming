#ifndef __WAVE_H_INCLUDED__
#define	__WAVE_H_INCLUDED__

#ifdef __cplusplus
extern "C" {	
#endif

#ifndef M_PI
#define M_PI  (3.1415926535897932)
#endif

#ifndef TWOPI
#define TWOPI (2.0 * M_PI)
#endif

typedef struct  t_oscil 
{
	double srate;
	double twopiovrsr;
	double curfreq;
	double curphase;
	double incr;
} OSCIL;

OSCIL*  new_oscil(double srate);

double sinetick  (OSCIL* p_osc, double freq);

typedef double (*tickfunc)(OSCIL* osc,double);

#ifdef __cplusplus
}	
#endif

#endif
