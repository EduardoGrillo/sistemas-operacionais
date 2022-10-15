#include <iostream>

#include "read_file.hpp"
#include "kernel.hpp"

using namespace std;

int main(){
    ReadFile r;
    Tokenizar t;
    Kernel k;

    unordered_map <string, vector<int>> item;  
    unordered_map <string, vector<int>> classe;  
    unordered_map <string, vector<int>>:: iterator it;

    unordered_map <int, vector<string>> processo;
    unordered_map <int, vector<string>> processoReduzido;
    unordered_map <int, vector<string>>:: iterator it2;
    
    unordered_map <int, vector<vector <string>>> combinacoesProcessos;

    int op = 1;

    string x; //vai receber o path do read_file

    do{
        cout << "[1]- Ler e armazenar D.csv" << endl;
        cout << "[2]- Ler e armazenar T.csv" << endl;
        cout << "[3]- Sair" << endl;
        cin >> op;

        // switch (op){
        // case 1:
        //     x.assign("D.csv");
        //     r.leitura(x, &item, &classe, &processo, true);
            
        //     break;
        
        //case 2:
            x.assign("D.csv");
            r.leitura(x, &item, &classe, &processo, true);
            x.assign("T.csv");
            r.leitura(x, &item, &classe, &processo, false);
            k.reduzirProcesso(&item, &processo, &processoReduzido);
            k.combinacaoReduzida(&processoReduzido, &combinacoesProcessos);
            k.intersecaoCombinacao(&item, &classe, &combinacoesProcessos);
            
            //break;
        
        // case 3:
        //     return 0;
        //     break;

        // default:
        //     break;
        //}

    cout << endl;

    } while(op != 3);
}