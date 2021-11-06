#include <iostream>
#include <iomanip>
#include <locale.h>
#include "Clientes.h"
#include "ClienteVip.h"
#include "Emprestimo.h"

using namespace std;

namespace Cliente{
ClienteVip::ClienteVip()
{

}

ClienteVip::~ClienteVip()
{
    //dtor
}

bool ClienteVip::getVip(){
    return true;
}

void ClienteVip::AdicionaEmprestimo(Emprestimo emp){

        if(emprestimo.getLivros() == ""){
            emprestimo = emp;
            emprestimo.setPrazo(60);
        }else{
            emprestimo2 = emp;
            emprestimo2.setPrazo(60);
        }
        std::cout << std::endl;
        std::cout << "----Empréstimo adicionado com sucesso----\n" << std::endl;
}

void ClienteVip::setEmp(Emprestimo emp){
    emprestimo = emp;

}

Emprestimo ClienteVip::getEmp(){
    return emprestimo;
}

void ClienteVip::AtualizaPrazo(){
    emprestimo.setPrazo(emprestimo.getPrazo() - 1);
    if(emprestimo2.getLivros() != "")
        emprestimo2.setPrazo(emprestimo2.getPrazo() - 1);
}

void ClienteVip::MostrarLista(){
    setlocale(LC_ALL, "Portuguese");

        std::cout << std::endl;
        std::cout << "Nome: " << emprestimo.getNomes() << std::endl;
        std::cout << "Livro(s): " << std::endl;
        std::cout << "  " + emprestimo.getLivros() << std::endl;
        if(emprestimo2.getLivros() != "")
            std::cout << "  " + emprestimo2.getLivros() << std::endl;

        if(emprestimo.getPrazo() >= 0){
            std::cout << "Prazo de devolução: " << emprestimo.getPrazo() << " dias" << std::endl;
            std::cout << std::endl;

        }else{
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Prazo de devolução expirado a " << emprestimo.getPrazo() * (-1) << " dia(s)" << std::endl;
            std::cout << "Multa a ser paga: R$" << emprestimo.getPrazo() * (-1) * 2.0 << std::endl;
        }

}

int ClienteVip::ExcluirEmprestimo(std::string procuraL, std::string procuraN){
    setlocale(LC_ALL, "Portuguese");

    if(emprestimo.getNomes().find(procuraN) != std::string::npos){
        if(emprestimo.getLivros().find(procuraL) != std::string::npos ){
            std::cout << std::endl;
            std::cout << "Livro: " << emprestimo.getLivros() << std::endl;
            std::cout << "Nome: " << emprestimo.getNomes() << std::endl;

            if(emprestimo.getPrazo() >= 0){
            std::cout << "Prazo de devolução: " << emprestimo.getPrazo() << " dias" << std::endl;
            std::cout << std::endl;
            }else{
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Prazo de devolução expirado a " << emprestimo.getPrazo() * (-1) << " dia(s)" << std::endl;
                std::cout << "Multa a ser paga: R$" << emprestimo.getPrazo() * (-1) * 2.0 << std::endl;
            }
                std::cout << "Deseja realmente excluir esse empréstimo?\n"
                            "1 - Sim\n"
                            "2 - Não" << std::endl;
            int op = 0;
            std::cin >> op;
            getchar();

            if(op == 2)
                return 2;
            else{
                emprestimo.setLivros(emprestimo2.getLivros());
                emprestimo.setNomes(emprestimo2.getNomes());
                emprestimo2.setLivros("");
                emprestimo2.setNomes("");

                if(emprestimo.getLivros() == "" && emprestimo2.getLivros() == "")
                    return 1;
                else
                    return 2;
            }
        }else if(emprestimo2.getLivros().find(procuraL) != std::string::npos ){
            std::cout << std::endl;
            std::cout << "Livro: " << emprestimo2.getLivros() << std::endl;
            std::cout << "Nome: " << emprestimo2.getNomes() << std::endl;

            if(emprestimo.getPrazo() >= 0){
                std::cout << "Prazo de devolução: " << emprestimo2.getPrazo() << " dias" << std::endl;
                std::cout << std::endl;
            }else{
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "Prazo de devolução expirado a " << emprestimo2.getPrazo() * (-1) << " dia(s)" << std::endl;
                std::cout << "Multa a ser paga: R$" << emprestimo2.getPrazo() * (-1) * 2.0 << std::endl;
            }
            std::cout << "Deseja realmente excluir esse empréstimo?\n"
                        "1 - Sim\n"
                        "2 - Não" << std::endl;
            int op = 0;
            std::cin >> op;
            getchar();

            if(op == 2)
                return 2;
            else{
                emprestimo2.setLivros("");
                emprestimo2.setNomes("");
                if(emprestimo.getLivros() == "" && emprestimo2.getLivros() == "")
                    return 1;
                else
                    return 2;
            }

        }
    }

    return 0;
}

bool ClienteVip::AlterarEmprestimo(std::string procuraL, std::string procuraN){
    setlocale(LC_ALL, "Portuguese");
    int alterar = -1;
    std::string nvLivro, nvNome;
    int nvPrazo;

        if(emprestimo.getNomes().find(procuraN) != std::string::npos){
            if(emprestimo.getLivros().find(procuraL) != std::string::npos){
                std::cout << std::endl;
                std::cout << "Livro: " << emprestimo.getLivros() << std::endl;
                std::cout << "Nome: " << emprestimo.getNomes() << std::endl;

                if(emprestimo.getPrazo() >= 0){
                    std::cout << "Prazo de devolução: " << emprestimo.getPrazo() << " dias" << std::endl;
                    std::cout << std::endl;
                }else{
                    std::cout << std::fixed << std::setprecision(2);
                    std::cout << "Prazo de devolução expirado a " << emprestimo.getPrazo() * (-1) << " dia(s)" << std::endl;
                    std::cout << "Multa a ser paga: R$" << emprestimo.getPrazo() * (-1) * 2.0 << std::endl;
                }
                std:: cout << std::endl;

                std::cout << "-------O que deseja alterar?-------" << std::endl;
                std::cout << "1 - Nome do livro\n"
                            "2 - Nome do cliente\n"
                            "3 - Prazo de entrega\n"
                            "4 - Cancelar alteração" << std::endl;
                int op = 0;
                std::cin >> op;
                getchar();

                switch(op){
                    case 1:
                        std::cout << "Digite o novo nome do livro: ";
                        std::getline(std::cin, nvLivro);
                        emprestimo.setLivros(nvLivro);
                        std::cout << std::endl;
                        std::cout << "----Nome do livro alterado com sucesso----" << std::endl;
                        return true;

                    case 2:
                        std::cout << "Digite o novo nome do cliente: ";
                        std::getline(std::cin, nvNome);
                        emprestimo.setNomes(nvNome);
                        std::cout << std::endl;
                        std::cout << "----Nome do cliente alterado com sucesso----" << std::endl;
                        return true;

                    case 3:
                        std::cout << "Digite o novo prazo: ";
                        std::cin >> nvPrazo;
                        getchar();
                        emprestimo.setPrazo(nvPrazo);
                        std::cout << std::endl;
                        std::cout << "----Prazo alterado com sucesso----" << std::endl;
                        return true;

                    case 4:
                        return true;
                }
            }else if(emprestimo2.getLivros().find(procuraL) != std::string::npos){
                std::cout << std::endl;
                std::cout << "Livro: " << emprestimo2.getLivros() << std::endl;
                std::cout << "Nome: " << emprestimo2.getNomes() << std::endl;

                if(emprestimo2.getPrazo() >= 0){
                    std::cout << "Prazo de devolução: " << emprestimo2.getPrazo() << " dias" << std::endl;
                    std::cout << std::endl;
                }else{
                    std::cout << std::fixed << std::setprecision(2);
                    std::cout << "Prazo de devolução expirado a " << emprestimo2.getPrazo() * (-1) << " dia(s)" << std::endl;
                    std::cout << "Multa a ser paga: R$" << emprestimo2.getPrazo() * (-1) * 2.0 << std::endl;
                }
                std:: cout << std::endl;

                std::cout << "-------O que deseja alterar?-------" << std::endl;
                std::cout << "1 - Nome do livro\n"
                            "2 - Nome do cliente\n"
                            "3 - Prazo de entrega\n"
                            "4 - Cancelar alteração" << std::endl;
                int op = 0;
                std::cin >> op;
                getchar();

                switch(op){
                    case 1:
                        std::cout << "Digite o novo nome do livro: ";
                        std::getline(std::cin, nvLivro);
                        emprestimo2.setLivros(nvLivro);
                        std::cout << std::endl;
                        std::cout << "----Nome do livro alterado com sucesso----" << std::endl;
                        return true;

                    case 2:
                        std::cout << "Digite o novo nome do cliente: ";
                        std::getline(std::cin, nvNome);
                        emprestimo2.setNomes(nvNome);
                        std::cout << std::endl;
                        std::cout << "----Nome do cliente alterado com sucesso----" << std::endl;
                        return true;

                    case 3:
                        std::cout << "Digite o novo prazo: ";
                        std::cin >> nvPrazo;
                        getchar();
                        emprestimo2.setPrazo(nvPrazo);
                        std::cout << std::endl;
                        std::cout << "----Prazo alterado com sucesso----" << std::endl;
                        return true;

                    case 4:
                        return true;
                }
            }
        }

        if(alterar == -1){
            return false;
        }

}

int ClienteVip::opcaoEditar(){
    int op = 0;

  while(1){
    std::cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n"
                "          Menu de Edição da Biblioteca!\n"
                "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << std::endl;
    std::cout << std::endl;
    std::cout << "-------Edição de empréstimos-------\n" << std::endl;
    std::cout << "1 - Excluir um empréstimo\n"
                 "2 - Alterar um empréstimo\n"
                 "3 - Voltar ao Menu Principal" << std::endl;
    std::cin >> op;
    getchar();
    return op;
  }

}
}
