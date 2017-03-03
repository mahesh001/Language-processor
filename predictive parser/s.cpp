#include<stdio.h>
#include<stdlib.h>
#define node struct tree1
char matrix[12][9][2]={{'s5','e ','e ','s4',' e','e ','1','2','3'},{' e','s6','e ','e ',' e','accept',' e','e ','e'},{'e ','r2','s7','e ','r2','r2','e ',' e',' e'},
                    {'e ','r4','r4',' e','r4','r4',' e','e ',' e'},{'s5',' e',' e','s4','e ','e ','8','2','3'},{'e ','r6','r6',' e','r6','r6',' e',' e','e '},
                    {'s5',' e',' e','s4',' e','e ','e ','9','3'},{'s5',' e','e ','s4',' e',' e','e ','e ','10'},{' e','s6',' e','e ','s11',' e','e ','e ','e '},
                    {' e','r1','s7','e ','r1','r1',' e','e ','e '},{' e','r3','r3','e ','r3','r3','e ',' e',' e'},{' e','r5','r5','e ','r5','r5','e ','e ',' e'} 
					};

int tos=-1;

struct tree1
{
        char data;
        node *lptr;
        node *rptr;
}*first;

struct opr
{
        char op_name;
        node *t;
}oprate[50];

char cur_op[12]={'0','1','2','3','4','5','6','7','8','9','10','11'};
char stack_op[9]={'i','+','*','(',')','$','E','T','F'};

int isOperator(char c)
{
        int i=0;
        for(i=0;i<12;i++)
                if(c==cur_op[i] || c==stack_op[i])
                        break;
        if(i==5)
                return -1;
        else
                return i;
}

int getOperatorPosition(char c)
{
        int i;
        for(i=0;i<9;i++)
                if(c==cur_op[i] || c==stack_op[i])
                        break;
        return i;
}					
void matrix_value()
{
        int i,j;
        printf("SLR Matrix\n");
        printf(" ");
        for(i=0;i<9;i++)
                printf(" %c",stack_op[i]);
        printf("\n");
        for(i=0;i<12;i++)
        {
                printf("%c| ",cur_op[i]);
                for(j=0;j<9;j++)
                {
                        printf("%c ",matrix[i][j]);
                }
                printf("\n");
        }
}

int main()
{
matrix_value();
			return 0;
}
