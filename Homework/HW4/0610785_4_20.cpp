#include <queue>
#include <iostream>
using namespace std;
string to_string(int x)
{
	string str;
	while(x)
	{
		str=((char)(x%10+'0'))+str;
		x/=10;
	}
	return str;
}
int to_int(string str)
{
	int num=0;
	for(int i=0;i<str.length();i++)
	{
		num=num*10+(str[i]-'0');
	}
	return num;
}
int main(){
	string prefix;
	string op;
	string num1,num2;
	queue<string> que;
	queue<string> temp;
	cout<<"input prefix expression = ";
	getline(std::cin,prefix);
	queue<string> forprint;
	
	for(int i=0;i<prefix.length();)
	{
		string str="";
		int temp=0;
		if(prefix[i]=='+'||prefix[i]=='-'||prefix[i]=='*'||prefix[i]=='/')
		{
			str+=prefix[i];
			que.push(str);
			str="";	
			i++;
		}
		else if(prefix[i]==' ')
			i++;
		else{
			while(prefix[i]!=' ' && i<prefix.length())
			{
				temp=temp*10+(prefix[i]-'0');
				i++;
			}
			que.push(to_string(temp));
			temp=0;	
		}
		
	}
	
	
	while(temp.size()!=1)
	{
		while(!temp.empty())
			temp.pop();
		bool isop = false;
		bool isnum1 = false;
		bool isnum2 = false;
		string num1,num2,op;
		while(!que.empty())
		{
			
			if(isop&&isnum1&&isnum2)
			{
				int tmp;
				if(op=="+")
					tmp=to_int(num1)+to_int(num2);
				else if(op=="-")
					tmp=to_int(num1)-to_int(num2);
				else if(op=="*")
					tmp=to_int(num1)*to_int(num2);
				else if(op=="/")
					tmp=to_int(num1)/to_int(num2);
				temp.push(to_string(tmp));
				
				isop=false;
				isnum1=false;
				isnum2=false;
			}
			else if(isop&&isnum1)
			{
				if((que.front()!="+")&&(que.front()!="-")&&(que.front()!="*")&&(que.front()!="/")) 
				{
					isnum2=true;
					num2=que.front();
					que.pop();
				}
				else
				{
					temp.push(op);
					temp.push(num1);
					isop=true;
					isnum1=false;
					op=que.front();
					que.pop();
				}
			}
			else if(isop)
			{
				if((que.front()!="+")&&(que.front()!="-")&&(que.front()!="*")&&(que.front()!="/"))
				{
					isnum1=true;
					num1=que.front();
					que.pop();
				}
				else
				{
					temp.push(op);
					isop=true;
					op=que.front();
					que.pop();
				}
			}
			else
			{
				if((que.front()!="+")&&(que.front()!="-")&&(que.front()!="*")&&(que.front()!="/"))
				{   
					temp.push(que.front());
					que.pop();
				}
				else
				{ 
					isop=true;
					op=que.front();
					que.pop();
				}
			}
		
		}
		
		if(isop&&isnum1&&isnum2)
		{
			int tmp;
			if(op=="+")
				tmp=to_int(num1)+to_int(num2);
			else if(op=="-")
				tmp=to_int(num1)-to_int(num2);
			else if(op=="*")
				tmp=to_int(num1)*to_int(num2);
			else if(op=="/")
				tmp=to_int(num1)/to_int(num2);
			temp.push(to_string(tmp));
				
			isop=false;
			isnum1=false;
			isnum2=false;
		}
		
		queue<string> forprint;
		forprint=temp;
		que=temp;
	}
	cout<<"ans = "<<to_int(temp.front());
	return 0;
}
 
