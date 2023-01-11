#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>
#include <time.h>
#include <unistd.h>
int main()
{
    FILE *fp1,*fp2,*fp3;
    char line1[10000],line2[10000];
    int k=0;
    char *n1,*n2;
    fp1=fopen("keyword.txt","r");
    fp2=fopen("passwordfile.txt","r");
    fp3=fopen("allcrackpasswd.txt","w");
    if((fp1==NULL))
    {
        printf("ERROR");
        exit(1);
    }
    while(1)
    {
		int i=0;
		char a[1000]="",b[1000]="";
		
		//char output[100];
		n1=fgets(line1,sizeof(line1),fp1);
        //n2=fgets(line2,sizeof(line2),fp2);
        if((n1==NULL))
        {
            break;
        }
        char * token1 = strtok(line1," ");
   // loop through the string to extract all other tokens
		
		 while( token1 != NULL )
		 {
			if(i==0)
			{
				strcpy(a,token1);
				//printf( " %s", a);
			}
			if(i==1)
			{
				strcpy(b,token1);
				//printf( " %s", a);
				while(fgets(line2,sizeof(line2),fp2))//double loop for comparing two files
				{
					//printf( " %s", b);
					int j=0;
					char c[1000]="",d[1000]="";
					char * token2 = strtok(line2,":");
					while(token2!=NULL)
					{
						if(j==0)
						{
							strcpy(c,token2);
							//printf( " %s", c);
							
						}
						if(j==1)
						{
							strcpy(d,token2);
							//printf( " %s", b);
							
						}
						j=j+1;
						token2= strtok(NULL, ":");
					}
					if(strcmp(b,d)==0)
					{
						//printf("%s=%s\n",a,c);
						fprintf(fp3,"%s=%s\n",a,c);//comparing hashcodes and replacing value and saving in new file
						k=k+1;//taking count
					}
					
					
				}
				fseek(fp2, 0, SEEK_SET);
				
				
			}
			//printf( " %s", a);
			//strcpy(d,b);
			
			i=i+1; 
			token1= strtok(NULL, " ");
			
			}
		
}
fprintf(fp3,"total password cracked is=%d",k);//totalcracked pwd output
printf("total password cracked is=%d",k);
fclose(fp3);
}
