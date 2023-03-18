
void dfs(int **isConnected, int isConnectedSize, int *isConnectedColSize, int *visited, int i)
{
    for (int j = 0; j < isConnectedSize; j++)
    {
        if (visited[j] == 0 && isConnected[i][j] == 1)
        {
            visited[j] = 1;
            dfs(isConnected, isConnectedSize, isConnectedColSize, visited, j);
        }
    }
}

int findCircleNum(int **isConnected, int isConnectedSize, int *isConnectedColSize)
{
    int count = 0;
    int *visited = (int *)malloc(sizeof(int) * isConnectedSize);
    // purpose of isconnectedcolsize is to get the size of the array in the array of arrays (isconnected) so that we can use it in the for loop below to initialize the visited array

    for (int i = 0; i < isConnectedSize; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < isConnectedSize; i++)
    {
        if (visited[i] == 0)
        {
            dfs(isConnected, isConnectedSize, isConnectedColSize, visited, i);
            count++;
        }
    }

    return count;
}
