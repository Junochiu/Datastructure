#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "0610785_6_48.h"
using namespace std;
typedef struct treenode
{
	char data;
	int weight;
	treenode* right;
	treenode* left;
}TREENODE;

int compare(void* a,void* b)
{
	if(((TREENODE*)a)->weight >= ((TREENODE*)b)->weight)
		return 1;
	else
		return -1;
}
 
buildhuff(TREENODE** huff)
{
	//read the weight for each char from the weight.txt file
	fstream file;
	LIST* list;
	list=createList(compare);
	file.open("weight.txt",ios::in);
	if(!file)
	{
		cout<<"cannot open file \n";
		return 0;
	}
	
	char data;
	int weight;
	while(file>>data>>weight)
	{
		TREENODE* newnode=new TREENODE();
		newnode->left=NULL;
		newnode->right=NULL;
		newnode->weight=weight;
		newnode->data=data;
		addNode(list,newnode);
	}
	
	cout<<endl;
	cout<<endl;
	
	while(list->count>1)
	{
		TREENODE *newnode=new TREENODE();
		_delete(list,NULL,list->head,(void**)&newnode->left);
		_delete(list,NULL,list->head,(void**)&newnode->right);
		newnode->weight=newnode->left->weight+newnode->right->weight;
		newnode->data='!';
		addNode(list,newnode);
	}
	TREENODE* tmp;
	traverse(list,0,(void**)&tmp);
	(*huff)=tmp;
}

void printhuff(TREENODE* huff,string& str,string *storage)
{
	if(huff)
	{
		if(huff->left)
		{
			str=str+'0';
			printhuff(huff->left,str,storage);
		}
		
		if(huff->data!='!')
		{
			cout<<setw(8)<<huff->data<<" "<<setw(12)<<str;
			storage[huff->data - 'A']=str;
			cout<<endl;
		}
		
		
		if(huff->right)
		{
			str=str+'1';
			printhuff(huff->right,str,storage);
		}
		str=str.substr(0,str.length()-1);
		
		
	}
	
}

void hufftostring(TREENODE* huff,string str)
{
	TREENODE* startpoint=huff;
	while(!str.empty())
	{
		if(huff->data!='!')
		{
			cout<<huff->data;
			huff=startpoint;
		}
		else if(str[0]=='1')
		{
			huff=huff->right;
			str=str.substr(1,str.length()-1);
		}
		else if(str[0]=='0')
		{
			huff=huff->left;
			str=str.substr(1,str.length()-1);
		}
	}
	cout<<huff->data;
}

int main()
{
	int x;
	cout<<"#6-48 HUFFMAN CODE \n";
	cout<<"the Huffman code is built as follows \n";
	TREENODE *huff=new TREENODE();
	buildhuff(&huff); 
	string str;
	string storage[26];
	cout<<setw(20)<<"HUFFMAN CODE"<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<endl;
	printhuff(huff,str,storage);
	cout<<"-----------------------------------"<<endl;
	cout<<"you can input a UPPERCASE string to see the huff code version"<<endl;
	string string1;
	cin>>string1;
	for(int i=0;i<string1.length();i++)
	{
		cout<<storage[(int)string1[i]-'A'];
	}
	cout<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<"or you can input a huff code version to see the UPPERCASE string"<<endl;
	string string2;
	cin>>string2;
	hufftostring(huff,string2);
	return 0;
}
