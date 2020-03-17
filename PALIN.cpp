#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int start=0;
		int end=s.length()-1;
		bool b=false;
		while((start!=end)&&(start+1!=end))
		{
			if(s[start]>s[end]){s[end]=s[start]; b=true;}
			if(s[start]<s[end]){s[end]=s[start]; b=false;}
			start++;
			end--;
			
		}
		if(start==end)
		{
			if(!b)
			{
				if(s[start]=='9')
				{
					while((s[start]=='9')&&(s[end]=='9'))
					{
						if(start!=0)
						{
						start--;
						end++;
						}
						else
						{
							break;
						}
					}
					if((start==0)&&((s[start]=='9')&&(s[end]=='9')))
					{
						string p="1";
							for(int u=0;u<s.size()-1;u++)
							{
								p+='0';
							}
							p+='1';
							s=p;
					}
					else{
					s[start]++;
					s[end]=s[start];
					}
					for(int j=start+1;j<end;j++)
					{
						s[j]='0';
					}
				}
				else
				{
					s[start]++;
				}
			}
		}
		if(end==start+1)
		{
			if(b&&(s[start]==s[end]))
			{
				if(s[start]>=s[end]) s[end]=s[start];
				else
				{
					s[start]++;
					s[end]=s[start];
				}
			}
			else if(!b)
			{
				if(s[start]>s[end]) s[end]=s[start];
				else if((s[start]=='9')&&(s[end]=='9'))
				{
					while((s[start]=='9')&&(s[end]=='9'))
					{
						if(start!=0)
						{
						start--;
						end++;
						}
						else
						{
							break;
						}
					}
					if((start==0)&&((s[start]=='9')&&(s[end]=='9')))
					{
						string p="1";
							for(int u=0;u<s.size()-1;u++)
							{
								p+='0';
							}
							p+='1';
							s=p;
					}
					else{
					s[start]++;
					s[end]=s[start];
					}
					for(int j=start+1;j<end;j++)
					{
						s[j]='0';
					}
				}
			
				else if (s[start]==s[end])
				{
					s[start]++;
					s[end]++;
				}
				else if(s[start]<s[end])
				{
					s[start]++;
					s[end]=s[start];
				}
			}
		}
		cout<<s<<endl;
	}
	
	return 0;
}
