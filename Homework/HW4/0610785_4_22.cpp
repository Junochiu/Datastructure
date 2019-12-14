#include "0610785_4_22.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
class calldata
{
	public:
		int callnum;
		int arrivetime;
};

class callstatus
{
	public:
		int callnum;
		int arrivetime;
		int starttime;
		int svctime;
};
//clock is the current time 
//callnum is the last occupied callnumber
int main()
{
	srand(time(NULL));
	
	for(int i=0;i<2;i++)
	{
		int hours[2]={120,120};
		int maxtime[2]={2,5};
		int totalcall=0;
		int totsvctime=0;
		int totwaittime=0;
		int maxquesize=0;
		int totalidletime=0;
		int quesize=0;
		int endtime=hours[0]; 
 		int clock=0;
		int callnum=-1;
		bool morecall=false;
		QUEUE* que;
		que=createQueue();
		callstatus *status = new callstatus();
		
		
		cout<<"case "<<i+1<<" ----------------------------------------------------------"<<endl<<endl;
		cout<<" the length of time the service is "<<hours[i]<<"min"<<endl; 
		cout<<" the maximum time it takes for the operator to take an order is "<<maxtime[i]<<endl; 
	
		cout<<setw(12)<<"clocktime"<<setw(12)<<"callnumber"<<setw(12)<<"arrivetime"<<setw(12)<<"starttime"<<setw(12)<<"svctime"<<setw(12)<<"waittime"<<setw(12)<<"quesize"<<endl;
		
		//the timing loop
		while((clock<=endtime)||(morecall))
		{
			//create new call by random
			if(clock<=endtime)
			{
				int x=rand()%10;
				if(x>4)
				{
					callnum++;
					calldata *data = new calldata();
					data->arrivetime = clock;
					data->callnum = callnum;
					enqueue(que,data);
				}			 
			
			}
			
			//see sever is free or not
			if(clock > (status->starttime + status->svctime-1))
			{
				
				if(!emptyQueue(que))
				{
					calldata *temp;
					dequeue(que,(void**)&temp);
					status->callnum = temp->callnum;
					status->arrivetime = temp->arrivetime;
					status->starttime = clock;
					status->svctime = rand()%maxtime[i]+1; 
					morecall = true;
				}
				else
				{
					totalidletime++;
					morecall = false;
				}	
			}
			
			//see whether the current call complete or not
			if(clock==(status->starttime + status->svctime -1))
			{
				int waittime = status->starttime - status->arrivetime;
				totalcall++;
				totsvctime = totsvctime + status->svctime;
				totwaittime = totwaittime + waittime;
				quesize = que->count;
				if(quesize > maxquesize)
					maxquesize = quesize;
			
				cout<<setw(12)<<clock<<setw(12)<<status->callnum<<setw(12)<<status->arrivetime<<setw(12)<<status->starttime<<setw(12)<<status->svctime<<setw(12)<<waittime<<setw(12)<<quesize<<endl;
				morecall = false;
			}
			
			//see whether there is call in queue or not
			if(!emptyQueue(que))
				morecall = true;
			
			clock++;
		}
		//printing status----------------------------------------------------------------------------------------------------------
		cout<<"Total calls "<<totalcall<<endl;
		cout<<"Total idle time "<<totalidletime<<endl;
		cout<<"Total wait time "<<totwaittime<<endl;
		cout<<"Total service time "<<totsvctime<<endl;
		cout<<"Max que size "<<maxquesize<<endl;
		cout<<"Avg wait time "<<(((float)totwaittime)/((float)totalcall))<<endl;
		cout<<"Avg service time "<<(((float)totsvctime)/((float)totalcall))<<endl;
		destroyQueue(que);
	}
	return 0;
}


