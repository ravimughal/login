#include <bits/stdc++.h>
using namespace std;

void cadastrar();
void verificar(string user)
{
    int rows = 0;
    ifstream contas("contas.csv");
    string line_user, all_users, act_user;
    all_users = "";
    act_user = "";
    while (getline(contas, line_user))
    {
        rows++;
        bool user_verification = true;
        for (int i = 0; i < line_user.length(); i++)
        {
            if (line_user[i] != ',')
            {
                all_users += line_user[i];
                
            } else {
                all_users += " ";
                break;
            }
        }
        for (int i = 0; i < all_users.length(); i++)
        {
            if (all_users[i] != ' ')
            {
                act_user += all_users[i];
            } else {
                if (act_user == user)
                {
                    cout << "\n\nusuario ja cadastrado, tente novamente \n\n";
                    cadastrar();
                }
                act_user = "";
            }
        }
    }
}

void cadastrar()
{
    int i = 0;
    while (i == 0)
    {
        if (FILE *fd = fopen("contas.csv", "r")) // se existe "contas.csv" não criará um arquivo encima do já existente
        {
            ofstream contas;
            contas.open("contas.csv", ios_base::app);
            string user, password;
            cout << "Digite o usuario: ";
            cin >> user;
            cout << "Digite a senha: ";
            cin >> password;
            verificar(user);
            contas << user << "," << password << endl;
            contas.close();
        }
        else
        {
            ofstream contas("contas.csv");
            string user, password;
            cout << "Digite o usuário: ";
            cin >> user;
            cout << "Digite a senha: ";
            cin >> password;
            contas << "user" << "," << "password" << endl;
            verificar(user);
            contas << user << "," << password << endl;
            contas.close();
        }
    }
}

int main()
{
    cadastrar();
    return 0;
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