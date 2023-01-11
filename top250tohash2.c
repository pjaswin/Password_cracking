#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>
#include <time.h>
#include <unistd.h>
int main()
{
    FILE *fp1,*fp2;
    char line1[100];
    char *n1;
    unsigned long seed[2];
    char salt[] = "$1$GC";
    char *password;
    fp1=fopen("top250.txt","r");
    fp2=fopen("keyword.txt","w");
    if((fp1==NULL)||(fp2==NULL))
    {
        printf("ERROR");
        exit(1);
    }
    while(1)
    {
		int i=0;
		char a[10]="";
        n1=fgets(line1,sizeof(line1),fp1);
        if((n1==NULL))
        {
			break;
		}
		char * token2 = strtok(line1,"\t\n");//using strtok function to seprate password keyword
		while( token2 != NULL )
		 {
		   //printf( " %s\n", token2);
			 if(i==3)
			{
			    //strcpy(a,token2);
				//printf( " %s", token2);
			    password = crypt(token2, salt);//hashing 250words with salt $1$GC
				//printf("%s\n" ,password);
				fprintf(fp2,"%s %s\n",token2,password);//saving all hashed keywords to new file		
			}
			i=i+1; 
			token2= strtok(NULL, "\t\n");
		 }
		 
		}
}
