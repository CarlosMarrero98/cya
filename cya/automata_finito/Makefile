TARGET = main_automata 		#Variable con el nombre de programa
OBJS = main_automatas.o DFA.o estado.o 		#Variable de las que depende mi programa
CXXFLAGS = -g -O0
CXX = g++

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o  $(TARGET)

%.o : %.cc		#Genera un archivo .o a partir de un archivo .cc
	@$(CXX) -c $(CXXFLAGS) $^ -o $@

.PHONY : clean
clean:
	@rm -f *.o outfile.txt $(TARGET)

push:
	git pull 
	git add . 
	git commit -m "Another example" 
	git push 