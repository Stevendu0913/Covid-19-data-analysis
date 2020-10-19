CXX = g++
CFLAGS = -O -I.
SRC = main.cpp country.cpp record.cpp support.cpp
OBJ = $(subst .cpp,.o,$(SRC))
all: plot_covid run

plot_covid :$(OBJ)
	$(CXX) $(CFLAGS) -o $@ $^

run:
	./plot_covid
clean:
	rm -f *.o plot_covid
