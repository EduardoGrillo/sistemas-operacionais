#include "read_file.hpp"

ReadFile::ReadFile(){}

ReadFile::~ReadFile(){}

void ReadFile::leitura(string path, unordered_map <string, vector<int>> *umap, bool controle) {
	path.insert(0, "src/arquivos/");

	ifstream myfile(path);
	string line;
    
    int contLinha = 0;

    Tokenizar t; 

	if (myfile.is_open()) {
		while (getline(myfile, line)){
            if(controle == true){
                contLinha++;
                t.tok(line, contLinha); //chamando a classe tokenizar para fazer a tokenização
            } 
        }
		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo!" << endl;
}

