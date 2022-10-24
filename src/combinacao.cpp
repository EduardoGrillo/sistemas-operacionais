#include "combinacao.hpp"

Combinacao::Combinacao(){}
Combinacao::~Combinacao(){}

void Combinacao::Combinacoes(vector<string> vec, int perm[], int index, int n, int k) {
	static int count = 0;
    vector <string> aux;

	aux.clear();

	if (count == k) {
		string s = "";

		for (int i = 0; i < n; i++){
            if (perm[i] == 1){
                aux.push_back(vec.at(i));
				s.append(vec.at(i));
            }
        }
		cout << s << endl;
        //this->vecString.push_back(aux);
		this->str.push_back(s);

	} else if ((n - index) >= (k - count)) {

		perm[index] = 1;
		count++;
		Combinacoes(vec, perm, index + 1, n, k);

		perm[index] = 0;
		count--;
		Combinacoes(vec, perm, index + 1, n, k);

	}
}