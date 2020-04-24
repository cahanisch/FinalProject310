INCLUDE_DIRS	:= /home/caleb/CSC310/2assign
CC				:= g++
CFLAGS			:= -I$(INCLUDE_DIRS)

OBJS			:= customErrorClass.o binaryFile.o

excBinaryFile: main.cpp $(OBJS)
	$(CC) -o $@ $^

customErrorClass.o: customErrorClass.cpp customErrorClass.h
	$(CC) -c -o $@ $<

binaryFile.o: binaryFile.cpp binaryFile.h
	$(CC) -c -o $@ $<

.PHONY: clean

clean:
	rm $(OBJS) excBinaryFile output.txt