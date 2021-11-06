#include "Emprestimo.h"
#include "Clientes.h"
#include "ClienteVip.h"
#include "ClienteNormal.h"
#include "Controle.h"
#include <iostream>
#include <locale.h>
#include <iomanip>
#include <vector>

int main(){
    Controle ctl;
    std::string livros, nomes;
    Emprestimo emp;
    std::vector<Clientes*> cl;
    Clientes *cls;
    int opcao = 0;
    int loop = 1;
    int vip;

    std::string procuraL, procuraN;
    int valorEdita;

    setlocale(LC_ALL, "Portuguese");
    while(1){
        ctl.menuPrincipal();

        std::cin >> opcao;
        getchar();

        switch(opcao){
            case 1:
                std::cout << "calma�\n\n";
                system("pause");
                system("cls");
                break;

            case 2:
                //adicionar um emprestimo
                system("cls");
                std::cout << "\nO cliente possui cart�o VIP?\n"
                            "1 - Sim\n"
                            "2 - N�o\n";
                std::cin >> vip;
                getchar();

                if(vip == 1){
                    cls = new Cliente::ClienteVip();

                }else{
                    cls = new Cliente::ClienteNormal();

                }

                std::cout << "Nome do cliente: ";
                std::getline(std::cin, nomes);

                std::cout << std::endl;
                std::cout << "Nome do livro: ";
                std::getline(std::cin, livros);

                emp = Emprestimo(livros, nomes);
                cls->AdicionaEmprestimo(emp);
                if(vip == 1){
                    std::cout << "\nDeseja adicionar outro empr�stimo?\n"
                                "1 - Sim\n"
                                "2 - N�o\n";
                    std::cin >> vip;
                    getchar();

                    if(vip == 1){
                        std::cout << std::endl;
                        std::cout << "Nome do livro: ";
                        std::getline(std::cin, livros);
                        emp = Emprestimo(livros, nomes);
                        cls->AdicionaEmprestimo(emp);
                        system("pause");
                        system("cls");
                    } else {
                        system("cls");
                    }
                } else {
                    system("pause");
                    system("cls");
                }
                cl.push_back(cls);
                break;

            case 3:
                //atualiza prazos

                for(int i = 0; i < cl.size(); i++){
                    cl[i]->AtualizaPrazo();
                }
                std::cout << std::endl;
                std::cout << "----Prazos atualizados com sucesso----\n" << std::endl;
                system("pause");
                system("cls");
                break;

            case 4:
                //Mostra lista
                system("cls");
                std::cout << std::endl;
                std::cout << "-------Lista de empr�stimos-------" << std::endl;
                std::cout << std::endl;
                for(int i = 0; i < cl.size(); i++){
                    cl[i]->MostrarLista();
                }
                std::cout << std::endl;
                system("pause");
                system("cls");
                break;

            case 5:
                system("cls");
                loop = 1;
                while(loop){
                    switch(cl[0]->opcaoEditar()){
                        case 1:
                            std::cout << "Digite o nome do cliente: ";
                            std::getline(std::cin, procuraN);
                            std::cout << "Digite o nome do livro: ";
                            std::getline(std::cin, procuraL);

                            valorEdita = 0;
                            for(int i = 0; i < cl.size(); i++){
                                valorEdita = cl[i]->ExcluirEmprestimo(procuraL, procuraN);
                                if(valorEdita == 1){
                                    cl.erase(cl.begin()+i);
                                    std::cout << std::endl;
                                    std::cout << "----Empr�stimo exclu�do com sucesso----" << std::endl;
                                    break;
                                }
                                if(valorEdita == 2){
                                    break;
                                }
                                if(cl.size() - i == 1){
                                    std::cout << "Empr�stimo n�o encontrado" << std::endl;
                                }
                            }
                            system("pause");
                            system("cls");
                            break;

                        case 2:

                            std::cout << "Digite o nome do cliente: ";
                            std::getline(std::cin, procuraN);
                            std::cout << "Digite o nome do livro: ";
                            std::getline(std::cin, procuraL);

                            for(int i = 0; i < cl.size(); i++){
                                if(cl[i]->AlterarEmprestimo(procuraL, procuraN) == true)
                                    break;
                                if(cl.size() - i == 1){
                                    std::cout << "Empr�stimo n�o encontrado\n" << std::endl;
                                }
                            }
                            system("pause");
                            system("cls");
                            break;

                        case 3:
                            loop = 0;
                            system("cls");
                            break;

                        default:
                            std::cout << "*****Op��o inv�lida*****\n" << std::endl;
                            system("pause");
                            system("cls");
                    }
                }
            break;

            case 6:
                for(int i = 0; i < cl.size(); i++){
                    delete cl[i];
                }
                cl.clear();

                std::cout << "At� a pr�xima!!!\n";
                return 0;

            default:
                std::cout << "*****Op��o inv�lida*****\n" << std::endl;
                system("pause");
                system("cls");
        }
    }
}
