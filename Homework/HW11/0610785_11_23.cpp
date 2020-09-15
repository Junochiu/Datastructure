#include "0610785_11_23_graph.h"
#include <iostream>
using namespace std;
int compare(void *a,void*b)
{
	if((char*)a==(char*)b)
		return 0;
	return 1;
}

void printgraph(GRAPH* graph)
{
	VERTEX* vertex;
	vertex = graph->first;
	ARC*        arc;
	while(vertex)
	{
		if (!vertex->intree)
            continue;
        arc = vertex->pArc;
        while (arc){
            if (arc->intree)
            	cout<<(char *)vertex->dataPtr<<" - "<<(char *)arc->destination->dataPtr<<" ";
            arc = arc->pNextArc;
        }
        vertex = vertex->pNextVertex;
    }
    return;
}
void shortestpath(GRAPH* graph)
{
	VERTEX* vertex;
	ARC* arc;
	ARC* minEdgeLoc = NULL;
	ARC* pathLoc = NULL;
	int minPath;
	int minEdge;
	int newPathLen = INT_MAX;
	bool treecomplete = false;
	
	vertex=graph->first;
	while(vertex)
	{
		vertex->intree=false;
		vertex->pathLength=INT_MAX;
		arc=vertex->pArc;
		while(arc)
		{
			arc->intree=false;
			arc=arc->pNextArc;
		}
		vertex=vertex->pNextVertex;
	}
	//derive minimum path tree
	vertex = graph->first;
	vertex->intree=true;
	vertex->pathLength=0;
	treecomplete = false;
	while(!treecomplete)
	{
		treecomplete = true;
		minEdgeLoc = NULL;
		pathLoc = NULL;
		newPathLen = INT_MAX;
		vertex = graph->first;
		while(vertex)
		{
			if(vertex->intree==true && vertex->outDegree>0)
			{
				minPath = vertex->pathLength;
				minEdge = INT_MAX;
				arc = vertex->pArc;
				while(arc)
				{
					if(arc->destination->intree==false)
					{
						treecomplete = false;
						if(arc->weight<minEdge)
						{
							minEdge=arc->weight;
							minEdgeLoc = arc;
						}
					}
					arc=arc->pNextArc;
				}
				if(minPath+minEdge<newPathLen)
				{
					newPathLen = minPath + minEdge;
					pathLoc = minEdgeLoc;
				}
			}
			vertex=vertex->pNextVertex;
		}
		if(pathLoc!=NULL)
		{
			pathLoc->intree = true;
			pathLoc->destination->intree = true;
			pathLoc->destination->pathLength = newPathLen;
		}
	}
	//print final cost
	cout<<"complete shortest path search \n";
}

int main()
{
	//create graph
	GRAPH *graph;
	graph=(GRAPH*)malloc (sizeof(GRAPH));
	graph->count=0;
	graph->first=NULL;
	graph->compare=compare;
	//must create graph here!
	cout<<"# 11-23 shortest path \n";
	cout<<"original graph looks like this:\n";
	cout<<"in this format (u,v,weight)\n";
	cout<<"(A,B,1) (B,D,3) (B,C,1) (C,D,1) (A,C,4)\n";
	cout<<"------------------------------------------------------\n";
	graphInsVrtx (graph, (void*)"A");
    graphInsVrtx (graph, (void*)"B");
    graphInsVrtx (graph, (void*)"C");
    graphInsVrtx (graph, (void*)"D");
    graphInsArc (graph, (void*)"A", (void*)"B", 1);
    graphInsArc (graph, (void*)"B", (void*)"C", 1);
	graphInsArc (graph, (void*)"A", (void*)"C", 4);
	graphInsArc (graph, (void*)"B", (void*)"D", 3);
	graphInsArc (graph, (void*)"C", (void*)"D", 1);
	shortestpath(graph);
	printgraph(graph);
} 
