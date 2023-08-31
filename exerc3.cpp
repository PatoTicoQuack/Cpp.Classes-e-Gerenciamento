#include <iostream>
#include "header1.h"

using namespace std;

int main(){
    int quantFunc, quantHorasTrab;
    cout << "Digite a quantidade de funcionarios, as horas trabalhas no mes e crie uma senha (respectivamente)" << endl;
    string senha, criarsenha;;
    cin >> (quantFunc);
    cin >> (quantHorasTrab);
    cin >> (criarsenha);

    cout << "Insira a sua senha novamente para entrar na conta de gerencia" << endl;
    cin >> (senha);

    gerente* gerente1 = new gerente();
    gerente1->setGerente(quantFunc, quantHorasTrab, criarsenha);
    gerente1->autenticar(senha);

    cout << "Insira a sua senha para a verificao de troca: " << endl;
    cin >> (senha);
    gerente1->mudarSenha(senha);

    gerente1->horasTrab();

    int salarioBase;
    cout << "Digite seu salario base para o calculo: " << endl;
    cin >> (salarioBase);
    gerente1->setFuncionario("0","0",salarioBase,0,0);
    cout << "Valor do bonus e a soma com o salario base: " << gerente1->calculaBonus() << " - " << gerente1->calculaBonus() + gerente1->getSalarioBase() <<endl;
}
