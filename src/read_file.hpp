#ifndef READ_FILE_H
#define READ_FILE_H 

#include <iostream>
#include <fstream>

#include <unordered_map>
#include <vector>

#include "tokenizar.hpp"

using namespace std;

class ReadFile{
    private:

    public:
    
    ReadFile();
    ~ReadFile();

    void leitura(string path, unordered_map <string, vector<int>> *umap, bool controle);
};

#endif