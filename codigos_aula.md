int A = 10;
int B
FILE*fp = fopen("ola.txt","wb");  //stdlib
fwrite(&A, sizeof(int), 1, fp);

int fid = open("ola.txt", &A, sizeof(int)) // posix
--------------------------------------------------
int fd = open("/tmp/teste.txt", O_RDONLY);
char c;
lseek (fd,6,SEEK_SET);
read (fd, &c, 1);

