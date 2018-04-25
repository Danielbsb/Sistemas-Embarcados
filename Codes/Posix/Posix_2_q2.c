#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
	int fp;
	char extensao[5] = ".txt";
   	char nome[100] = {"Nome: "};
	char idade[100] = {"Idade: "};
	printf("Digite o seu nome: ");
	scanf("%s", &nome[7]);
	printf("Digite sua idade: ");
	scanf("%s", &idade[8]);
	int i = 7;
	
	while(nome[i] != '\0'){
		i++;
	}
	nome[i] = '.';
	nome[i+1] = 't';
	nome[i+2] = 'x';
	nome[i+3] = 't';
	//i = 0;
	int j = 0;
	for(j = 0; j<20; j++){
		printf("%c", nome[j]);
	} 

	fp = open (&nome[7], O_RDWR | O_CREAT, S_IRWXU);
	
	write(fp, &nome, (i+4)*sizeof(char));
	write(fp, &idade, (10)*sizeof(char));
	
	close(fp);
	/*fp = open ("ola_mundo.txt", O_RDONLY);
	read(fp, &teste[0], sizeof(char));
	close(fp);

	printf("%c\n", teste[0]);
	*/
	return(0);
}