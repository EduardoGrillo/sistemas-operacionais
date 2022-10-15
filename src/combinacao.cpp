#include "combinacao.hpp"

Combinacao::Combinacao(){}
Combinacao::~Combinacao(){}

void Combinacao::Combinacoes(vector<string> vec, int perm[], int index, int n, int k) {
	static int count = 0;
    vector <string> aux;

	if (count == k) {
		for (int i = 0; i < n; i++){
            if (perm[i] == 1){
                aux.push_back(vec.at(i));
            }
        }
        this->vecString.push_back(aux);

	} else if ((n - index) >= (k - count)) {

		perm[index] = 1;
		count++;
		Combinacoes(vec, perm, index + 1, n, k);

		perm[index] = 0;
		count--;
		Combinacoes(vec, perm, index + 1, n, k);

	}
}