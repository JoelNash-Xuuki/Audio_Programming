LIBS        = -L ./lib/ -lportsf -lm
PORTSF		= ./lib/libportsf.a
SOUNDFILE	= Soundfile_Handling/
CC = gcc

$(SOUNDFILE)read: $(SOUNDFILE)read.c $(PORTSF) 
	$(CC) -o $(SOUNDFILE)read $(SOUNDFILE)read.c $(LIBS)

#$(SOUNDFILE)write: $(SOUNDFILE)write.c $(PORTSF) 
#	$(CC) -o $(SOUNDFILE)write $(SOUNDFILE)write.c $(LIBS)

