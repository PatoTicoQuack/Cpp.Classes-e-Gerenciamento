#include <iostream>
#include "header1.h"

using namespace std;

int main(){
    Empresa* empresa1 = new Empresa();
    add:
        string a,b,f;
        float c;
        int d,e,opcao;
        cout << "Digite o nome: " << endl;
        cin >> (a);
        cout << "Digite a matricula: " << endl;
        cin >> (b);
        cout << "Digite o salario bruto: " << endl;
        cin >> (c);
        cout << "Digite as horas trabalhadas no mes: " << endl;
        cin >> (d);
        cout << "Digite a meta mensal de horas: " << endl;
        cin >> (e);
        empresa1->setQuantFuncionarios(a,b,c,d,e);

        cout << "Deseja cadastrar outro funcionario? '1' para sim e '0' para nao" << endl;
        cin >> (opcao);
        if (opcao == 1){
            goto add; // Usando goto para nao estanciar de novo
        }

        cout << "Deseja exibir todos os funcionarios registrados? '1' para sim '0' para nao" << endl;
        cin >> (opcao);
        if (opcao == 1){
            empresa1->getFuncionarios(opcao);
        }

        cout << "Deseja exibir o salario total dos funcionarios registrados? '1' para sim '0' para nao" << endl;
        cin >> (opcao);
        if (opcao == 1){
            empresa1->calcularFolhaDePagamento();
        }

        cout << "Deseja adicionar clientes? se sim '1' e nao '0'" << endl;
        cin >> (opcao);
        if (opcao == 1){
            add2:
                cout << "Digite o nome do cliente: " << endl;
                cin >> (a);
                cout << "Digite o telefone do cliente: " << endl;
                cin >> (b);
                cout << "Digite o endereco do cliente: " << endl;
                cin >> (f);
                empresa1->setQuantClientes(a,b,f);

                cout << "Deseja cadastrar outro cliente? '1' para sim e '0' para nao" << endl;
                cin >> (opcao);
                if (opcao == 1){
                    goto add2;
                }
        }
        cout << "Deseja exibir todos os clientes registrados? '1' para sim '0' para nao" << endl;
        cin >> (opcao);
        if (opcao == 1){
            empresa1->getClientes(opcao);
        }
}