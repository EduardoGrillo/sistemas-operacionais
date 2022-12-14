#include <iostream>

#include "read_file.hpp"
#include "kernel.hpp"

using namespace std;

int main(){
    ReadFile r;
    Tokenizar t;
    Kernel k;

    unordered_map<string, vector<int>> item;
    unordered_map<string, vector<int>> classe;
    unordered_map<string, vector<int>>::iterator it;

    unordered_map<int, vector<string>> processo;
    unordered_map<int, vector<string>> processoReduzido;
    unordered_map<int, vector<string>>::iterator it2;

    unordered_map<int, vector<string>> combinacoesProcessos;

    string x; // vai receber o path do read_file

    x.assign("D.csv");
    r.leitura(x, &item, &classe, &processo, true);
    x.assign("T.csv");
    r.leitura(x, &item, &classe, &processo, false);
    k.reduzirProcesso(&item, &processo, &processoReduzido);
    k.combinacaoReduzida(&processoReduzido, &combinacoesProcessos);
    k.intersecaoCombinacao(&item, &classe, &combinacoesProcessos);

    return 0;
}