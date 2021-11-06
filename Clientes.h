#pragma once
#include "Emprestimo.h"

class Clientes
{
    public:
        Clientes();
        virtual ~Clientes();

        virtual void AdicionaEmprestimo(Emprestimo emp) = 0;
        virtual void setEmp(Emprestimo emp) = 0;
        virtual Emprestimo getEmp() = 0;
        virtual void AtualizaPrazo() = 0;
        virtual void MostrarLista() = 0;
        virtual int ExcluirEmprestimo(std::string procuraL, std::string procuraN) = 0;
        virtual bool AlterarEmprestimo(std::string procuraL, std::string procuraN) = 0;
        virtual int opcaoEditar() = 0;


    protected:


    private:

};
