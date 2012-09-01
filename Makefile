CC = gcc -Wall -g
CFLAGS= -g -Wall
NOMBRE=ProjectC2
TARGETS=http.o

all: $(TARGETS)
	$(CC) $(CFLAGS) -o $(NOMBRE) $(TARGETS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $(<)

clean:
	rm -fv $(TARGETS) *~ *.o

test: tp3 

	@echo  "\n*** Test | Running under test ***\n"
	@./tp3 :f tp3.conf

