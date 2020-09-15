#include<iostream>
#include<vector>

#define GOAL 'O'

using namespace std;
typedef struct node 
{
	char data;
	vector<char> adj;
	bool visited;
}GRAPH_NODES;
void createmap(vector<GRAPH_NODES*> &map)
{
	/*create the map
	1.save all the adjacency data into each graph_node 
	2.save all the graph_node into a graph 
	  The corresponding vertex id = (GRAPH_NODES->data-'A') 
	*/
	//graphnode A
	GRAPH_NODES* newnode = new GRAPH_NODES();
	newnode->data='A'; 
	(newnode->adj).push_back('B');
	newnode->visited=false;
	map.push_back(newnode);
	//graphnode B
	newnode = new GRAPH_NODES();
	newnode->data='B'; 
	(newnode->adj).push_back('A');
	(newnode->adj).push_back('E');
	(newnode->adj).push_back('C');
	newnode->visited=false;
	map.push_back(newnode);
	//graphnode C
	newnode = new GRAPH_NODES();
	newnode->data='C'; 
	(newnode->adj).push_back('B');
	(newnode->adj).push_back('D');
	(newnode->adj).push_back('G');
	newnode->visited=false;
	map.push_back(newnode);
	//graphnode D
	newnode = new GRAPH_NODES();
	newnode->data='D'; 
	newnode->visited=false;
	map.push_back(newnode);
	//graphnode E
	newnode = new GRAPH_NODES();
	newnode->data='E'; 
	(newnode->adj).push_back('B');
	(newnode->adj).push_back('G');
	(newnode->adj).push_back('F');
	newnode->visited=false;
	map.push_back(newnode);
	//graphnode F
	newnode = new GRAPH_NODES();
	newnode->data='F'; 
	(newnode->adj).push_back('E');
	(newnode->adj).push_back('G');
	(newnode->adj).push_back('H');
	newnode->visited=false;
	map.push_back(newnode);
	//graphnode G
	newnode = new GRAPH_NODES();
	newnode->data='G'; 
	(newnode->adj).push_back('E');
	(newnode->adj).push_back('F');
	(newnode->adj).push_back('C');
	newnode->visited=false;
	map.push_back(newnode);
	//graphnode H
	newnode = new GRAPH_NODES();
	newnode->data='H'; 
	(newnode->adj).push_back('F');
	(newnode->adj).push_back('I');
	(newnode->adj).push_back('J');
	newnode->visited=false;
	map.push_back(newnode);	
	//graphnode I
	newnode = new GRAPH_NODES();
	newnode->data='I'; 
	newnode->visited=false;
	map.push_back(newnode);
	//graphnode J
	newnode = new GRAPH_NODES();
	newnode->data='J'; 
	(newnode->adj).push_back('H');
	(newnode->adj).push_back('K');
	(newnode->adj).push_back('L');
	newnode->visited=false;
	map.push_back(newnode);
	//graphnode K
	newnode = new GRAPH_NODES();
	newnode->data='K'; 
	(newnode->adj).push_back('J');
	newnode->visited=false;
	map.push_back(newnode);
	//graphnode L
	newnode = new GRAPH_NODES();
	newnode->data='L'; 
	(newnode->adj).push_back('M');
	(newnode->adj).push_back('N');
	(newnode->adj).push_back('O');
	newnode->visited=false;
	map.push_back(newnode);
	//graphnode M
	newnode = new GRAPH_NODES();
	newnode->data='M'; 
	(newnode->adj).push_back('L');
	newnode->visited=false;
	map.push_back(newnode);
	//graphnode N
	newnode = new GRAPH_NODES();
	newnode->data='N'; 
	(newnode->adj).push_back('L');
	newnode->visited=false;
	map.push_back(newnode);
	//graphnode O
	newnode = new GRAPH_NODES();
	newnode->data='O'; 
	(newnode->adj).push_back('L');
	newnode->visited=false;
	map.push_back(newnode);
	return;
}
void findexit(vector<GRAPH_NODES*> &map)
{
	bool exitfound=false;
	int i=0;
	vector<int> path;
	vector<int> nextmove;
	
	
	while(!exitfound)
	{
		//cout<<"in the loop";
		map[i]->visited=true;
		path.push_back(i);
		cout<<"currentpath : ";
		for(int j=0;j<path.size();j++)
		{
			if(path[j]==-1)
				cout<<"-1";
			else 
				cout<<map[path[j]]->data<<" ";
		}
		cout<<"\n";
		if(map[i]->data==GOAL)
		{
			cout<<endl;
			cout<<"final path\n";
			exitfound=true;
			for(int j=0;j<path.size();j++)
				if(path[j]!=-1)
					cout<<map[path[j]]->data<<" ";
		}
		else if(map[i]->data=='D'||map[i]->data=='N'||map[i]->data=='K'||map[i]->data=='I')
		{
			while(path[path.size()-1]!=-1)
			{
				path.pop_back();
			}
			if(path.size()!=0 && path[path.size()-1]==-1)
				path.pop_back();
			i=nextmove[nextmove.size()-1];
			nextmove.pop_back();
		}
		else
		{
			for(int j=0;j<(map[i]->adj).size();j++)
			{
				int count=0;
				char neighbor=(map[i]->adj)[j];
				if(!map[neighbor-'A']->visited)
				{
					nextmove.push_back(neighbor-'A');
					count++;
				}
				if(count>=2)
				{
					for(int i=0;i<count-1;i++)
						path.push_back(-1);
				}
			}
			i=nextmove[nextmove.size()-1];
			nextmove.pop_back();			
		}
	}
	return;
}
int main()
{
	//create map
	vector<GRAPH_NODES*> map;
	createmap(map);
	//cout<<"map created";
	cout<<"# 11-27 map walking using DFS";
	findexit(map);
	return 0;
}
