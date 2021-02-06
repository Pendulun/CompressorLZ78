CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -g #-Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp1 # nome do executavel que sera gerado, nao troque
TMPOUT=tp1.testresult
BUILD=./build/
SRC=./src/
INCLUDE=./include/
COMPR=compressor/
VALID=validacao/

$(EXEC):	$(BUILD)main.o  
	$(CC) $(CFLAGS) -o $(EXEC) $(BUILD)main.o $(BUILD)$(VALID)*.o 

$(BUILD)main.o:	$(SRC)main.cpp $(BUILD)$(VALID)Validador.o  
	$(CC) $(CFLAGS) -I $(INCLUDE)$(VALID) -c $(SRC)main.cpp -o $(BUILD)main.o

$(BUILD)$(VALID)Validador.o: $(SRC)$(VALID)Validador.cpp
	$(CC) $(CFLAGS) -I $(INCLUDE)$(VALID) -c $(SRC)$(VALID)Validador.cpp -o $(BUILD)$(VALID)Validador.o

test:	$(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm -f $(BUILD)*/*.o

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(EXEC) ./testcases/EX5