#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fp1,*fp2,*fp3;
    char line1[1000],line2[1000];
    char *n1,*n2;
    
    char a[1000],b[1000],ch;
    fp1=fopen("training-passwd.txt","r");
    fp2=fopen("training-shadow.txt","r");
    fp3=fopen("passwordfile.txt","w");
    if((fp1==NULL)||(fp2==NULL))
    {
        printf("ERROR");
        exit(1);
    }
	while(1)
    {
		int i=0;
		char a[]="";
        n2=fgets(line2,sizeof(line2),fp2);
        if((n2==NULL))
        {
            break;
        }
        char * token2 = strtok(line2,":");//used token to seprate words
 
		
		 while( token2 != NULL )
		 {
			if(i==1)
			{
				strcpy(a,token2);
				//printf( " %s\n", a);
			}
			i=i+1; 
			 
			 token2= strtok(NULL, ":");
		 }
		 strcpy(b,a);
		n1=fgets(line1,sizeof(line1),fp1);
		
		if((n1==NULL))
        {
            break;
        }
        
        char * token1 = strtok(line1,":");
        char sam[50000];
        strcpy(sam,"\0");
        int f=0;
		while( token1 != NULL )
		 {
			 if(f==0)
			 {
				 strcat(sam,token1);
				
				    
			 }
			 
			 int r=strcmp(token1,"x");//replaced x with hash value 
			 if(r==0)
			 {
				 //printf(" %s\n", b);
				 strcat(sam,":");
				 strcat(sam,b);
				 
			 }
			 //if(r !=0 && f!=1)
			 //{
				//printf( " %s\n", token1);
				//strcat(sam,":");
				//strcat(sam,token1);
			
			 
			 f=1;
			token1= strtok(NULL, ":");
		 }
		fprintf(fp3,"%s\n",sam);//saving file in newfile.
        //printf(" %s\n", sam);
		
    }
}
