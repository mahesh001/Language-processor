#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char stk[80][10];
int top;

char FIRST[10][10][20];
char FOLLOW[10][10][20];
char TABLE[10][10][20];

char NT[10];
char T[10][10];
int tc;
int finish[10];
char followEq[20][2];
int eqcnt;
int followCn[10];
int num;


void push(char S[80][10],char str[10])
{
        strcpy(S[top++],str);
}

char *pop(char S[80][10])
{
        return S[--top];
}

char *rettop(char S[80][10])
{
        int i;
        i=top-1;
        return S[i];
}
int search(char str[80],char key)
{
        int i;
        for(i=0;i<strlen(str);i++)
        {
                if(str[i]==key)
                        return i;
        }
        return -1;
}

int search2(char str[10][10],char key[10],int n)
{
        int i;
        for(i=0;i<n;i++)
                if(strcmp(key,str[i])==0)
                        return i;
        return -1;
}

int check(char str[10][20],char key[10],int n)
{
        int i;
        for(i=0;i<n;i++)
                if(strcmp(str[i],key)==0)
                        return 1;
        return 0;
}
int checkFinish(char nt)
{
        int i;
        for(i=0;i<num;i++)
                                                  {
                if(NT[i]==nt)
                        return finish[i];
        }
        return 0;
}

void findFirst(char prod[10][80],int i)
{
        char tempFirst[10][20];
        int j,idx,pos,k,jc;
        j=0;
        idx=3;

        if(finish[i]<1)  //If FIRST is not yet found
        {
        if(search(prod[i],'e')!=-1)  // If epsilon present
                strcpy(tempFirst[j++],"e");

        while(idx<strlen(prod[i]))
        {
                if((prod[i][idx]<'A' || prod[i][idx]>'Z')  && prod[i][idx]!='e')  // if terminals present first
                {
                        //printf("%c %c\n",prod[i][idx],NT[i]);
                        jc=0;
                        while((prod[i][idx]<'A' || prod[i][idx]>'Z')  && prod[i][idx]!='e')  // if terminals present first
                        {
                                tempFirst[j][jc++]=prod[i][idx++];
                        }
                        tempFirst[j][jc]='\0';
                        j++;
                        while(prod[i][idx]!='|' && prod[i][idx]!='\0')
                                idx++;
                        idx++;
                        finish[i]++;
                }
                else
                {
                        pos=search(NT,prod[i][idx]);
                        if(checkFinish(NT[pos])) // FIRST of that NT already available
                        {
                                for(k=0;k<finish[pos];k++)
                                        if(FIRST[pos][k][0]!='e')
                                        {
                                                strcpy(tempFirst[j++],FIRST[pos][k]);
                                                finish[i]++;
                                        }
                        }
                        else                     // FIRST not available
                        {
                                findFirst(prod,pos);
                                for(k=0;k<finish[pos];k++)
                                        if(FIRST[pos][k][0]!='e')
                                        {
                                                strcpy(tempFirst[j++],FIRST[pos][k]);
                                                finish[i]++;
                                        }
                        }
                        while(prod[i][idx]!='|' && prod[i]!='\0')
                                idx++;
                }
        }
        finish[i]=j;
        for(k=0;k<j;k++){
                strcpy(FIRST[i][k],tempFirst[k]);
                //printf("%s--",FIRST[i][k]);
                }
        }
}

                                     void findFollow(char prod[10][80],int i)
{
        int idx,j,k,pos1,pos2,flag;
        char terminal[2];
        terminal[1]='\0';
        idx=3;
        while(idx<strlen(prod[i]))
        {
                while((prod[i][idx]<'A' || prod[i][idx]>'Z') && prod[i][idx]!='|')
                        idx++;
                pos1=search(NT,prod[i][idx]);
                //printf("%c\n",prod[i][idx]);
                pos2=search(NT,prod[i][idx+1]);
                if(pos1!=-1)
                {
                        if(pos2==-1)
                        {
                                if(prod[i][idx+1]=='|' || prod[i][idx+1]=='\0') // No follow
                                {
                                        if(NT[pos1]!=prod[i][0] && NT[pos1]!=prod[i][0])
                                        {
                                                followEq[eqcnt][0]=NT[pos1];
                                                followEq[eqcnt++][1]=prod[i][0];
                                        }
                                }
                                else  // terminal follow
                                {
                                        //printf("%c termf\n",NT[pos1]);
                                        terminal[0]=prod[i][idx+1];
                                        //printf("%c",prod[i][idx+1]);
                                        if(!check(FOLLOW[pos1],terminal,followCn[pos1]))
                                        strcpy(FOLLOW[pos1][followCn[pos1]++],terminal);
                                }
                        }
                        else // Non terminal follow
                        {
                                //printf("%c nonTermf\n",NT[pos1]);
                                flag=0;
                                for(j=0;j<finish[pos2];j++)
                                {
                                        if(strcmp(FIRST[pos2][j],"e")==0)
                                        {
                                                if(NT[pos1]!=prod[i][0] && NT[pos1]!=prod[i][0])
                                                {
                                                        followEq[eqcnt][0]=NT[pos1];
                                                        followEq[eqcnt++][1]=prod[i][0];
                                                }
                                        }
                                        else
                                        {
                                                if(!check(FOLLOW[pos1],FIRST[pos2][j],followCn[pos1]))
                                                strcpy(FOLLOW[pos1][followCn[pos1]++],FIRST[pos2][j]);
                                        }
                                }
                        }
                }
                idx++;
        }
        //printf("-%d--\n",followCn[i]);
}

void constructTable(char prod[10][80],int n)
{
        int i,j,k,l,s,t;
        int idx;
        int idx2;
        char substr[10];
        for(i=0;i<n;i++)
        {
                                           j=3;
                substr[0]=prod[i][0];
                substr[1]=prod[i][1];
                substr[2]=prod[i][2];
                while(j<strlen(prod[i]))
                {
                        t=3;
                        s=j;
                        while(prod[i][s]!='|' && s<strlen(prod[i]))
                                substr[t++]=prod[i][s++];
                        substr[t]='\0';
                        if(prod[i][j]>='A' && prod[i][j]<='Z')
                        {
                                idx=search(NT,prod[i][j]);
                                for(k=0;k<finish[idx];k++)
                                {
                                        if(strcmp(FIRST[idx][k],"e")!=0)
                                        {
                                                idx2=search2(T,FIRST[idx][k],tc);
                                                strcpy(TABLE[i][idx2],substr);
                                        }
                                        else
                                        {
                                                for(l=0;l<followCn[i];l++)
                                                {
                                                        idx2=search2(T,FOLLOW[i][l],tc);
                                                        strcpy(TABLE[i][idx2],substr);
                                                }
                                        }
                                }
                        }
                        else if(prod[i][j]!='e')
                        {
                                char temp[2];
                                temp[0]=prod[i][j];
                                temp[1]='\0';
                                idx2=search2(T,temp,tc);
                                strcpy(TABLE[i][idx2],substr);
                        }
                        else
                        {
                                substr[3]='e';
                                substr[4]='\0';
                                for(l=0;l<followCn[i];l++)
                                {
                                        idx2=search2(T,FOLLOW[i][l],tc);
                                        strcpy(TABLE[i][idx2],substr);
                                }
                        }

                        while(prod[i][j]!='|' && j<strlen(prod[i]))
                        {
                                j++;
                        }
                        j++;
                }
        }
}

void printstk()
{
        int i;
        for(i=0;i<top;i++)
                printf("%s ",stk[i]);
}

int main()
{
        top=0;
        int i,j;
     char nonTerminal;
        char alpha[10][10],beta[10][10];
        int ca,cb;
        char production[10][80];
        int index=3;
        printf("Enter number of porductions:");
        scanf("%d",&num);
        printf("Enter the grammar:\n");
        for(i=0;i<num;i++)
                scanf("%s",production[i]);
        for(i=0;i<num;i++)
        {
                NT[i]=production[i][0];
                finish[i]=0;
                followCn[i]=0;
        }
        strcpy(T[0],"i");
        strcpy(T[1],"+");
        strcpy(T[2],"*");
        strcpy(T[3],"(");
        strcpy(T[4],")");
        strcpy(T[5],"$");
        tc=6;
        for(i=0;i<num;i++)
                findFirst(production,i);
        printf("FIRST:\n");
        for(i=0;i<num;i++)
        {
                printf("%d %c: ",finish[i],NT[i]);
                for(j=0;j<finish[i];j++)
                {
                        printf("%s",FIRST[i][j]);
                        if(j<finish[i]-1)
                        printf("|");
                }
                printf("\n");
        }
        int k;
        eqcnt=0;
        strcpy(FOLLOW[0][0],"$"); // adding $ to FOLLOW of start state
        followCn[0]++;
        for(i=0;i<num;i++)
                findFollow(production,i);
        printf("FOLLOW:\n");
        int l;
        for(i=0;i<eqcnt;i++)
        {
                j=search(NT,followEq[i][0]);
                k=search(NT,followEq[i][1]);
                for(l=0;l<followCn[k];l++)
                {
                        if(!check(FOLLOW[j],FOLLOW[k][l],followCn[j]))
                        {
                                strcpy(FOLLOW[j][followCn[j]],FOLLOW[k][l]);
                                followCn[j]++;
                        }
                }
        }
        for(k=0;k<num;k++)
        {
                printf("%d %c: ",followCn[k],NT[k]);
                for(j=0;j<followCn[k];j++)
                {
                        printf("%s",FOLLOW[k][j]);
                        if(j<followCn[k]-1)
                        printf("|");
                }
                printf("\n");
        }
        for(i=0;i<num;i++)
              for(j=0;j<tc;j++)
                        strcpy(TABLE[i][j],"error");
        constructTable(production,num);
        for(i=0;i<num;i++)
        {
                for(j=0;j<tc;j++)
                        printf("%s\t",TABLE[i][j]);
                printf("\n");
        }
        char input[80][10];
        int n;
        printf("Enter no of terminal in input:");
        scanf("%d",&n);
        for(i=0;i<n;i++)
                scanf("%s",input[i]);
        strcpy(input[n],"$");
        push(stk,"$");
        char temp[5];
        temp[0]=NT[0];
        temp[1]='\0';
        push(stk,temp);
        i=0;
        int tidx,sidx;
        while(strcmp(input[i],"$")!=0 || strcmp(rettop(stk),"$")!=0)
        {
                //printstk(stk);
                //printf(" -- %s\n",input[i]);
                tidx=search2(T,input[i],tc);
                if(tidx==-1)
                {
                        printf("Terminal not found, not accepted\n");
                        exit(0);
                }
                strcpy(temp,rettop(stk));
                if(temp[0]>='A' && temp[0]<='Z')
                {
                        sidx=search(NT,temp[0]);
                        j=strlen(TABLE[sidx][tidx])-1;
                        top--;
                        while(j>=3)
                        {
                                temp[0]=TABLE[sidx][tidx][j--];
                                temp[1]='\0';
                                if(strcmp(temp,"e")!=0)
                                        push(stk,temp);
                        }

                }
                else if(strcmp(temp,"e")==0)
                        top--;
                else if(strcmp(temp,input[i])==0)
                {
                        top--;
                        i++;
                }
                else
                {
                        printf("String not accepted.\n");
                        exit(1);
                }
                //sleep(1);
        }
                printf("String is accepted\n");
}
                                                     
