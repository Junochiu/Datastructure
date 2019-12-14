#include <iostream>
using namespace std;
long long int c(int n,int k)
{
	if(k==n||k==0)
		return 1;
	else 
		return c(n-1,k)+c(n-1,k-1);
}
int main() 
{
	int n,k;
	cout<<"calculate c(n,k)"<<endl;
	cout<<"input n : ";
	cin>>n;
	cout<<"input k : ";
	cin>>k;
	cout<<"c("<<n<<","<<k<<") = "<<c(n,k);
	return 0;
}

