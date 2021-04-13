STD = -std=c++2a
OPT = -O3
WARN = -Wall -Wextra
GCC = g++ $(OPT) $(STD) $(WARN)
PROGRAM = main

RANDOM = $(addprefix random/, uniform normal exponential poisson gamma generator chi-square beta student-t geometric binomial)
FILES = $(RANDOM) $(DATA)

INCLUDE = $(addsuffix .h,$(FILES)) $(addsuffix .h,$(ARGPARSER)) random/random.h tensor/tensor.h
MAIN = main.cpp
SRC = $(addsuffix .cpp,$(FILES)) $(MAIN) $(addsuffix .cpp,$(ARGPARSER))

all: random


random: $(INCLUDE) $(SRC)
	$(GCC) -o $(PROGRAM) $(SRC)


clean:
	rm *.o *.s
