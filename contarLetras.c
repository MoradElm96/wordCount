#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
   
    char buffer[10];
    int fd;
    int contador=0;
    char letra;
    int estado=0;
    
    if (argc<3)
        {
            printf("Faltan los argumentos\n");
            exit(0);
        }



char letra1 =argv[2][0];
    char letra2 = argv[2][1];
    char letra3= argv[2][2];



fd=open(argv[1],0);// abre el fichero para lectura
    printf("Contenido del fichero:\n");
    
    while(read(fd,buffer,1)){
        printf("%c",buffer[0]);
		switch (estado){
			case 0:
				if (buffer[0]==letra1)
				 	estado=1;
				break;
			case 1:
				if (buffer[0]== letra2)
				 	estado=2;
				else
					if (buffer[0]==letra1)
						estado=2;
					else
						estado=0;
				break;
			default: //estado 2
				if (buffer[0]==letra3)
					{
						estado=0;
						contador++;
					}
				else if (buffer[0]==letra1)
						estado=1;
						else
							estado=0;


				break;
		}
			
    }
    close(fd);
	printf("Hay %d apariciones\n",contador);
}