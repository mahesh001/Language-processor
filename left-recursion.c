#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
        int i,j;
        char nonTerminal;
        char alpha[10][10],beta[10][10];
        int num,ca,cb;
        char production[10][80];
        int index=3;
        printf("Enter number of porductions:");
        scanf("%d",&num);
        printf("Enter the grammar:\n");
        for(i=0;i<num;i++)
                scanf("%s",production[i]);
        for(i=0;i<num;i++)
        {
                printf("\nGrammar: %s\n",production[i]);
                nonTerminal=production[i][0];
              
                index=3;
                ca=0;
                cb=0;
                while(index<strlen(production[i]))
                {
                        if(nonTerminal==production[i][index])
                        {
                                index++;
                                j=0;
                                while(production[i][index]!='|' && production[i][index]!='\0')
                                {
                                        alpha[ca][j++]=production[i][index++];
                                }
                                alpha[ca][j]='\0';
                             
                                ca++;
                                index++;
                        }
                        else
                        {
                                j=0;
                                while(production[i][index]!='|' && production[i][index]!='\0')
                                {
                                        beta[cb][j++]=production[i][index++];
                                }
                                beta[cb][j]='\0';
                              
                                cb++;
                                index++;
                        }
                }
                if(ca>0)
                {
                        printf("Left recursion removed grammar:\n");
                        printf("%c->",nonTerminal);
                        for(j=0;j<cb;j++)
                        {
                                printf("%s%c\'",beta[j],nonTerminal);
                                if(j<cb-1)
                                printf("|");
                        }
                        printf("\n");
                        printf("%c\'->",nonTerminal);
                        for(j=0;j<ca;j++)
                        {
                                printf("%s%c\'|",alpha[j],nonTerminal);
                        }
                        printf("epsilon\n");
   }
                else
                        printf("No left recursion present\n");
        }
        return 0;
}




/*


E->E+T
E->T
T->T*F
T->F
F->(E)
F->id


*/
