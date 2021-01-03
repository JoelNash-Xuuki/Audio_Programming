#include<stdio.h>
#include<stdlib.h>
#include "../include/portsf.h"

int check_sampletype(psf_stype type);
int check_sampleformat(psf_format format);

int main(int argc, char *argv[])
{
	int sf;
	const char *filename;
	int i;
	PSF_PROPS props;
	psf_format format;

	while (--argc > 0)
		filename = *++argv;

	printf("Reading: %s\n", filename); 

	
	format = psf_getFormatExt(filename);
	sf = psf_sndOpen(filename, &props, 0);

	psf_init();
	
	if(sf < 0){
		printf("Error: unable to open soundfile\n");
		return 1;
	}

	if(!check_sampletype(props.samptype)){
		printf("file has unsupported sample type\n");
		return 1;
	}

	if(!check_sampleformat(props.format)){
		printf("file has unsupported sample type\n");
		return 1;
	}

	printf("Sample rate: %d\n", props.srate);
	printf("Number of channels: %d\n", props.chans);
	
	psf_finish();

	return 0;
}

int check_sampletype(psf_stype type)
{
	int accept = 1;

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

int check_sampleformat(psf_format format)
{
	int accept = 1;
	char *f = "Format:";

	switch(format){
	case(PSF_STDWAVE):
		printf("%s .wav file\n", f);
		break;
	case(PSF_WAVE_EX):
		printf("%s .wav file\n", f);
		break;
	case(PSF_AIFF):
		printf("%s .aif\n", f);
		break;
	case(PSF_AIFC):
		printf(".aif\n");
		break;
	default:
		printf("unknown\n");
		accept = 0;
	}

	return accept;
}
