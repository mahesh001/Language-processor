#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n;
	cout<<"enter number of productions";
	cin>>n;
	char *l[n];
	char *r[n];
	
	
	for(int i=0;i<n;i++)
	{
	
		r[i]=new char[10];
		//for(int i=0;i<n;i++)
		l[i]=new char[10];
    }
    
    
    cout<<"enter production rules";
    //cout<<"enter variable";
    for(int i=1;i<=n;i++)
    {
    	cout<<"rule"<<" "<<i<<"\n";
    	cin>>l[i-1];
    	cout<<" derives  ";
    	cin>>r[i-1];
    }
    
    
    cout<<"production rules are \n";
    {
    	for(int i=0;i<n;i++)
    	{
    		cout<<l[i]<<"  ->  "<<r[i]<<endl;
    	}
    }
    
    
    char *c;
    c=new char[10];
    cout<<"enter the string to be checked";
    cin>>c;
    int z=strlen(c);
    string str[z+2][z+2];
    
    
    for(int i=0;i<z;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		if(strlen(r[j])==1  && r[j][0]==c[i])
    		{
    			str[1][i].append(l[j]);
    		}
    	}
    }
    for(int i=2;i<=z;i++)
    {
    	for(int m=0;m<z-i+1;m++)
    	{
    		for(int j=1;j<=z;j++)
    		{
    			for(int k=1;k<=z;k++)
    			{
    				if(j+k==i)
    				{
    					for(int x=0;x<str[j][m].length();x++)
    					{
    						for(int y=0;y<str[k][m+j].length();y++)
    						{
    							char a[3];
    							a[0]=str[j][m][x];
    							a[1]=str[k][m+j][y];
    							a[2]='\0';
    							for(int w=0;w<n;w++)
    							{
    								if(strcmp(r[w],a)==0)
    								{
    									int f;
    									for(f=0;f<str[i][m].length();f++)
    									{
    										if(l[w][0]==str[i][m][f])
    										break;
    							     	}
    									if(f==str[i][m].length())
    									str[i][m].append(l[w]);
    								
    								}
    							}
    						}
    					}
    				}
    			}
    		}
    	}
    }
    
    cout<<"\n  table  \n";
    for(int i=1;i<=z;i++)
    {
    	cout<<" length  "<<i<<"    ";
    	for(int j=0;j<z-i+1;j++)
    	{
    		cout<<str[i][j]<<"\t";
    	}
    	cout<<endl;
    }
    
    int d;
    for(int d=0;d<str[z][0].length();d++)
    {
    	if(str[z][0][d]=='S')
    	{
    
         cout<<"String is accepted by the language\n";
         break;
        }
     if(str[z][0].length()==0 || d==str[z][0].length())
      {
      	 cout<<"String is not accepted by the language\n";
      	 
      }
 }
    return 0;
}
