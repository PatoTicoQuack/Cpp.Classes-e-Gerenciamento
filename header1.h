#ifndef COISASBASICAS_H
#define COISASBASICAS_H

using namespace std;

class pessoa{
    public:
        string nome;
};  

class pessoaFisica: public pessoa{ //INICIO DO PRIMEIRO EXERCICIO
    public:
        void setFisica(string a, string b){
            cpf = a;
            nome = b;
        }
        string getCPF(){
            return cpf;
        }
        string getNome(){
            return nome;
        }
    private:
        string cpf;
        string nome;
};

class Funcionario: public pessoaFisica{ // INICIO DO SEGUNDO EXERCICIO
    public:
        int calculaSalarioBruto();
        void setFuncionario(string a, string e, float b, int c, int d){
            this->nome = a;
            this->matricula = e;
            this->salarioBase = b;            
            this->horasTrabMensal = c;
            this->metaHorarioMensal = d;
        }
        string getMatricula(){
            return this->matricula;
        }
        int getSalarioBase(){
            return this->salarioBase;
        }
        int getMetaHorasMensal(){
            return this->metaHorarioMensal;
        }
        string getHorasTrabMensal(){
            if (horasTrabMensal >= 0 && horasTrabMensal <= 220){
                return std::to_string(horasTrabMensal); //convertendo as horas trabalhadas de int pra string pra fazer o retorno
            }else{
                return "erro";
            }
        }
        string getNome(){
            return nome;
        }
        virtual float calculaBonus();
    private:
        string matricula;
        string nome;
        int salarioBase;
        int metaHorarioMensal;
        int horasTrabMensal;
};

int Funcionario:: calculaSalarioBruto(){
    int retorno1;
    retorno1 = (salarioBase * horasTrabMensal)/(metaHorarioMensal + calculaBonus());
    if (retorno1 < 0){
        return 0;
    }else{
        return retorno1;
    }
}

float Funcionario:: calculaBonus(){
    return 0;
}

class gerente: public Funcionario{ // INICIO DO TERCEIRO EXERCICIO
    public:
        void autenticar(string senhaDigitada);
        void mudarSenha(string senhaTroca);
        float calculaBonus() override; // Polimorfismo
        void horasTrab();

        void setGerente(int a, int b, string c){
            this->quantFunc = a;
            this->quantHorasTrab = b;
            this->senhaCriada = c;
        }
        void setSenha(string d){
            this->senhaCriada = d;
        }
        int getQuantFunc(){
            return this->quantFunc;
        }
        int getQuantHorasTrab(){
            return this->quantHorasTrab;
        }
        string getSenha(){
            return this->senhaCriada;
        }
        void setHorasExtra(int z){
            this->horasExtra = z;
        }
        int getHorasExtra(){
            return this->horasExtra;
        }
    private:
        int quantFunc;
        int quantHorasTrab;
        int horasExtra;
        string senhaCriada;
};

void gerente::autenticar(string senhaDigitada){
    if (senhaDigitada == getSenha()){
        cout << "Autenticado" << endl;
        cout << "Quantidade de funcionarios: " << getQuantFunc() << " - " << "Horas trabalhadas: " << getQuantHorasTrab() << endl;
    }else{
        cout << "Erro" << endl;
    }
}

void gerente::mudarSenha(string senhaTroca){
    if (senhaTroca == getSenha()){
        cout << "Senha certa, digite a nova senha: " << endl;
        cin >> (senhaTroca);
        setSenha(senhaTroca);
    }else{
        cout << "Senha errada" << endl;
    }
}

void gerente::horasTrab(){
    int horasRest;
    if (getQuantHorasTrab() > 220){
        horasRest = getQuantHorasTrab() - 220;
        cout << "Horas extras: " << horasRest << endl; 
    }else{
        horasRest = 0;
        cout << "Sem horas extras" << endl;
    }
    setHorasExtra(horasRest);
}

float gerente::calculaBonus(){
    float bonus;

    if(bonus > getSalarioBase() * 0.3){
        if (getHorasExtra() > 0){
            bonus = (getSalarioBase() * 0.3) + ((getSalarioBase() * 1.5)/getHorasExtra());
        }else{
            bonus = getSalarioBase() * 0.3;
        }
    }else{
        if (getHorasExtra() > 0){
            bonus = (getSalarioBase() * (0.005 * getHorasExtra())) + ((getSalarioBase() * 1.5)/getHorasExtra());
        }else{
            bonus = getSalarioBase() * (0.005 * getHorasExtra());
        }
    }
    return bonus;
}

class Estagiario: public Funcionario{ //INICIO DO QUARTO EXERCICIO
    public:
        int calculoBonus();
        void setEstagiario(int a, int b){
            mesesRestantes = a;
            qualificacaoEstagio = b;
        }
        int getMesesRestantes(){
            return mesesRestantes;
        }
        int getQualificacaoEstagio(){
            return qualificacaoEstagio;
        }
    private:
        int mesesRestantes;
        int qualificacaoEstagio;
};

int Estagiario:: calculoBonus(){
    int bonus;
    if (getQualificacaoEstagio() == 1){
        bonus = (getSalarioBase() * 0.05)/getMesesRestantes();
    }else if (getQualificacaoEstagio() == 2){
        bonus = (getSalarioBase() * 0.10)/getMesesRestantes();   
    }
    return bonus;
}

class Cliente: public pessoaFisica{ //INICIO DO QUINTO EXERCICIO
    public: 
        void setCliente(string a, string b, string c){
            nome = a;
            telefone = b;
            endereco = c;
        }
        string getEndereco(){
            return endereco;
        }
        string getTelefone(){
            return telefone;
        }
        string getNome(){
            return nome;
        }
    private:
        string nome;
        string endereco;
        string telefone;
};

class pessoaJuridica: public pessoa{ //PRIMEIRO EXERCICIO
    public:
        void setJuridica(string c, string d, string e){
            cnpj = c;
            razao = d;
            nomeFake = e;
        }
        string getCNPJ(){
            return cnpj;
        }
        string getRazao(){
            return razao;
        }
        string getNomeFake(){
            return nomeFake;
        }
    private:
        string cnpj;
        string razao;
        string nomeFake;
};

class Empresa: public pessoaJuridica{ //INICIO SEXTO EXERCICIO
    public: 
        Funcionario* funcionario1 = new Funcionario[100];
        Cliente* cliente1 = new Cliente[100];
        void setQuantFuncionarios(string a, string b, float c, int d, int e);
        void setQuantClientes(string nome, string telefone, string endereco);
        void getFuncionarios(int opcao);
        void getClientes(int opcao);
        void calcularFolhaDePagamento();
    private:
        int quantClientes = 0;
        int quantFuncionarios = 0;
};

void Empresa:: setQuantFuncionarios(string a, string b, float c, int d, int e){
    quantFuncionarios += 1;
    string matricula;
    string nome;
    float salarioBruto;
    int metaHorarioMensal;
    int horasTrabMensal;

    nome = a;
    matricula = b;
    salarioBruto = c;
    horasTrabMensal = d;
    metaHorarioMensal = e;

    funcionario1[quantFuncionarios-1].setFuncionario(nome,matricula,salarioBruto,horasTrabMensal,metaHorarioMensal);
    // Reaproveitando da classe pai as funcoes de setar
}

void Empresa:: getFuncionarios(int opcao){
    int i;
    if (opcao != 1){
        cout << "Nome do funcionario, matricula e salario bruto: " << funcionario1[quantFuncionarios-1].getNome() << " - " << funcionario1[quantFuncionarios-1].getMatricula() << " - " << funcionario1[quantFuncionarios-1].calculaSalarioBruto() << endl;
    }

    for (i = 0; i < quantFuncionarios; i++){
        cout << "Nome do funcionario " << i+1 << ", matricula e salario bruto: " << funcionario1[i].getNome() << " - " << funcionario1[i].getMatricula() << " - " << funcionario1[i].calculaSalarioBruto() << endl; 
    }
}

void Empresa:: calcularFolhaDePagamento(){
    float salarioTotal = 0.0;
    for (int i = 0; i < quantFuncionarios ; i++){
        cout << "Salario do funcionario " << i << " = " << funcionario1[i].calculaSalarioBruto() << endl;
        salarioTotal += funcionario1[i].calculaSalarioBruto();
    }
    cout << "Salario total de funcionarios: " << salarioTotal << endl;
}
 
void Empresa:: setQuantClientes(string a, string b, string c){
    quantClientes++;
    string nome, telefone, endereco;
    nome = a;
    telefone = b;
    endereco = c;

    cliente1[quantClientes - 1].setCliente(nome, telefone, endereco);
    // Reaproveitando da classe pai as funcoes de setar
}

void Empresa:: getClientes(int opcao){
    int i;
    if (opcao != 1){
        cout << "Nome, telefone e endereco do cliente: " << cliente1[quantClientes-1].getNome() << " - " << cliente1[quantClientes-1].getTelefone() << " - " << cliente1[quantClientes-1].getEndereco() << endl;
    }

    for (i = 0; i < quantClientes; i++){
        cout << "Nome, telefone e endereco do cliente " << i+1 << ": " << cliente1[i].getNome() << " - " << cliente1[i].getTelefone() << " - " << cliente1[i].getEndereco() << endl;
    }
}
#endif