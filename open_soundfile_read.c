#include<stdio.h>
#include<stdlib.h>
#include "./include/portsf.h"

int check_sampletype(psf_stype type);

int main(int argc, char **argv)
{
	PSF_PROPS props;
	int sf;
	psf_init();

	sf = psf_sndOpen("sample.wav", &props, 0);
	
	if(sf < 0){
		printf("Error: unable to open soundfile\n");
		return 1;
	}

	if(!check_sampletype(props.samptype)){
		printf("file has unsupported sample type\n");
		return 1;
	}
	else{
		check_sampletype(props.samptype);
	}

	printf("Sample rate = %d\n", props.srate);
	printf("number of channels = %d\n", props.chans);

	
	psf_finish();

	return 0;

}

int check_sampletype(psf_stype type)
{
	int accept = 1;

	printf("sample type: ");
	switch(type){
	case(PSF_SAMP_8):
		printf("8 bit\n");
		accept = 0;
		break;
	case(PSF_SAMP_16):
		printf("16 bit\n");
		break;
	case(PSF_SAMP_24):
		printf("24 bit\n");
		break;
	case(PSF_SAMP_32):
		printf("32 bit (integer)\n");
		break;
	case(PSF_SAMP_IEEE_FLOAT):
		printf("32 bit floating point\n");
		break;
	default:
		printf("unknown\n");
		accept = 0;
	}

	return accept;
}
