#include <bits/stdc++.h>
using namespace std;

void cadastrar(), login(), verificar_login_user(), verificar_senha();

//
//
int verificar_cadastro(string user)
{
    ifstream contas("contas.csv");
    string name, pass, linha;
    int rr= 0;
    
    while (getline(contas, linha, ','))
    {
        getline(contas,name,',');
        getline(contas,pass, '\n');

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
            }
            else
            {
                all_users += " ";
                break;
            }
        }
        for (int i = 0; i < all_users.length(); i++)
        {
            if (all_users[i] != ' ')
            {
                act_user += all_users[i];
            }
            else
            {
                if (act_user == user)
                {
                    // cout << "\n\nusuario encontrado\n\n";
                    user_verification = false;
                    return rows;
                }
                act_user = "";
            }
        }
    }
    cout << "usuario nao encontrado" << endl;

    while (true)
    {
        string a;
        cout << "cadastrar ou tentar login novamente? (cadastrar/login) ";
        cin >> a;

        if (a == "cadastrar")
        {
            cadastrar();
            return 1;
        }
        else if (a == "login")
        {
            login();
            return 1;
        }
    }
}

//
//

void verificar_senha(string password, int row)
{
    ifstream contas("contas.csv");

    bool found_password = false;

    string name;
    string pass;
    string line = "";
    std::vector<std::string> record;
    int cont = 0;
    while (getline(contas, line, '\n') && !found_password)
    {
        getline(contas, name, ',');
        getline(contas, pass, '\n');
        record.push_back(name);
        record.push_back(pass);
        cont++;
    }

    cout << cont;

    for (int i = 0; i < 3; i++)
    {
        cout << record[i];
    }
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
            } else 
            {
                cout << "Usuario ja registrado";
            }
            contas.close();
            login();
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

            contas <<"id" << "," <<"user"
                   << ','
                   << "password" << endl;
            if (verificar_cadastro(user) != 1)
            {
                contas << id << ',' << user << ',' << password << endl;
            } else 
            {
                cout<< "usuario ja registrado";
            }
            contas.close();
            login();
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
    verificar_senha(password, row);
}

//
//

int main()
{
    string conta;
    cout << "fazer login ou cadastro? (login/cadastro) ";
    cin >> conta;
    if (conta == "login")
    {
        login();
    }
    else
    {
        cadastrar();
    }
    return 0;
}