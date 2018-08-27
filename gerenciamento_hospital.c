#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int total_de_pacientes = 1;
int total_de_medicos   = 1;
int total_de_prontuarios   = 1;
int total_de_planos   = 1;

typedef struct Endereco{ // Declara e Cria o Tipo Endereco
    char rua[50];
    int numero;
    char bairro[50];
    char cidade[50];
    char estado[50];
}Endereco;

typedef struct Pacientes{ // Declara e Cria o Tipo Pacientes
    long int CPF;
    char nome_paciente[50];
    char tipo_saguineo[10];
    Endereco endereco_paciente;
    long int telefone_celular;
    long int telefone_fixo;
    int situacao;
}Pacientes;

Pacientes paciente[100]; // Cria um vetor do tipo Pacientes, com 100 posicoes

typedef struct Medicos{ // Declara e Cria o Tipo Medicos
    char nome_medico[50];
    int CRM;
    char data_nascimento[50];
    char tipo_saguineo[10];
    Endereco endereco_medico;
    long int telefone_celular;
    long int telefone_fixo;
    int situacao;
}Medicos;

Medicos medico[10]; // Cria um vetor do tipo Medicos, com 100 posicoes

typedef struct Pronturario{ // Declara e Cria o Tipo Prontuario
    int id_paciente;
    int id_medico_responsavel;
    char data_interncao[50];
    char doenca_identificada[50];
    char procedimentos_executados[50];
    char medicamentos[50];
    int plano_de_saude;
}Pronturario;

Pronturario prontuario[100]; // Cria um vetor do tipo Prontuario, com 100 posicoes

typedef struct PlanoDeSaude{ // Declara e Cria o Tipo Prontuario
    int id_plano;
    char nome_plano[50];
}PlanoDeSaude;

PlanoDeSaude plano_de_saude[5]; // Cria um vetor do tipo plano de saude, com 100 posicoes

void imprime_pacientes(int id_paciente){
    /***
        Essa funcao recebe o id_paciente para imprimir todos os seus dados
    ***/
    printf("===============>Dados do Paciente ===========>\n");
    printf("CPF do paciente: %ld \n", paciente[id_paciente].CPF);
    printf("Nome do paciente: "); puts(paciente[id_paciente].nome_paciente);
    printf("Tipo Sanguineo: "); puts(paciente[id_paciente].tipo_saguineo);
    printf("Rua: ");    puts(paciente[id_paciente].endereco_paciente.rua);
    printf("Numero: %d\n",   paciente[id_paciente].endereco_paciente.numero);
    printf("Bairro: "); puts(paciente[id_paciente].endereco_paciente.bairro);
    printf("Cidade: "); puts(paciente[id_paciente].endereco_paciente.cidade);
    printf("Estado: "); puts(paciente[id_paciente].endereco_paciente.estado);
    printf("Telefone Celular: %ld \n", paciente[id_paciente].telefone_celular);
    printf("Telefone Fixo: %ld \n", paciente[id_paciente].telefone_fixo);
    printf("Situacao: %d \n", paciente[id_paciente].situacao);
    system("pause");
}

void imprime_medicos(int id_medico){
    /***
        Essa funcao recebe o id_medico para imprimir todos os seus dados
    ***/
    printf("===============>Dados do Medico ===========>\n");
    printf("CRM do medico: %d \n", medico[id_medico].CRM);
    printf("Nome do medico: "); puts(medico[id_medico].nome_medico);
    printf("Data de Nascimento: "); puts(medico[id_medico].data_nascimento);
    printf("Tipo Sanguineo: "); puts(medico[id_medico].tipo_saguineo);
    printf("Rua: ");    puts(medico[id_medico].endereco_medico.rua);
    printf("Numero: %d\n",   medico[id_medico].endereco_medico.numero);
    printf("Bairro: "); puts(medico[id_medico].endereco_medico.bairro);
    printf("Cidade: "); puts(medico[id_medico].endereco_medico.cidade);
    printf("Estado: "); puts(medico[id_medico].endereco_medico.estado);
    printf("Telefone Celular: %ld \n", medico[id_medico].telefone_celular);
    printf("Telefone Fixo: %ld \n", medico[id_medico].telefone_fixo);
    printf("Situacao: %d \n", medico[id_medico].situacao);
    system("pause");
}
int buscar_medico(char opcao_de_busca, char nome[50], int CRM){
    /***
        Essa funcao realiza dois tipos de busca: por nome do medico ou CRM do medico
        O primeiro parametro determina se o tipo da busca irá ocorrer por nome ou CRM
        O segundo parametro é o nome do medico que esta sendo procurado
        O terceiro parametro é o CRM do medico que esta sendo procurado
    ***/
    int i = 0;
    switch(opcao_de_busca){ // Realiza um Switch para verificar qual o tipo da busca: nome ou CRM
        case '1':// Caso seja 1, ira buscar por nome

                  for(i=1; i<= total_de_medicos; i++)
                    {
                        if (strcmp(nome, medico[i].nome_medico) == 0) // Faz um IF para verificar se o nome ja existe
                            {
                                imprime_medicos(i);
                                return i;
                            }
                    }
                  break;
        case '2':// Caso seja 2, ira bsucar CRM
                  for(i=1; i<= total_de_medicos; i++)
                    {
                        if (CRM == medico[i].CRM) // Faz um IF para verificar se o CRM ja existe
                            {
                                imprime_medicos(i);
                                return i;
                            }
                    }
                  break;
        default: printf("Opcao de busca nao encontrada\n"); // Caso seja qualquer outro valor, um alerta é gerado
    }
    return 0;
}
int buscar_paciente(char opcao_de_busca, char nome[50], long int CPF){
    /***
        Essa funcao realiza dois tipos de busca: por nome do paciente ou CPF do paciente
        O primeiro parametro determina se o tipo da busca irá ocorrer por nome ou CPF
        O segundo parametro é o nome do paciente que esta sendo procurado
        O terceiro parametro é o CPF do paciente que esta sendo procurado
    ***/
    int i = 0;
    switch(opcao_de_busca){ // Faz um switch para verificar o tipo de busca, se é por nome ou CPF
        case '1':// Caso seja 1, a busca deve ocorer por nome
                  for(i=1; i<= total_de_pacientes; i++)
                    {
                        if (strcmp(nome, paciente[i].nome_paciente) == 0)// Faz um IF para verificar se o nome ja existe
                            {
                                imprime_pacientes(i);
                                return i;
                            }
                    }
                  break;
        case '2': // Case seja 2, a busca deve ocorrer por CPF
                  for(i=1; i<= total_de_pacientes; i++)
                    {
                        if (CPF == paciente[i].CPF) // Faz um IF para verificar se o CPF ja existe
                            {
                                imprime_pacientes(i);
                                return i;
                            }
                    }
                  break;
        default: printf("Opcao de busca nao encontrada\n"); // Caso seja qualquer outro valor, um alerta é gerado
    }

    return 0;
}

int buscar_plano_de_saude(char nome[50])
{
    /***
        Essa funcao realiza uma busca por nome, para determinar se o nome do plano de saude ja existe
    ***/
   int i = 0;
    for(i=1; i<= total_de_planos; i++)
    {
        if (strcmp(nome, plano_de_saude[i].nome_plano) == 0) // Faz um IF para verififcar se o nome ja existe
            {
                return i; // Caso o nome exista, retorna o ID do plano de saudde
            }
    }
    return 0;
}

int selecionar_opcao_de_buscar_medicos(){
    /***
        O usuario possui 2 opcoes de buscar um medico:
            1- Por nome
            2- Por CRM
        A funcao buscar_medicos é chamada de acordo com as opcao escolhida nessa funcao
        Case seja 1 ira chamar a funcao buscar_medicos, para procurar pelo nome
        Case seja 2 ira chamar a funcao buscar_medicos, para procurar pelo CRM
    ***/

    char op;
    char nome[50];
    int CRM;
    int id_medico;

    system("cls");
    printf ("\t -------Medicos---------\n");
    printf ("\t|1- Buscar por nome    |\n");
    printf ("\t|2- Buscar por CRM     |\n");
    printf ("\t|0- Sair               |\n");
    printf ("\t ----------------------\n");
    printf ("Digite sua opcao: ");
    scanf ("%s", &op);
    system("cls");
    switch (op){ /*** Realiza um switch para verificar a opcao do usuario: nome ou CRM ***/
        case '1':
                // Caso seja 1, a busca deve ocorrer por nome
                printf("Voce selecionou =====>Medicos =========> Buscar Por Nome\n");
                fflush(stdin);
                printf("Digite o nome: ");
                gets(nome);
                id_medico = buscar_medico('1', nome, 0); // Chama a funcao buscar_medico, passando o nome para ser buscado
                if (id_medico == 0 )// Verifca se o nome foi encontrado, a funcao buscar_medico retorna 0 caso nada seja encontrado
                                    // Se buscar_medico encontrar algum medico com o nome igual ao buscado, ele retorna o ID do medico encontrado
                    {
                        printf("Nenhum dado foi encontrado !\n\n");
                        system("pause");
                    }
                return id_medico;
                break;
        case '2':
                // Caso seja 2, a busca deve ocorrer por CRM
                printf("Voce selecionou =====>Medicos =========> Buscar Por CRM\n");
                printf("Digite o CRM: ");
                scanf("%d", &CRM);
                id_medico= buscar_medico('2', 0, CRM); // Chama a funcao buscar_medico, passando o CRM para ser buscado
                    if (id_medico == 0)// Verifca se o CRM foi encontrado, a funcao buscar_medico retorna 0 caso nada seja encontrado
                                    // Se buscar_medico encontrar algum medico com o CRM igual ao buscado, ele retorna o ID do medico encontrado
                    {
                        printf("Nenhum dado foi encontrado !\n\n");
                        system("pause");
                    }
                return id_medico;
                    break;
        default: break; // Sai da funcao
    }
}

int selecionar_opcao_de_buscar_pacientes(){
    /***
        O usuario possui 2 opcoes de buscar um paciente:
            1- Por nome
            2- Por CPF
        A funcao buscar_paciente é chamada de acordo com as opcao escolhida nessa funcao
        Case seja 1 ira chamar a funcao buscar_paciente, para procurar pelo nome
        Case seja 2 ira chamar a funcao buscar_paciente, para procurar pelo CPF
    ***/
    char op;
    char nome[50];
    long int CPF;
    int id_paciente;

    system("cls");
    printf ("\t ------Pacientes--------\n");
    printf ("\t|1- Buscar por nome    |\n");
    printf ("\t|2- Buscar por CPF     |\n");
    printf ("\t|0- Sair               |\n");
    printf ("\t ----------------------\n");
    printf ("Digite sua opcao: ");
    scanf ("%s", &op);
    system("cls");
    switch (op){ /*** Realiza um switch para verificar a opcao do usuario: nome ou CPF ***/
        case '1':
                printf("Voce selecionou =====>Pacientes =========> Buscar Por Nome\n");
                fflush(stdin);
                printf("Digite o nome: ");
                gets(nome); // lê o nome
                id_paciente = buscar_paciente('1', nome, 0);  // Chama a funcao buscar_paciente, passando o nome para ser buscado
                if (id_paciente == 0 )// Verifca se o nome foi encontrado, a funcao buscar_paciente retorna 0 caso nada seja encontrado
                                    // Se buscar_paciente encontrar algum paciente com o nome igual ao buscado, ele retorna o ID do paciente encontrado
                    {
                        printf("Nenhum dado foi encontrado !\n\n");
                        system("pause");
                    }
                return id_paciente;
                break;
        case '2':
                printf("Voce selecionou =====>Pacientes =========> Buscar Por CPF\n");
                printf("Digite o CPF: ");
                scanf("%d", &CPF); // Le o CPF
                id_paciente= buscar_paciente('2', 0, CPF); // Chama a funcao buscar_paciente, passando o nome para ser buscado
                    if (id_paciente == 0)// Verifca se o CPF foi encontrado, a funcao buscar_paciente retorna 0 caso nada seja encontrado
                                    // Se buscar_paciente encontrar algum paciente com o CPF igual ao buscado, ele retorna o ID do paciente encontrado
                    {
                        printf("Nenhum dado foi encontrado !\n\n");
                        system("pause");
                    }
                return id_paciente;
                    break;
        default: break; // Sai da funcao
    }
}

void cadastra_paciente(){
    /*** Essa funcao realiza o cadastro de um novo paciente no sistema ****/

    long int CPF;
    char op;
    int id_paciente;
    printf("Voce selecionou =====>Pacientes =========> Cadastrar novo paciente\n\n");
    printf("Digite o CPF: ");
    scanf("%ld", &CPF); // Le o CPF do usuario para buscar e localizar se ele ja existe no sistema

    id_paciente = buscar_paciente('2', 0, CPF); // Chamaa a funcao buscar_paciente para verificar se ele existe no sistema
                                                // Buscar paciente ira retonra o ID do paciente, caso o paciente ja exista no sistema
                                                // Caso o usuario nao existe a funcao retorna 0.
    if(id_paciente != 0){ // Verifica se o usuario ja existe

        printf("O usuario ja existe, deseja edita-lo? \n\n");
        printf("Editar ======> 1 \n");
        printf("Sair   ======> 0 \n\n");
        printf("Selecione uma opcao: ");
        scanf("%s", &op);
        if (op == '0') {
                main();
        }
    }else{
        if(total_de_pacientes >= 100){ // Verifca se ja atinigiu o limite de 100 usuarios
            printf("Voce nao pode cadastrar mais pacientes");
            printf("Voce atingiu o limite de 100 pacientes cadastrados, tente editar um ja existente");
            main(); // Retorna o usuario para o menu principal do sistema
        }
        id_paciente = total_de_pacientes; // Atribui ao id_paciente o numero atual total de pacientes
        paciente[id_paciente].CPF = CPF; // Atribui o CPF lido no inicio para a busca, ao paciente sendo criado
        total_de_pacientes++; // Incrementa o total de pacientes, pois um novo usuario foi adicionado
    }
    /***********Realiza a leitura de todos os atributos do paciente*******************/
    fflush(stdin);
    printf("Digite o nome do paciente: ");
    gets(paciente[id_paciente].nome_paciente);

    fflush(stdin);
    printf("Tipo sanguineo: ");
    gets(paciente[id_paciente].tipo_saguineo);

    fflush(stdin);
    printf("Nome da rua: ");
    gets(paciente[id_paciente].endereco_paciente.rua);

    printf("Numero da rua: ");
    scanf("%d", &paciente[id_paciente].endereco_paciente.numero);

    fflush(stdin);
    printf("Bairro: ");
    gets(paciente[id_paciente].endereco_paciente.bairro);

    fflush(stdin);
    printf("Cidade: ");
    gets(paciente[id_paciente].endereco_paciente.cidade);

    fflush(stdin);
    printf("Estado: ");
    gets(paciente[id_paciente].endereco_paciente.estado);

    printf("Telefone Celular: ");
    scanf("%d", &paciente[id_paciente].telefone_celular);

    printf("Telefone Fixo: ");
    scanf("%d", &paciente[id_paciente].telefone_fixo);

    do{
        printf("Opcoes: 0 =>  Alta, 1 => Internado, 2 => Obito\n");
        printf("Situacao: ");
        scanf("%d", &paciente[id_paciente].situacao);
    }while(paciente[id_paciente].situacao > 2); // O usuario é obrigado escolhere entre: 0,1 ou 2
    // Equanto o usuario nao escolher uma dessas 3 opcoes, o sistema ira solicitar para digitar novamente

}
void cadastra_medico(){
    /******** Essa funcao realiza o cadastro de um novo medico ao sistema *****************/
    int CRM;
    char op;
    int id_medico;
    printf("Voce selecionou =====>Medico  =========> Cadastrar novo medico\n\n");
    printf("Digite o CRM: ");
    scanf("%d", &CRM); // Realiza a leitura do CRM para localizar, se ele ja existe no sistema

    id_medico = buscar_medico('2', 0, CRM); // Chama a funcao buscar medico, passando o CRM como atributo para ser buscado
                                            // Chamaa a funcao buscar medico para verificar se ele existe no sistema
                                                // Buscar medico ira retonra o ID do medico, caso o medico ja exista no sistema
                                                // Caso o medico ainda nao exista a funcao retorna 0.
    if(id_medico != 0){ // Verifica se o medico ja existe

        printf("O medico ja existe, deseja edita-lo? \n\n");
        printf("Editar ======> 1 \n");
        printf("Sair   ======> 0 \n\n");
        printf("Selecione uma opcao: ");
        scanf("%s", &op);
        if (op == '0') {
                main();
        }
    }else{
        if(total_de_medicos >= 10){ // Verifica se o sistema ja atigiu o maximo de 10 medicos
            printf("Voce nao pode cadastrar mais medicos\n");
            printf("Voce atingiu o limite de 10 medicos cadastrados, tente editar um ja existente\n");
            system("pause");
            main(); // Retonra o usuario para o menu principal do programa
        }
        id_medico = total_de_medicos; // O ID do medico é numero total de medicos atual
        medico[id_medico].CRM = CRM; // Atribui o CRM lido no inicio ao novo medico sendo criado
        total_de_medicos++; // total de medicos é incrmenado, pois um novo medico esta sendo adicionado ao sistema
    }

    /**** Realiza a leitura de todos os atributos do tipo medico ******/

    fflush(stdin);
    printf("Digite o nome do medico: ");
    gets(medico[id_medico].nome_medico);

    fflush(stdin);
    printf("Digite a data de nascimento: ");
    gets(medico[id_medico].data_nascimento);

    fflush(stdin);
    printf("Tipo sanguineo: ");
    gets(medico[id_medico].tipo_saguineo);

    fflush(stdin);
    printf("Nome da rua: ");
    gets(medico[id_medico].endereco_medico.rua);

    printf("Numero da rua: ");
    scanf("%d", &medico[id_medico].endereco_medico.numero);

    fflush(stdin);
    printf("Bairro: ");
    gets(medico[id_medico].endereco_medico.bairro);

    fflush(stdin);
    printf("Cidade: ");
    gets(medico[id_medico].endereco_medico.cidade);

    fflush(stdin);
    printf("Estado: ");
    gets(medico[id_medico].endereco_medico.estado);

    printf("Telefone Celular: ");
    scanf("%d", &medico[id_medico].telefone_celular);

    printf("Telefone Fixo: ");
    scanf("%d", &medico[id_medico].telefone_fixo);

    do{
     printf("Opcoes: 0 => Afastado, 1 => Ativo \n");
     printf("Situacao: ");
     scanf("%d", &medico[id_medico].situacao);
    }while(medico[id_medico].situacao > 1);
    // O usuario é obrigado escolhere entre: 0 ou 1
    // Equanto o usuario nao escolher uma dessas 2 opcoes, o sistema ira solicitar para digitar novamente
}
int cadastra_plano(){
    int id_plano = 0;
    char nome_plano[50];
    char op;

    printf("Voce selecionou =====>Planos de Saude =========>\n\n");
    printf("Digite o nome do plano: ");
    fflush(stdin); gets(nome_plano);

    id_plano = buscar_plano_de_saude(nome_plano);

    if(id_plano != 0){ // Verifica se o medico ja existe

        printf("O plano ja existe, deseja edita-lo? \n\n");
        printf("Editar ======> 1 \n");
        printf("Sair   ======> 0 \n\n");
        printf("Selecione uma opcao: ");
        scanf("%s", &op);
        if (op == '0') {
                main();
        }else{
            printf("Digite o novo nome desejado: ");
            fflush(stdin); gets(plano_de_saude[id_plano].nome_plano);
            printf("Plano editado com sucesso ! \n");
            return id_plano;
        }
    }else{
        id_plano = total_de_planos;
        if(total_de_planos >= 5){
            printf("Voce nao pode cadastrar mais planos\n");
            printf("Voce atingiu o limite de 5 planos cadastrados, tente editar um ja existente\n");
            system("pause");
            main();
        }
        strcpy(plano_de_saude[id_plano].nome_plano, nome_plano);
        total_de_planos++;
        printf ("Novo Plano Cadastrado com sucesso !!!\n");
        system("pause");
        return id_plano;
    }
    return 0;
}
void cadastra_pronturario(){
    /****************** Essa funcao realiza o cadastro de um novo prontuario ****************/

    int id_paciente, id_medico, id_prontuario, id_plano_de_saude;

    id_prontuario = total_de_prontuarios;

    printf("Voce selecionou =====>Pronturario  =========> Cadastrar novo prontuario\n\n");

    printf("Para cadastrar o prontuario voce deve: \n\n");
    printf("1- Selecionar o Paciente \n");
    system("pause");
    do{
        id_paciente = selecionar_opcao_de_buscar_pacientes(); // Realiza a chamada da funcao, para buscar pacientes no sistema
        // A funcao retorna o ID do paciente escolhido
    }while(id_paciente == 0);// Enquanto nao retorna o ID de um paciente, repete a chamada da funcao de buscar paciente

    printf("\nPara cadastrar o prontuario voce deve: \n\n");// Realiza a chamada da funcao, para buscar pacientes no sistema
    printf("2- Selecionar o Medico \n");
    system("pause");
    do{
     id_medico   = selecionar_opcao_de_buscar_medicos(); // Realiza a chamada da funcao, para buscar pacientes no sistema
     // A funcao retorna o ID do medico escolhido
    }while(id_medico == 0);// Enquanto nao retorna o ID de um paciente, repete a chamada da funcao de buscar medico

    system("cls");

    /********** Realiza a leitura de todos os atributos do tipo prontuario *****************/

    printf("Voce selecionou =====>Pronturario  =========> Cadastrar novo prontuario\n\n");
    printf("Paciente Selecionado => CPF= %ld, Nome: %s \n", paciente[id_paciente].CPF, paciente[id_paciente].nome_paciente);
    printf("Medico Selecionado => CRM= %d, Nome: %s \n\n", medico[id_medico].CRM, medico[id_medico].nome_medico);

    printf("Digite a Data de Interncao: ");

	fflush(stdin); gets(prontuario[id_prontuario].data_interncao);

    printf("Digite a Doenca Identificada: ");
    fflush(stdin); gets(prontuario[id_prontuario].doenca_identificada);

    printf("Digite os Procedimentos executados: ");
    fflush(stdin); gets(prontuario[id_prontuario].procedimentos_executados);

    printf("Digite a Medicacao: ");
    fflush(stdin); gets(prontuario[id_prontuario].medicamentos);

    id_plano_de_saude = cadastra_plano(); // Chama a funcao cadastra plano
    // O usuario pode escolher um plano existente ou adicionar um novo
    // A funcao retorna o ID do plano_de_saude escolhido
    prontuario[id_prontuario].plano_de_saude = id_plano_de_saude; // Atribui o ID do plano de saude escolhido

    total_de_prontuarios++; // Incremente o nuemero total de prontuarios, pois um novo prontuario foi adicionado ao sistema
    system("pause");
}

void imprime_dados_paciente(int situacao){
    /******* Essa funcao imprime os pacientes de acordo com sua situacao
                onde: 0 => Alta,
                      1 => Internado,
                      2 => Obito
    *******/
    int i = 1;
    for(i=1; i< total_de_pacientes; i++)
    {
        if (paciente[i].situacao == situacao) // Faz um IF para verificar a situacao do pacinete
            {
                imprime_pacientes(i); // Chama a fucnao imprimir, que realiza o printf dos dados
            }
    }
}
void imprime_dados_medico(int opcao)
{
    /******* Essa funcao imprime os medicos de acordo com sua situacao
                onde: 0 => Afastado,
                      1 => Ativo
    *******/
    int i = 0;
    for(i=1; i< total_de_medicos; i++)
    {
        if (medico[i].situacao == opcao) // Faz um IF para verificar a situacao do medico
        {
            imprime_medicos(i); // Chama a fucnao imprimir, que realiza o printf dos dados
        }
    }
}
void imprime_dados()
{
    /***** Essa funcao, é o menu da opcao imprime, onde chama as funcoes de acordo com a escolha do usuario *******/
    char op;
    while(1)
    {
    system("cls");
    printf ("\t ---------------Imprimir Dados----------------------\n");
    printf ("\t|1- Imprime todos os pacientes com alta             |\n");
    printf ("\t|2- Imprime todos os pacientes internados           |\n");
    printf ("\t|3- Imprime todos os pacientes em obito             |\n");
    printf ("\t|4- Imprime dados de um paciente em especifico      |\n");
    printf ("\t|5- Imprime todos os medicos afastados              |\n");
    printf ("\t|6- Imprime todos os medicos ativos                 |\n");
    printf ("\t|7- Imprime de um medico especifico                 |\n");
    printf ("\t|0- SAIR                                            |\n");
    printf ("\t ---------------------------------------------------\n");
    printf ("Digite sua opcao: ");
    scanf ("%s", &op);
    system("cls");
        switch (op)
        {
            case '1': printf("======>Voce Selecionou Pacientes com alta======>\n"); imprime_dados_paciente(0); break; // Pacientes com alta
            case '2': printf("======>Voce Selecionou Pacientes internados======>\n"); imprime_dados_paciente(1); break; // Pacientes Internado
            case '3': printf("======>Voce Selecionou Pacientes com alta======>\n"); imprime_dados_paciente(2); break; // Pacientes em Obito
            case '4': selecionar_opcao_de_buscar_pacientes(); break; // Buscar Paciente
            case '5': printf("======>Voce Selecionou Medicos Afastados======>\n"); imprime_dados_medico(0); break; // Medicos afastados
            case '6': printf("======>Voce Selecionou Medicos Ativos======>\n"); imprime_dados_medico(1); break; // Medicos Ativos
            case '7': selecionar_opcao_de_buscar_medicos(); break; // Buscar Medico
            default:  main(); break;
        }
    }
}


main(){ // FUncao pricipal do programa

char op;
while(1){
    system("cls");
    printf ("\t ----------------------\n");
    printf ("\t|1- Cadastrar paciente   |\n");
    printf ("\t|2- Buscar paciente      |\n");
    printf ("\t|3- Cadastrar Medico     |\n");
    printf ("\t|4- Buscar Medico        |\n");
    printf ("\t|5- Cadastrar prontuario |\n");
    printf ("\t|6- Cadastrar plano      |\n");
    printf ("\t|7- Imprimir Dados       |\n");
    printf ("\t|0- Sair                 |\n");
    printf ("\t ------------------------\n");
    printf ("Digite sua opcao: ");
    scanf ("%s", &op);
    system("cls");

    switch (op){
        case '1': cadastra_paciente(); break; // Chama a funcao de cadastrar pacientes
        case '2': selecionar_opcao_de_buscar_pacientes(); break; // Chama a funcao de escolher a forma de busca do usuario
        case '3': cadastra_medico(); break; // Chama a funcao de cadastrar medicos
        case '4': selecionar_opcao_de_buscar_medicos(); break; // Chama a funcao de escolher a forma de busca do medico
        case '5': cadastra_pronturario(); break; // Chama a funcao de cadastrar prontuario
        case '6': cadastra_plano(); break; // Chama a funcao de cadastrar plano de saude
        case '7': imprime_dados(); break; // Chama a funcao que imprime o menu das opcoes de impressoes
        case '0': exit(1); // Finaliza o progrma
    }
}

}
