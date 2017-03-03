#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
        char alpha[20];
        char token[10][20];
        char production[80];
        int i,j,n,tc;
        int index,ac,ap;
        index=3;
        ac=0;
        ap=0;
        printf("Enter the grammar:\n");
                scanf("%s",production);
        {
                tc=0;

                while(index<strlen(production))
                {
                        j=0;
                        while(production[index]!='\0' && production[index]!='|')
                        {
                                token[tc][j++]=production[index++];
                        }
                        token[tc][j]='\0';
                        if(token[tc][0]==token[0][0])
                                ac++;
                        tc++;
                        index++;
                }
                int flag=0;
                ap=0;
                for(i=0;token[0][i]!='\0';i++)
                {
                        for(j=1;j<ac;j++)
                        {
                                if(token[j][i]!=token[0][i])
                                        flag=1;
                        }
                        if(flag==1)
                                break;
                        ap++;
                }
                printf("Left factoring removed:\n");
                printf("%c->",production[0]);
                for(i=0;i<ap;i++)
                        printf("%c",token[0][i]);
                printf("%c\'",production[0]);
                for(i=ac;i<tc;i++)
                        printf("%s",token[i]);
                printf("\n");

                printf("%c\'->",production[0]);
                for(i=0;i<ac;i++)
                {
                        if(i!=0)
                                printf("|");
                        for(j=ap;j<strlen(token[i]);j++)
                                printf("%c",token[i][j]);
                }
        }
		return 0;
}


/*
T->*iF|*iB|d

*/
