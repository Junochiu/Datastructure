#include <iostream>
using namespace std;
long long int iterativefac(int n)
{
	int ans=1;
	for(int i=n;i>0;i--)
	{
		ans*=i;
	}
}
int main()
{
	int n;
	cout<<"calculate factorial n!"<<endl;
	cout<<"input n : ";
	cin>>n;
	cout<<"ans = "<<iterativefac(n);
	return 0;
	
} 
