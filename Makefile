LIBS        = -L ./lib/ -lportsf -lm
PORTSF		= ./lib/libportsf.a
CC = gcc

open_soundfile_read: open_soundfile_read.c $(PORTSF) 
	$(CC) -o open_soundfile_read open_soundfile_read.c $(LIBS)

