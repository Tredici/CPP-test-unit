CC:=g++
CPPFLAGS:=-std=c++17 -Wall -Wextra
EXE:=

FILES:=main.cc
DEPS:=$(FILES:.cc=.d)
OBJS:=$(FILES:.cc=.o)

all: run

run: main
	./main

EXE+=main
main: $(OBJS)

%.d: %.cc
	$(CC) -MM -MF $@ $<
-include $(DEPS)

clean:
	rm -f *.o *.d $(EXE)

