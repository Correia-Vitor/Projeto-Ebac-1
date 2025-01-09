#include <stdio.h> //biblioteca de comunicacao do usuario
#include <stdlib.h> //biblioteca de alocao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texo por regiao
#include <string.h> //biblioteca responsavel pelas strings


int main()
{
	int opcao=0; //definindo variveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
   	 	setlocale(LC_ALL,"Portuguese"); //definindo linguagem
    
   		printf(" ### Cartório da EBAC ###\n\n"); //Inicio do Menu
   		printf("escolha a opção desejada no menu:\n\n");
   		printf("\t1 - Registrar nomes\n");
   		printf("\t2 - Consultar nomes\n");
   		printf("\t3 - Deletar nomes\n");
   		printf("\t4 - Sair do Programa\n\n\n");
		printf("Opção:");   //Fim do Menu
   	
   		scanf("%d", &opcao); //Armazenando a escolha do usuario
   	
   		system("cls"); //responsavel por limpar a tela
   		
   		
		switch(opcao)	
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado e até a próxima!");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
   			system("pause");
   			break;
			} //fim da selecao
	   
   }
   	
}


int registro() //responsavel por cadastrar os usuarios no sistema
{
	//inicio da criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criacao de variaveis/string
	
	printf("Você escolheu o registro de nomes!\nDigite o CPF a ser cadastrado: ");//Coletando informacao do usuario
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria arquivo o "w" vem de Write(escrever)
	fprintf(file,"CPF: ");
	fprintf(file, cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);	
	
   	system("pause");
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
		
	printf("Você escolheu consultar nomes!\nDigite o CPF a ser consultado: ");
	scanf("%s", cpf);
	system("cls");
	printf("Dados cadastrais:\n\n");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nArquivo não localizado!\n");
	}
	
	

	
	while(fgets(conteudo, 200, file)!= NULL)
	{
	
	printf("%s", conteudo);
	printf("\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Você escolheu deletar nomes!\nDigite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Este CPF não se encontra no sistema!\n");
				
	}
	if(file != NULL)
	{
		printf("Cadastro deletado com sucesso!\n");
		
	}
	system("pause");
}
