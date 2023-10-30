TARGET = ProjetoFinal
CXX = c++
LD = c++
OBJS = main.cpp controleClientes.cpp
ProjetoFinal:$(OBJS)
	$(LD) -o $(TARGET) $(OBJS)