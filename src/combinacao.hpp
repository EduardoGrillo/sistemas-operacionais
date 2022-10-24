#ifndef COMBINACAO_H
#define COMBINACAO_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Combinacao{
    private:
        
    public:
    vector <string> str;

    Combinacao();
    ~Combinacao();

    void Combinacoes(vector<string> vec, int perm[], int index, int n, int k);

};

#endif