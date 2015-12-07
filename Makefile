all: sndinfo sndcat

sndinfo: sndinfo.o filereader.o filewriter.o wav_reader.o util.o
	clang++ -o sndinfo sndinfo.o filereader.o filewriter.o wav_reader.o util.o

sndinfo.o: sndinfo.cpp sndinfo.h filereader.h util.h wav_reader.h help.h
	clang++ -c sndinfo.cpp

filereader.o: filereader.cpp filereader.h sndinfo.h util.h help.h
	clang++ -c filereader.cpp

filewriter.o: filewriter.cpp filewriter.h
	clang++ -c filewriter.cpp

wav_reader.o: wav_reader.cpp wav_reader.h
	clang++ -c wav_reader.cpp

util.o: util.cpp util.h
	clang++ -c util.cpp

sndcat: sndcat.o filereader.o filewriter.o wav_reader.o util.o
	clang++ -o sndcat sndcat.o filereader.o filewriter.o wav_reader.o util.o

sndcat.o: sndcat.cpp sndcat.h filereader.h
	clang++ -c sndcat.cpp

clean:
	rm -f *.o
