TARGET = ProjetoFinal
CXX = c++
LD = c++
OBJS = main.cpp Implementação/ControleClientes.cpp Implementação/Cliente.cpp
ProjetoFinal:$(OBJS)
	$(LD) -o $(TARGET) $(OBJS)