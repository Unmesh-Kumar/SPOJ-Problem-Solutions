#include <iostream>
#include <stack>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		stack<char> list;//+, -, *, /, ^ 
		string out="";
		for(int i=0;i<s.length();i++)
		{
			char c=s[i];
			if(c=='(')  list.push(c);
			else if(c=='+')
			{
				if(list.top()=='+') out+=c; 
				else list.push(c);
			}
			else if(c=='-')
			{
				while((list.top()=='-')||(list.top()=='+'))
				{
					char f=list.top();
					list.pop();
					out=out+f;
				}
				list.push(c);
			}
			else if(c=='*')
			{
				while((list.top()=='-')||(list.top()=='+')||(list.top()=='*'))
				{
					char f=list.top();
					list.pop();
					out=out+f;
				}
				list.push(c);
			}
			else if(c=='/')
			{
				while((list.top()=='-')||(list.top()=='+')||(list.top()=='*')||(list.top()=='/'))
				{
					char f=list.top();
					list.pop();
					out=out+f;
				}
				list.push(c);
			}
			else if(c=='^')
			{
				while((list.top()=='-')||(list.top()=='+')||(list.top()=='*')||(list.top()=='/')||(list.top()=='^'))
				{
					char f=list.top();
					list.pop();
					out=out+f;
				}
				list.push(c);
			}
			else if(c==')')
			{
				while(list.top()!='(')
				{
					char f=list.top();
					list.pop();
					out=out+f;
				}
				list.pop();
			}
			else out+=c;
			
			
			
		}
		cout<<out<<endl;
	}
	return 0;
}
