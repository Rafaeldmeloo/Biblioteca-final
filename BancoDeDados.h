#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class BancoDeDados{
    public:
        BancoDeDados();

        void addLivro();
        void removeLivro();
        void mostraBanco();
        void menu();
};
