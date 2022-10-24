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
    unordered_map <int, vector <string>> *combinacoesProcessos){

    unordered_map <int, vector<string>>:: iterator it_Processo;
    unordered_map <int, vector <string>>:: iterator itCombinacaoProcessos;

    Combinacao c;

    for(it_Processo = processoReduzido->begin(); it_Processo != processoReduzido->end(); ++it_Processo){
        int aux = 1;
        int perm[TAM] = { 0 };
        
        while(aux <= it_Processo->second.size()){
            c.Combinacoes(it_Processo->second, perm, 0, it_Processo->second.size(), aux);
            aux++;
        }

        combinacoesProcessos->insert({it_Processo->first, c.str});
    }

}

void Kernel::intersecaoCombinacao(
    unordered_map <string, vector<int>> *item,
    unordered_map <string, vector<int>> *classe,
    unordered_map <int, vector <string>> *combinacoesProcessos){

    unordered_map <int, vector <string>>:: iterator itCombinacaoProcessos;
    unordered_map <string, vector<int>>:: iterator itClasse;
    unordered_map <string, int>:: iterator itClasse2;

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
    
        for(auto comb: itCombinacaoProcessos->second){
            verificaCache(comb, item, classe, &itRes->second); 
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

void Kernel::verificaCache(string combinacao, 
        unordered_map <string, vector<int>> *item,
        unordered_map <string, vector<int>> *classe,
        unordered_map <string, int> *vectorAux){
    
    int colum = 1;

    stringstream sstream(combinacao);
    string token;

    vector <string> t;

    vector <int> v1;
    vector <int> v2;
    vector <int> vRes;

    unordered_map <string, unordered_map <string, int>>::iterator itCache;
    unordered_map <string, int>:: iterator itCache2;
    
    unordered_map <string, int>::iterator itVec;
    unordered_map <string, int>::iterator itVec2;

    unordered_map <string, vector<int>>:: iterator itItem;
    unordered_map <string, int>:: iterator itClasse2;

    unordered_map <int, vector<string>>:: iterator itr;
    
    itCache = cache.find(combinacao);
    
    if(itCache != cache.end()){
        for(itVec = itCache->second.begin(); itVec != itCache->second.end(); ++itVec){
            itVec2 = vectorAux->find(itVec->first);
            itVec2->second += itVec->second;
        }
    } else{
        unordered_map <string, int> classeAux;
        unordered_map <string, vector<int>>::iterator itClasse;
        
        for(itClasse = classe->begin(); itClasse != classe->end(); ++itClasse){
            classeAux.insert({itClasse->first, 0});
        }

        itCache = cache.find(combinacao);

        while (getline(sstream, token, '_')){
            t.push_back(token);
        }
        if(t.size() == 1){
            itItem = item->find(t.front());
                
            if(itItem != item->end()){
                v1.clear();
                v1 = itItem->second;

                for(itClasse = classe->begin(); itClasse != classe->end(); ++itClasse){
                    vRes.clear();
                    v2.clear();

                    v2 = itClasse->second;
                    intersecaoGeral(v1, v2, &vRes);
                    
                    
                    itClasse2 = vectorAux->find(itClasse->first);
                    if(itClasse2 != vectorAux->end()){
                        itClasse2->second = itClasse2->second + vRes.size();
                    } 
                }
            }

            v1.clear();
        }
    }
}