#include "ControleMidiaExceptions.hpp"

namespace midia_excp {

codigo_repetido::codigo_repetido(int codigo) : _codigo(codigo) {}

codigo_inexistente::codigo_inexistente(int codigo) : _codigo(codigo) {}

tipo_desconhecido::tipo_desconhecido(int tipoMidia) : _tipoMidia(tipoMidia) {}

erro_de_abertura::erro_de_abertura(std::string arquivo) : _arquivo(arquivo) {}

ordem_invalida::ordem_invalida(char ordem) : _ordem(ordem) {}

} 