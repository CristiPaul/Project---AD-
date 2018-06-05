#include <stdio.h>
#include <stdlib.h>
#include "indegree.h"
#define MAX 100

int n;    /*Number of vertices in the graph*/
int adj[MAX][MAX]; /*Adjacency Matrix*/

int indegree(int vertice)
{
	int iterator ;
	int in_deg = 0;

	for(iterator = 0; iterator < n; iterator++)
		if(adj[iterator][vertice] == 1)
			in_deg++;

	return in_deg;
}/*End of indegree() */
