#include <iostream>
#include "header1.h"

using namespace std;

int main(){
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
}