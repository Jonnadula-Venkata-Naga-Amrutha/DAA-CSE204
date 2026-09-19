#include <stdio.h>
int ne=1,min,mincost=0;
int parent[50];
int a,b,u,v;
int find(int i)
{
    while(parent[i]!=i)
    {
        i=parent[i];
    }
    return i;
}
int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    int adj[50][50];
    printf("Enter number of vertices = ");
    scanf("%d",&n);
    printf("Enter edge weights in adjacency matrix form:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
            if(adj[i][j]==0)
            {
                adj[i][j]=9999;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    printf("\nEdges in Minimum Spanning Tree:\n");
    while(ne<n)
    {
        min=9999;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj[i][j]<min)
                {
                    min=adj[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u, v))
        {
            printf("%d edge (%d, %d) = %d\n",ne++,a,b,min);

            mincost+=min;
        }
        adj[a][b]=adj[b][a]=9999;
    }
    printf("\nMinimum Cost = %d\n", mincost);
    return 0;
}