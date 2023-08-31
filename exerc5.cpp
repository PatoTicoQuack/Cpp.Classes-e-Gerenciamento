#include <iostream> 
#include "header1.h"

using namespace std;

int main(){
    Cliente* cliente1 = new Cliente();

    cliente1->setCliente("","Av. Carlos Gomes","44 99999-1644");

    cout << "Endereco e telefone do cliente: " << cliente1->getEndereco() << " - " << cliente1->getTelefone() << endl; 
}