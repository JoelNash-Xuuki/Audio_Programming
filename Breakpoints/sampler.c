#define SAMPLELEN 1048576

float* sampbuf;

sampbuf = (float*) malloc(SAMPLELEN * sizeof(float));
if (sampbuf == NULL)
	{
		puts("Sorry - not that much memory available!\n");
		exit(1);
	}

process_sample(sampbuf);
free(sampbuf);
