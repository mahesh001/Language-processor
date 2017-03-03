#include<iostream>
#include<cstring>
#include<string>
using namespace std;
 int main()
 {
 	int n;
 	cout<<"enter the number of the production \n";
 	cin>>n;
 	char *t[n];
 	char *p[n];
 	for(int i=0;i<n;i++)
 	p[i]=new char[10];
 		for(int i=0;i<n;i++)
 	t[i]=new char[10];
 
 	cout<<"enter the production rules";
 	//cout<<"enter the variable and press enter";
 	for(int i=1;i<=n;i++)
 	{
 		cout<<"rule"<<i<<"\n";
 		cin>>t[i-1];
 		cout<<"derives";
 		cin>>p[i-1];
 	}
 	cout<<"rules are ";
 	for(int i=0;i<n;i++)
 	{
 		cout<<t[i]<<"->"<<p[i]<<"\n";
 		
 	}
    char*c;
 	c=new char[10];
 	cout<<" enter the string";
 	cin>>c;
 	int b=strlen(c);
 	string str[b+2][b+2];
 	for(int i=0;i<b;i++)
 	{
 		
 		for(int j=0;j<n;j++)
 		{
 			if(strlen(p[j])==1 && p[j][0]==c[i])
 			{
 				str[1][j].append(t[j]);
 			}
 		}
 	}
 	for(int i=2;i<=b;i++)
 	{
 		
 		for(int m=0;m<b-i+1;m++)
 		{
 			for(int j=1;j<=b;j++)
 			{
 				for(int k=1;k<=b;k++)
 				{
 					
 					if(j+k==i)
 					{
 						
 						for(int u=0;u<str[j][m].length();u++)
 						{
 							cout<<"aa";
 							for(int v=0;v<str[k][m+j].length();v++)
 							{
 								cout<<"aa";
 								char a[3];
 								a[0]=str[j][m][u];
 								a[1]=str[k][m+j][v];
 								a[2]='\0';
 								for(int z=0;z<n;z++)
 								{
 									cout<<"aa";
 									if(strcmp(p[z],a)==0)
 									{
 										int bb;
 										for(bb=0;bb<str[i][m].length();bb++)
 										{
 											cout<<"aa";
 											if(t[z][0]==str[i][m][bb])
 											break;
 										}
 										cout<<"aa";
 										if(bb==str[i][m].length())
 										str[i][m].append(t[z]);
 										cout<<"aa";
 									}
 								}
 							}
 						}
 					}
 				}
 			}
 		}
 	}
 	cout<<"\n table is \n";
 	for(int i=1;i<=b;i++)
 	{
 		cout<<"lenght"<<i<<" ";
 		for(int j=0;j<b-i+1;j++)
 		{
 			cout<<str[i][j]<<"\t\t";
 		}
 		cout<<endl;
 	}
 	int e;
 	for(e=0;e<str[b][0].length();e++)
 	{
 		if(str[b][0][e]=='S')
 		{
 			cout<<"string is accepted by the language \n";
			 break;
		}
		if(str[b][0].length()==0||e==str[b][0].length())
		cout<<"string is not accepted by the language ";
 	}
 	return 0;
 	
 }


