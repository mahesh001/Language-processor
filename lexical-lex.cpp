
%{
	
%}
letter[a-z A-Z]
digit[0-9]

%%
{digit}+("E"("+"|"-")?{digit}+)?printf("\n%s\t is real number",yytext);
{digit}+"."{digit}+("E"("+"|"-")?{digit}+)?printf("\n%s\t is a floating point number number",yytext);
"\a"|"\n"|"\b"|"\t"|"\\t"|"\\b"|"\\a" printf("\n %s is a escap sequence ",yytext);
"if"|"else"|"int"|"char"|"scanf"|"print"|"switch"|"return"|"struct"|"do"|"while"|"void"|"for"|"float"| printf("\n%s is a keyword",yytext);
{letter}({letter}|{digit}*) printf("\n %s is an identifier",yytext);
"&&"|"<"|">"|"<="|">="|"="|"+"|"-"|"?"|"*"|"/"|"%"|"&"|"||" printf("\n %s it is operator",yytext);
"{"|"}"|"["|"]"|"("|")"|"#"|"'"|"."|"\\"|";" printf("\n %s is a special character",yytext);
"%d"|"%s"|"%c"|"%e"  printf("\n%s is a format identifier",yytext);
%%
int yywrap()
{
	return 1;
}
int main(int argc,char *argv[])
{
	yyin=fopen(argv[1],"r");
	yylex();
	fclose(yyin);
	return 0;
}
