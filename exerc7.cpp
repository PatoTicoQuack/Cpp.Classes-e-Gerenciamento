#include <iostream>
#include "header1.h"

using namespace std;

int main(){
    pessoaFisica* pessoaFisica1 = new pessoaFisica();
    pessoaJuridica* pessoaJuridica1 = new pessoaJuridica();
    Funcionario* func1 = new Funcionario();
    Funcionario* func2 = new Funcionario();
    Funcionario* func3 = new Funcionario();

    pessoaFisica1->setFisica("077654587-61","Matheus Roger");
    pessoaJuridica1->setJuridica("00.394.460/0058-87","Pesarini LTDA","Roger Matheus");

    cout << "Nome: " << pessoaFisica1->getNome() << " - " << pessoaFisica1->getCPF() << endl;
    cout << "Nome: " << pessoaJuridica1->getNomeFake() << " - " << "CNPJ: " << pessoaJuridica1->getCNPJ() << " - " << "Empresa: " << pessoaJuridica1->getRazao() << endl;

    // SEGUNDO EXERCICIO

    cout << endl << "Segundo exercicio" << endl << endl;

    func1->setFuncionario("","1093",4500,170,220);
    func2->setFuncionario("","1094",5000,-1,220);
    func3->setFuncionario("","1095",5500,221,220);

    cout << "Matricula do funcionario: " << func1->getMatricula() << " - " << "Salario base e salario bruto: " << func1->getSalarioBase() << "," << func1->calculaSalarioBruto() << " - " << "Meta mensal de horas e horas trabalhas no mes: " << func1->getMetaHorasMensal() << "," << func1->getHorasTrabMensal() << endl;
    cout << endl << "TESTE DE ERRO COM HORAS TRABALHADAS MENORES QUE 0" << " - " << "Matricula do funcionario: " << func2->getMatricula() << " - " << "Salario base e salario bruto: " << func2->getSalarioBase() << "," << func2->calculaSalarioBruto() << " - " << "Meta mensal de horas e horas trabalhas no mes: " << func2->getMetaHorasMensal() << "," << func2->getHorasTrabMensal() << endl;
    cout << endl << "TESTE DE ERRO COM HORAS TRABALHADAS MAIORES QUE 220" << " - " << "Matricula do funcionario: " << func3->getMatricula() << " - " << "Salario base e salario bruto: " << func3->getSalarioBase() << "," << func3->calculaSalarioBruto() << " - " << "Meta mensal de horas e horas trabalhas no mes: " << func3->getMetaHorasMensal() << "," << func3->getHorasTrabMensal() << endl;

    // TERCEIRO EXERCICIO

    cout << endl << "Terceiro exercicio" << endl << endl;
    
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

    // QUARTO EXERCICIO

    cout << endl << "Quarto exercicio" << endl << endl;

    Estagiario* estagiario1 = new Estagiario();
    int meses, qualificacao, salario;

    cout << "Digite quantos meses restantes de contrato voce tem: " << endl;
    cin >> (meses);

    cout << "Digite '1' se voce e jovem aprendiz e '2' se voce e universitario" << endl;
    cin >> (qualificacao);

    estagiario1->setEstagiario(meses, qualificacao);

    cout << "Digite seu salario base" << endl;
    cin >> (salario);
    estagiario1->setFuncionario("0","0",salario,0,0);

    cout << "Qualificacao do estagio e meses restantes de contrato: ";
    if (estagiario1->getQualificacaoEstagio() == 1){
        cout << "Jovem Aprendiz " << estagiario1->getMesesRestantes() << " meses restantes" << endl;
    }else if (estagiario1->getQualificacaoEstagio() == 0){
        cout << "Universitario " << estagiario1->getMesesRestantes() << " meses restantes" << endl;
    }

    cout << "Bonus salarial e a soma do salario: " << estagiario1->calculoBonus() << " - " << estagiario1->calculoBonus() + estagiario1->getSalarioBase() << endl;

    // QUINTO EXERCICIO

    cout << endl << "Quinto exercicio" << endl << endl;

    Cliente* cliente1 = new Cliente();

    cliente1->setCliente("","Av. Carlos Gomes","44 99999-1644");

    cout << "Endereco e telefone do cliente: " << cliente1->getEndereco() << " - " << cliente1->getTelefone() << endl; 

    // SEXTO EXERCICIO

    cout << endl << "Sexto exercicio" << endl << endl;

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
            goto add;
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