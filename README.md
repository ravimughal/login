# Login 

## Como Executar

- Baixe e instale o [compliador](https://osdn.net/projects/mingw/) C / C++
- Navegue até a pasta no CMD. [Como navegar?](https://medium.com/@adsonrocha/como-abrir-e-navegar-entre-pastas-com-o-prompt-de-comandos-do-windows-10-68750eae8f47)
- Compile o código
  
  ``` console
  ~/login gcc main.cpp -o main
  ```

- Execute o programa
  ``` console
  ~/login ./main
  ```

## Funcionalidades 

- Cadastro
      
  ``` console
    fazer login ou cadastro? (login/cadastro) cadastro
    Digite o usuario: RaviMughal
    Digite a senha: AmoPizza
  ```
  ``` console
    fazer login ou cadastro? (login/cadastro) cadastro
    Digite o usuario: RaviMughal
    Digite a senha: AmoPizza
    Usuario ja registrado
  ```

- Login
  ``` console
    fazer login ou cadastro? (login/cadastro) login
    LOGIN
    Digite o usuario: RaviMughal
    Digite a senha: AmoPizza
    acesso liberado
    Bem vindo(a) RaviMughal
  ```
  ``` console
    fazer login ou cadastro? (login/cadastro) login
    LOGIN
    Digite o usuario: RaviMughal
    Digite a senha: SmoPizza
    Acesso negado
  ```
