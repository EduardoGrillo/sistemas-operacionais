#include "read_file.hpp"

ReadFile::ReadFile(){}

ReadFile::~ReadFile(){}

void ReadFile::leitura(string path, 
    unordered_map <string, vector<int>> *item, 
    unordered_map <string, vector<int>> *classe,
    unordered_map <int, vector<string>> *processo,
    bool controle) {

	path.insert(0, "src/arquivos/");

	ifstream myfile(path);
	string line;
    
    int contLinha = 0;

    Tokenizar t; 

	if (myfile.is_open()) {
		while (getline(myfile, line)){
            contLinha++;
            if(controle == true){
                t.tok(line, contLinha, item, classe); //chamando a classe tokenizar para fazer a tokenização
            } else {
                t.tok2(line, contLinha, processo);
            }
        }
		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo!" << endl;
}

