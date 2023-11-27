#include "ControleClientesExceptions.hpp"

namespace clientes_excp {

cpf_curto::cpf_curto(std::string cpf) : _cpf(cpf) {}

cpf_repetido::cpf_repetido(std::string cpf) : _cpf(cpf) {}

cpf_inexistente::cpf_inexistente(std::string cpf) : _cpf(cpf) {}

ordem_invalida::ordem_invalida(char ordem) : _ordem(ordem) {}

} 