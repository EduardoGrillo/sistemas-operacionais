#ifndef KERNEL_H
#define KERNEL_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>  

#include "combinacao.hpp"

#define TAM 5

using namespace std;

class Kernel{
    private:

    public:
    
    Kernel();
    ~Kernel();

    void reduzirProcesso( 
        unordered_map <string, vector<int>> *item,
        unordered_map <int, vector<string>> *processo,
        unordered_map <int, vector<string>> *processoReduzido);
    
    void combinacaoReduzida(
        unordered_map <int, vector<string>> *processoReduzido,
        unordered_map <int, vector<vector <string>>> *combinacoesProcessos
    );

    void intersecaoCombinacao(
        unordered_map <string, vector<int>> *item,
        unordered_map <string, vector<int>> *classe,
        unordered_map <int, vector<vector <string>>> *combinacoesProcessos
    );

    void intersecaoGeral(vector <int> v1, vector <int> v2, vector <int> *res);

};



#endif

