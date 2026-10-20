#include<iostream>
using namespace std;

int graph[20][20];
int visited[20];
int n;

void DFS(int v)
{
    cout << v << " ";
    visited[v] = 1;

    for(int i=0;i<n;i++)
    {
        if(graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

void BFS(int start)
{
    int queue[20];
    int front = 0;
    int rear = 0;

    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
    }

    queue[rear] = start;
    rear++;
    visited[start] = 1;

    while(front < rear)
    {
        int v = queue[front];
        front++;

        cout << v << " ";

        for(int i=0;i<n;i++)
        {
            if(graph[v][i] == 1 && visited[i] == 0)
            {
                queue[rear] = i;
                rear++;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    cin >> n;

    int edges;
    cin >> edges;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j] = 0;
        }
    }

    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    cin >> start;

    for(int i=0;i<n;i++)
    {
        visited[i] = 0;
    }

    cout << "DFS: ";
    DFS(start);

    cout << endl;

    cout << "BFS: ";
    BFS(start);

    cout << endl;

    return 0;
}