#include <iostream>
#include "header1.h"

using namespace std;

int main(){
    pessoaFisica* pessoaFisica1 = new pessoaFisica();
    pessoaJuridica* pessoaJuridica1 = new pessoaJuridica();

    pessoaFisica1->setFisica("077569587-77","Matheus Roger");
    pessoaJuridica1->setJuridica("00.394.460/0058-87","Pesarini LTDA","Roger Matheus");

    cout << "Nome: " << pessoaFisica1->getNome() << " - " << pessoaFisica1->getCPF() << endl;
    cout << "Nome: " << pessoaJuridica1->getNomeFake() << " - " << "CNPJ: " << pessoaJuridica1->getCNPJ() << " - " << "Empresa: " << pessoaJuridica1->getRazao() << endl;
}