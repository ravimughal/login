#include <bits/stdc++.h>
using namespace std;

void cadastrar(), login(), verificar_login_user(), verificar_senha();
int main();

//
//
int verificar_cadastro(string user)
{
    ifstream contas("contas.csv");
    string name, pass, linha;

    while (getline(contas, linha, ','))
    {
        getline(contas, name, ',');
        getline(contas, pass, '\n');

        if (user == name)
        {
            return 1;
        }
    }
    return 0;
}

//
//

int verificar_login_user(string user)
{
    ifstream contas("contas.csv");
    string name, pass, linha;
    int row = 0;

    while (getline(contas, linha, ','))
    {
        getline(contas, name, ',');
        getline(contas, pass, '\n');

        if (user == name)
        {
            return row;
        }
        row++;
    }
    return -1;
}

//
//

void verificar_senha(string password, int row, string user)
{
    ifstream contas("contas.csv");
    string name, pass, linha;
    int rr = 0;
    while (getline(contas, linha, ','))
    {
        getline(contas, name, ',');
        getline(contas, pass, '\n');

        if (rr == row && password == pass && rr != 0)
        {
            cout << "acesso liberado" << endl;
            cout << "Bem vindo(a) " << user;
            return;
        }
        rr++;
    }

    cout << "Acesso negado" << endl;
    main();
}

//
//

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
            int id = reinterpret_cast<int>(&user);
            if (verificar_cadastro(user) != 1)
            {
                contas << id << ',' << user << ',' << password << endl;
            }
            else
            {
                cout << "Usuario ja registrado" << endl;
            }
            contas.close();
            main();
            return;
        }
        else
        {
            ofstream contas("contas.csv");
            string user, password;
            cout << "Digite o usuario: ";
            cin >> user;
            cout << "Digite a senha: ";
            cin >> password;
            int id = reinterpret_cast<int>(&user);

            contas << "id"
                   << ","
                   << "user"
                   << ','
                   << "password" << endl;
            if (verificar_cadastro(user) != 1)
            {
                contas << id << ',' << user << ',' << password << endl;
            }
            else
            {
                cout << "usuario ja registrado" << endl;
            }
            contas.close();
            main();
            return;
        }
    }
}

//
//

void login()
{
    cout << "LOGIN" << endl;
    string user, password;
    cout << "Digite o usuario: ";
    cin >> user;
    verificar_login_user(user);
    cout << "Digite a senha: ";
    cin >> password;
    auto row = verificar_login_user(user);
    if (row == -1)
    {
        cout << "Usuario nao cadastrado";
        return;
    }
    verificar_senha(password, row, user);
}

//
//

int main()
{
    string conta;
    while (true)
    {
        cout << "fazer login ou cadastro? (login/cadastro) ";
        cin >> conta;
        if (conta == "login")
        {
            login();
            break;
        }
        else if (conta == "cadastro")
        {
            cadastrar();
            break;
        }
    }

    return 0;
}