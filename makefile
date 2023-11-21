TARGET = ProjetoFinal
CXX = c++
LD = c++
OBJS = main.cpp Implementação/ControleClientes.cpp Implementação/Cliente.cpp Implementação/Dvd.cpp Implementação/Fita.cpp Implementação/Midia.cpp Implementação/ControleMidia.cpp Funções/FuncoesClientes.cpp
ProjetoFinal:$(OBJS)
	$(LD) -o $(TARGET) $(OBJS)