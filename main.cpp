#include <bits/stdc++.h>
using namespace std;

void cadastrar()
{
    if (FILE * fd = fopen("contas.csv", "r"))
    {
        cout << "arquivo existente";
    } else {
        ofstream contas("contas.csv");
    }

}

int main()
{
    string conta;
    cout << "Possui conta? (s/n)";
    cin >> conta;
    if (conta == "s" or conta == "sim") {
        cout << "hi";
    } else {
        cadastrar();
    }
    return 0;
}