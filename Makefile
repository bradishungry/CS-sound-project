main: main.o filereader.o filewriter.o wav_reader.o util.o
	clang++ -o main main.o filereader.o filewriter.o wav_reader.o util.o

main.o: main.cpp main.h filereader.h util.h wav_reader.h help.h
	clang++ -c main.cpp

filereader.o: filereader.cpp filereader.h main.h util.h help.h
	clang++ -c filereader.cpp

filewriter.o: filewriter.cpp filewriter.h
	clang++ -c filewriter.cpp

wav_reader.o: wav_reader.cpp wav_reader.h
	clang++ -c wav_reader.cpp

util.o: util.cpp util.h
	clang++ -c util.cpp

clean:
	rm -f *.o
