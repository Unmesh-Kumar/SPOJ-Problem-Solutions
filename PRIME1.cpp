#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	int n,m;
	cin>>n>>m;
	int x=n;
	while(x<=m)
	{
		if (x%2==0&&x>3) x++;
		bool b=true;
		
		for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) {b=false; break;}
		if(b&&x!=1) cout<<x<<endl;
		if(x>7) x++;
		x++;
	}
	cout<<endl;
	}
	return 0;
}
