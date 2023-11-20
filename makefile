TARGET = ProjetoFinal
CXX = c++
LD = c++
OBJS = main.cpp Implementação/ControleClientes.cpp Implementação/Cliente.cpp Implementação/Dvd.cpp Implementação/Fita.cpp Implementação/Midia.cpp Implementação/controleMidia.cpp
ProjetoFinal:$(OBJS)
	$(LD) -o $(TARGET) $(OBJS)