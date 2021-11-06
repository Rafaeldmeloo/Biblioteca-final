#include <iostream>
#include "Controle.h"

using namespace std;


Controle::Controle()
{
    //ctor
}

Controle::~Controle()
{
    //dtor
}

void Controle::menuPrincipal(){
    std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n"
                "Olá, bem-vindo(a) ao Menu de empréstimo da Biblioteca!\n"
                "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << std::endl;
    std::cout << std::endl;
    std::cout << "--------Escolha operação--------";
    std::cout << std::endl;
    std::cout << "\n1 - Menu do Banco de Dados\n"
                "2 - Adicionar um empréstimo\n"
                "3 - Atualizar datas de empréstimo\n"
                "4 - Mostrar lista de empréstimos\n"
                "5 - Editar empréstimo\n"
                "6 - Sair do programa\n" << std::endl;

}
