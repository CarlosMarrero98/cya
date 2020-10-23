TARGET = main_capicua 		#Variable con el nombre de programa
OBJS = main_capicua.o palindrome_prod.o 		#Variable de las que depende mi programa
CXXFLAGS = -g -O0
CXX = g++

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o  $(TARGET)

%.o : %.cc		#Genera un archivo .o a partir de un archivo .cc
	@$(CXX) -c $(CXXFLAGS) $^ -o $@

.PHONY : clean
clean:
	@rm -f *.o *.txt $(TARGET)