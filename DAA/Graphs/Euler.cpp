#include <iostream>
using namespace std;

void euler(int graph[5][5])
{
	int degree[5];
	for(int k=0;k<5;k++)
	{
		degree[k]=0;
	}
	for(int i =0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(graph[i][j]==1)
			{
				degree[i]++;	
			}	
		}
		cout<<"degree for "<<i<< " is "<<degree[i]<<endl;
	}
	int counter=0;
	for(int i =0;i<5;i++)
	{
		if(degree[i]%2!=0)
		{
		counter	++;
		}
	}
	
	if(counter==0)
	{
		cout<<"Eulerian circuit exists!"<<endl;
	}
	
	if(counter!=0 and counter<=2)
	{
		cout<<"Eulerian path exists!"<<endl;
	}
}
int main()
{
	/*int graph [5][5]={{0,1,1,1,0},
					{1,0,1,0,0},
					{1,1,0,0,0},
					{1,0,0,0,1},
					{0,0,0,1,0}}*/;
	
	int graph[5][5] = {{0, 1, 1, 1, 1},
   {1, 0, 1, 0, 0},
   {1, 1, 0, 0, 0},
   {1, 0, 0, 0, 1},
   {1, 0, 0, 1, 0}};
					
	euler(graph);
}

