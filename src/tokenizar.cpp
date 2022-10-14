#include "tokenizar.hpp"

Tokenizar::Tokenizar(){}

Tokenizar::~Tokenizar(){}

void Tokenizar::tok(string text, int contLinha) {
	char del = ',';
    int colum = 1;

	stringstream sstream(text);
	string token;

    cout << contLinha << endl;

	while (getline(sstream, token, del)){
        if(colum < 5)
            token.append(",").append(to_string(colum++)); //converter a coluna em string e adicionar no token
        cout << token << endl;
    }

    cout << endl;
}