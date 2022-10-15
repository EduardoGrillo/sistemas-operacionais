#ifndef TOKENIZAR_H
#define TOKENIZAR_H

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Tokenizar{
    private:

    public:

    Tokenizar();
    ~Tokenizar();

    void tok(string text, int contLinha, 
        unordered_map <string, vector<int>> *item, 
        unordered_map <string, vector<int>> *classe);

    void tok2(string text, int contLinha, 
        unordered_map <int, vector<string>> *processo);
};

#endif