INCLUDE_DIRS	:= /home/caleb/CSC310/2assign
CC				:= g++
CFLAGS			:= -I$(INCLUDE_DIRS)

OBJS			:= customError.o binaryFile.o

excRBTreeDel: main.cpp $(OBJS)
	$(CC) -o $@ $^

customError.o: customError.cpp customError.h
	$(CC) -c -o $@ $<

binaryFile.o: binaryFile.cpp binaryFile.h
	$(CC) -c -o $@ $<

.PHONY: clean

clean:
	rm $(OBJS) excBinaryFile