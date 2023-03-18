// 547. Number of Provinces
// Medium

/* 
# Question
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

/***********************
 **  Ibraheem Rehman  **
 **  SE-Q    21i-1102 **
***********************/
 
#include<iostream>
using namespace std;
 
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
