#include <bits/stdc++.h>
using namespace std;

void cadastrar()
{
    if (FILE *fd = fopen("contas.csv", "r")) // se existe "contas.csv" não criará um arquivo encima do já existente
    {
        cout << "arquivo existente";
        ofstream contas;
        contas.open("contas.csv", ios_base::app);
        string user, password;
        cout << "Digite o usuário";
        cin >> user;
        cout << "Digite a senha";
        cin >> password;
        contas << user << "," << password << endl;
        contas.close();
    }
    else
    {
        ofstream contas("contas.csv");
        string user, password;
        cout << "Digite o usuário";
        cin >> user;
        cout << "Digite a senha";
        cin >> password;
        contas << "user" << "," << "password" << endl;
        contas << user << "," << password << endl;
        contas.close();
    }
}

int main()
{
    string conta;
    cout << "Possui conta? (s/n)";
    cin >> conta;
    if (conta == "s" or conta == "sim")
    {
        cout << "hi";
    }
    else
    {
        cadastrar();
    }
    return 0;
}