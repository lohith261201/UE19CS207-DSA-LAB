#include<stdio.h>
#include "bfs.h"

int check_path(int **graph, int n, int v, int u)
{
	//TODO
int queue[n];
int temp;
int rear=-1,front=0;
int visited[n];
for(int j=0;j<n;j++)
{
visited[j]=0;
}
void bfs(int x)
{
for(int i=0;i<n;i++)
if(graph[x][i]&&!visited[i])
{
queue[++rear]=i;
}
if(front<=rear)
{
visited[queue[front]]=1;
bfs(queue[front++]);
}
}
bfs(v);
if(visited[u]==1)
{
return 1;
}
else
return 0;
}


	



