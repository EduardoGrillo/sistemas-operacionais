#include "kernel.hpp"

Kernel::Kernel(){}

Kernel::~Kernel(){}

void Kernel::reduzirProcesso( 
    unordered_map <string, vector<int>> *item,
    unordered_map <int, vector<string>> *processo,
    unordered_map <int, vector<string>> *processoReduzido){

    unordered_map <string, vector<int>>:: iterator it_Item;
    unordered_map <int, vector<string>>:: iterator it_Processo;

    vector <string> in; 

    for(it_Processo = processo->begin(); it_Processo != processo->end(); ++it_Processo){
        for(auto b: it_Processo->second){
            it_Item = item->find(b);

            if(it_Item != item->end()){
                in.push_back(b);
            }
        }
        
        if(in.size() > 0){
            processoReduzido->insert({it_Processo->first, in});
        } 
        
        in.clear();
    }

}

void Kernel::combinacaoReduzida(
    unordered_map <int, vector<string>> *processoReduzido,
    unordered_map <int, vector<vector <string>>> *combinacoesProcessos){

    unordered_map <int, vector<string>>:: iterator it_Processo;
    unordered_map <int, vector<vector <string>>>:: iterator itCombinacaoProcessos;

    Combinacao c;

    for(it_Processo = processoReduzido->begin(); it_Processo != processoReduzido->end(); ++it_Processo){
        int aux = 1;
        int perm[TAM] = { 0 };
        
        while(aux <= it_Processo->second.size()){
            c.Combinacoes(it_Processo->second, perm, 0, it_Processo->second.size(), aux);
            aux++;
        }

        combinacoesProcessos->insert({it_Processo->first, c.vecString});
    }

    // for(itCombinacaoProcessos = combinacoesProcessos->begin(); 
    //     itCombinacaoProcessos != combinacoesProcessos->end(); 
    //     ++itCombinacaoProcessos){
        
    //     cout << itCombinacaoProcessos->first << endl;
    //     for(auto vec: itCombinacaoProcessos->second){
    //         for(auto r: vec){
    //             cout << r << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}

void Kernel::intersecaoCombinacao(
    unordered_map <string, vector<int>> *item,
    unordered_map <string, vector<int>> *classe,
    unordered_map <int, vector<vector <string>>> *combinacoesProcessos){

    unordered_map <int, vector<vector <string>>>:: iterator itCombinacaoProcessos;
    unordered_map <string, vector<int>>:: iterator itClasse;
    unordered_map <string, vector<int>>:: iterator itItem;
    unordered_map <string, int>:: iterator itClasse2;

    vector <int> v1;
    vector <int> v2;
    vector <int> vRes;

    unordered_map <string, int> classeModelo;

    unordered_map <int,  unordered_map <string, int>> resultado;
    unordered_map <int,  unordered_map <string, int>>:: iterator itRes;

    for(itClasse = classe->begin(); itClasse != classe->end(); ++itClasse){
        classeModelo.insert({itClasse->first, 0});
    }

    for(itCombinacaoProcessos = combinacoesProcessos->begin(); 
        itCombinacaoProcessos != combinacoesProcessos->end(); 
        ++itCombinacaoProcessos){

        resultado.insert({itCombinacaoProcessos->first, classeModelo});
        itRes = resultado.find(itCombinacaoProcessos->first);
    
        for(auto vec: itCombinacaoProcessos->second){
            if(vec.size() == 1){
                itItem = item->find(vec.at(0));
                
                if(itItem != item->end()){
                    //v1.assign(itItem->second.begin(), itItem->second.end());
                    v1.clear();
                    v1 = itItem->second;

                    for(itClasse = classe->begin(); itClasse != classe->end(); ++itClasse){
                        //v2.assign(itClasse->second.begin(), itClasse->second.end());
                        v2 = itClasse->second;
                        intersecaoGeral(v1, v2, &vRes);
                        
                        itClasse2 = itRes->second.find(itClasse->first);
                        itClasse2->second += vRes.size();

                        //cout << vRes.size() << endl;

                        v2.clear();
                        vRes.clear();
                    }
                }
                v1.clear();
            }
        }

        for(itRes = resultado.begin(); itRes != resultado.end(); ++itRes){
            cout << itRes->first << endl;
            
            for(itClasse2 = itRes->second.begin(); itClasse2 != itRes->second.end(); ++itClasse2){
                cout << itClasse2->second <<  " ";
                cout << itClasse2->first << endl;
            }
        }
        cout << endl;
        resultado.clear();
    }
}

void Kernel::intersecaoGeral(vector <int> v1, vector <int> v2, vector <int> *res){    
    res->clear();
    res->resize(v1.size());

    vector <int>:: iterator it;

    it = set_intersection (v1.begin(), v1.end(), v2.begin(), v2.end(), res->begin());
    res->resize(it-res->begin());                      

}