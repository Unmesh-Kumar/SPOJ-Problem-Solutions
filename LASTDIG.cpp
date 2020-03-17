#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <iterator>
#include <iomanip>
#include <queue>
#include <utility>
using namespace std;
#define ll long long int
#define c(x) ll x;cin>>x

int main()
{
  //fast;
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cout<<setprecision(10)<<fixed;
  c(n);
  while(n--)
  {
    ll a,b;
    cin>>a>>b;
    a=a%10;
    if(a==0)
    {
      cout<<0<<endl;
    }
    else if(b==0)
    {
      cout<<1<<endl;
    }
    else
    {
      b=((b-1)%4)+1;
      cout<<(ll)pow(a,b)%10<<endl;
    }
  }
  return 0;
}
