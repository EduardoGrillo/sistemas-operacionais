#include "tokenizar.hpp"

Tokenizar::Tokenizar(){}

Tokenizar::~Tokenizar(){}

void Tokenizar::tok(string text, int contLinha, 
    unordered_map <string, vector<int>> *item, 
    unordered_map <string, vector<int>> *classe) {

	char del = ',';
    int colum = 1;
    unordered_map <string, vector<int>>:: iterator itr;

	stringstream sstream(text);
	string token;

    //cout << contLinha << endl;

	while (getline(sstream, token, del)){
        if(colum < 5){
            token.append(",").append(to_string(colum++)); //converter a coluna em string e adicionar no token
            itr = item->find(token);
            
            if(itr != item->end()){ 
                itr->second.push_back(contLinha);
            } else{
                vector <int> v;
                v.push_back(contLinha);
                item->insert({token, v});
            } 

        } else{ //mudar de item para classe 
            itr = classe->find(token);
            if(itr != classe->end()){
                itr->second.push_back(contLinha);
            } else{
                vector <int> v;
                v.push_back(contLinha);
                classe->insert({token, v});
            } 
        }

        // cout << token << endl;
    }

    // cout << endl;
}

void Tokenizar::tok2(string text, int contLinha, 
    unordered_map <int, vector<string>> *processo){
    
    char del = ',';
    int colum = 1;
    unordered_map <int, vector<string>>:: iterator itr;

	stringstream sstream(text);
	string token;

	while (getline(sstream, token, del)){
        if(colum < 5){
            token.append(",").append(to_string(colum++)); //converter a coluna em string e adicionar no token
            itr = processo->find(contLinha);
            
            if(itr != processo->end()){ 
                itr->second.push_back(token);
            } else{
                vector <string> v;
                v.push_back(token);
                processo->insert({contLinha, v});
            } 
        } 
    }
}