PRGNAME = main
VECTOR_SRC = main.cpp
CC= g++

all: $(PRGNAME) run

$(PRGNAME):$(VECTOR_SRC)
	$(CC) $(VECTOR_SRC) -o $(PRGNAME)

run: $(PRGNAME)
	./$(PRGNAME)

clean:
	rm --recursive --force $(PRGNAME)

.PHONY: run clean	
