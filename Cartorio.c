#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //ciclioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() // funcao responsavel por cadastrar os usuarios no sistema
{
	//inicio criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criacao de variaveis/string
	printf("Digite o CPF a ser cadastrado: "); //coletando informacao do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo o "w" significa escrever
	fprintf(file,cpf); //armazena o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //criar arquivo
	fprintf(file, ","); //cria uma virgula entre uma informacao e outra
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta informacao do usuario
	scanf("%s",nome); //salvando string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,nome); //armazena o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquvivo
	fprintf(file, ","); //cria uma virgula entre uma variavel e outra
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coleta informacao do usiario
	scanf("%s",sobrenome); //salva a string
	
	file = fopen(arquivo, "a"); //cria arquivo
	fprintf(file,sobrenome); //armazena o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria arquivo
	fprintf(file, ","); //cria uma virgula entre uma variavel e outra
	fclose(file); //fechar o arquivo
	
	printf("Cargo a ser cadastrado: "); //cria arquivo
	scanf("%s",cargo); //salva a string
	
	file = fopen(arquivo, "a"); //cria arquivo
	fprintf(file,cargo); //armazena o valor da variavel
	fclose(file); //fecha o arquivo
	
	
	
}

int consulta() //funcao para consultar
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	//inicio criacao de variaveis/string
    char cpf[40];
    char conteudo[200];
    //final criacao de variaveis/string
    
    printf("Digite o CPF a ser consultado: "); //coletando informacao do usuario
    scanf("%s",cpf); //salvar a string
    
    FILE *file; //criar arquivo
    file = fopen(cpf,"r"); //ler o arquivo
    
    if(file == NULL) //caso o valor da variavel seja nulo
    {
    	printf("N�o foi possivel encontrar esse arquivo, arquivo n�o localizado!.\n"); //acao caso nao haja a variavel
	}
	
	while(fgets(conteudo, 200, file) != NULL) //pesquisa de variaveis no banco de dados
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //pausa para ler
	
		
}

int deletar() { 
    char cpf[40];

    printf("Digite o CPF do usu�rio que deseja deletar: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usu�rio deletado com sucesso!\n");
    } else {
        printf("Usu�rio n�o cadastrado ou CPF incorreto.\n");
    }
    system("pause");
    return 0;
}



int main() //funcao principal
    {
	int opcao=0; //definindo as variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls"); //responsavel por limpar a tela
		
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n");//inicio do menu
	    printf("Escolha alguma das op��es abaixo no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar os nomes\n");
	    printf("\t3 - Deletar os nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("Op��o");
	
	    scanf("%d", &opcao);//armazenando a escolha do usuario
	
	    system("cls");
	    
	    
	    switch(opcao)//inicio da selecao do menu
	    {
	    	case 1:
	    	registro(); //chamada de funcao
			break;
			
			case 2:
			consulta(); //chamada de funcao
			break;
			
			case 3:
			deletar(); //chamada de funcao
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
			
			default:
			printf("Essa op��o n�o est� disponivel!\n"); //chamada de funcao
	        system("pause");	
	    	break;
				
		}  //fim da selecao de menu
}

}

