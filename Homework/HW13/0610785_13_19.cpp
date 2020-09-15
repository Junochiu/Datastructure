#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include "0610785_13_19.h"
using namespace std;
#define TABLE_SIZE 4

typedef struct {
    int partNum;
    int quantity;
} INVENTORY;

int compare(void* argu1, void* argu2);

int main() {
    LIST* hashList[TABLE_SIZE];
    vector<INVENTORY*> array;
    for(int i = 0; i < TABLE_SIZE; i++)
        hashList[i] = createList(&compare);

    FILE* inFile = fopen("0610785.txt", "r");

    int partNum, quantity, totalNode = 0;
    while(fscanf(inFile, "%d %d", &partNum, &quantity) != EOF) {
        totalNode++;

        INVENTORY* newPart = (INVENTORY*)malloc(sizeof(INVENTORY));
        newPart->partNum = partNum;
        newPart->quantity = quantity;
		array.push_back(newPart);
        addNode(hashList[partNum%TABLE_SIZE], newPart);
    }

    fclose(inFile);
	while(1)
	{
		int choice;
		cout<<"------------------------------------------------------------------------------------\n";
		cout<<"# 13-19 choose the following function you want and input the corresponding number\n";
		cout<<"1 search for an inventory item for quantity sold\n";
		cout<<"2 Print the inventory parts and the corresponding quantities sold\n";
		cout<<"3 Analyze the efficiency of the hashing algorithm\n";
		cout<<"4 exit\n";
		cout<<"input your choice";
		cin>>choice;
		switch(choice)
		{
			case 1:{
			
				int searchNum;
    			printf("Please enter a part number to search: ");
    			scanf("%d", &searchNum);

    			bool found = false;
    			for(int i = 0; i < TABLE_SIZE; i++) {
        			if(!emptyList(hashList[i])) {
            			NODE* walk = hashList[i]->head;
            			for(int j = 0; j < hashList[i]->count; j++) {
                			if(((INVENTORY*)(walk->dataPtr))->partNum == searchNum) {
                    			printf("Part number \"%d\" has sold \"%d\" in the past month.\n\n", ((INVENTORY*)(walk->dataPtr))->partNum, ((INVENTORY*)(walk->dataPtr))->quantity);
                    			found = true;
                    			break;
                				}
                			walk = walk->link;
            				}
        				}
        			if(found)
            			break;
    			}
				break;
			}
			case 2:{
				cout<<setw(8)<<"part #"<<setw(10)<<"Quantity\n";
				for(int i=0;i<array.size();i++)
				{
					cout<<setw(8)<<array[i]->partNum<<setw(10)<<array[i]->quantity<<endl;
				}
				break;
			}
			case 3:{
				 // Show all content in the hash table
    			printf("Home Addr\tPrime Area\tOverflow List\n");
    			for(int i = 0; i < TABLE_SIZE; i++) {
        			// Print home address
        			printf("%9d\t", i);

        			if(!emptyList(hashList[i])) {
            		// Print prime area
            			printf("%5d/%-4d\t", ((INVENTORY*)(hashList[i]->head->dataPtr))->partNum, ((INVENTORY*)(hashList[i]->head->dataPtr))->quantity);

            		// If there are overflow list
            			if(hashList[i]->count > 1) {
                			NODE* walk = hashList[i]->head->link;
                			for(int j = 0; j < (hashList[i]->count) - 1; j++) {
                    			printf("%d/%d ", ((INVENTORY*)(walk->dataPtr))->partNum, ((INVENTORY*)(walk->dataPtr))->quantity);
                    			walk = walk->link;
                			}
            			}
        			}
        		printf("\n");
    			}
    			printf("\n");

    			int primeCount = 0, listCount = 0, longest = 0;
   				for(int i = 0; i < TABLE_SIZE; i++) {
        			if(!emptyList(hashList[i])) {
            			primeCount++;
            			if(hashList[i]->count > 1)
                			listCount ++;
            			if(hashList[i]->count > longest)
                			longest = hashList[i]->count;
        			}
    			}

    			printf("Percentage of prime area filled: %5.1f %%\n", (float)primeCount/TABLE_SIZE*100);
    			printf("Average nodes in linked list:    %5.1f node(s)\n", (float)(totalNode-primeCount)/listCount);
    			printf("Logest linked list:              %5d node(s)\n\n", longest-1);
			break;
			}
			case 4:{
				exit(0);
				break;
			}
		}
	}
    return 0;
}

int compare(void* argu1, void* argu2) {
    return 1;
}
