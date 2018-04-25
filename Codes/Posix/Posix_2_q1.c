#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
	int fp;
	char word[12] = "Ola mundo !";
   	char teste[12] = {};

	fp = open ("ola_mundo.txt", O_RDWR | O_CREAT, S_IRWXU);

	int i = 0;
	
	write(fp, &word, 12*sizeof(char));
	close(fp);
	fp = open ("ola_mundo.txt", O_RDONLY);
	read(fp, &teste[0], sizeof(char));
	close(fp);

	printf("%c\n", teste[0]);
	return(0);
}