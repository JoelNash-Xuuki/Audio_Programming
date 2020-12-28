#include<stdio.h>
#include<stdlib.h>
#include "../include/portsf.h"

int main()
{
	PSF_PROPS props;
	int sf;

	psf_init();

	props.srate = 44100;
	props.chans = 6;
	props.samptype = PSF_SAMP_16;
	props.format = PSF_STDWAVE;
	props.chformat = MC_STEREO;

	sf = psf_sndCreate("write_sf_test.wav", &props, 1, 0, PSF_CREATE_RDWR);
	if(sf < 0)
	{
		printf("Error: unable to create output file\n");
		return 1;
	}

	psf_finish();
	return 0;
}


