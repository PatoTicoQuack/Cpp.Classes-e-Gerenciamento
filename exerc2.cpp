#include <iostream>
#include "header1.h"

using namespace std;

int main(){
    Funcionario* func1 = new Funcionario();
    Funcionario* func2 = new Funcionario();
    Funcionario* func3 = new Funcionario();

    func1->setFuncionario("","1093",4500,170,220);
    func2->setFuncionario("","1094",5000,-1,220);
    func3->setFuncionario("","1095",5500,221,220);

    cout << "Matricula do funcionario: " << func1->getMatricula() << " - " << "Salario base e salario bruto: " << func1->getSalarioBase() << "," << func1->calculaSalarioBruto() << " - " << "Meta mensal de horas e horas trabalhas no mes: " << func1->getMetaHorasMensal() << "," << func1->getHorasTrabMensal() << endl;
    cout << endl << "TESTE DE ERRO COM HORAS TRABALHADAS MENORES QUE 0" << " - " << "Matricula do funcionario: " << func2->getMatricula() << " - " << "Salario base e salario bruto: " << func2->getSalarioBase() << "," << func2->calculaSalarioBruto() << " - " << "Meta mensal de horas e horas trabalhas no mes: " << func2->getMetaHorasMensal() << "," << func2->getHorasTrabMensal() << endl;
    cout << endl << "TESTE DE ERRO COM HORAS TRABALHADAS MAIORES QUE 220" << " - " << "Matricula do funcionario: " << func3->getMatricula() << " - " << "Salario base e salario bruto: " << func3->getSalarioBase() << "," << func3->calculaSalarioBruto() << " - " << "Meta mensal de horas e horas trabalhas no mes: " << func3->getMetaHorasMensal() << "," << func3->getHorasTrabMensal() << endl;
}