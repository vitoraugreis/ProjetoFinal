TARGET = ProjetoFinal
CXX = c++
LD = c++
OBJS = main.cpp ControleClientes.cpp Cliente.cpp
ProjetoFinal:$(OBJS)
	$(LD) -o $(TARGET) $(OBJS)