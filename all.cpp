/** Author::  Unmesh Kumar   **/
/** Indian Institute of Technology,Roorkee CSE'22   **/

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
#define cc(x,y) ll x,y;cin>>x>>y
#define ccc(x,y,z) ll x,y,z; cin>>x>>y>>z
#define db long double
#define fast cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false)
#define inf 200000000000000
#define mod 1000000007
#define eps 1e-7
#define PI 3.1415926535897932385
#define pb push_back
#define bitc  __builtin_popcountll
#define mp make_pair
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define len(x) (ll)(x).size()
#define fr(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define rep(i,n) for (ll i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (ll i = n - 1; i >= 0; i--)
#define frr(i,a,b) for (ll i = (a), _b = (b); i >= _b; i--)
#define foreach(it,ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define print(arr,n) rep(i,n) cout<<arr[i]<<" "; cout<<endl
#define print2(arr,n,m) rep(i,n){ rep(j,m) cout<<arr[i][j]<<" "; cout<<endl; }
#define dyn1(arr,n) ll* arr=new ll[n]; rep(i,n) arr[i]=0;
#define dyn2(arr,n,m) ll** arr=new ll*[(n)]; rep(i,n) arr[i]=new ll[m]; rep(i,n) rep(j,m) arr[i][j]=0
#define carr(arr,n) rep(i,n) cin>>arr[i]
#define carr2(arr,n,m) rep(i,n) rep(j,m) cin>>arr[i][j]
#define debug(a) cout<<" :: "<<#a<<" == "<<a<<endl
#define debug2(a,b) cout<<" :: "<<#a<<" == "<<a<<" :: "<<#b<<" == "<<b<<endl
typedef pair<int,int> ii;
typedef vector<ii> vii;

void swap(ll &a,ll &b)
{
  ll temp=a;
  a=b;
  b=temp;
}

inline ll maxim(ll a,ll b) {if(a>b) return a; else return b;}
inline ll minim(ll a,ll b) {if(a<b) return a; else return b;}
inline bool equals(double a, double b){ return fabs(a - b) < 1e-9; }
ll gcd(ll a, ll b){ return b==0 ? a : gcd(b, a%b); }

map<ll,ll> x;
ll pow_of_3(ll n)
{
	ll t = n;
	if(x[n]) return x[n];
	ll res = 1, base = 3;
	while(n>0)
  {
		if(n%2==1)
    {
      res = (res*base)%mod;
    }
		base = (base*base)%mod;
		n = n>>1;
	}
  x[t] = res;
  return x[t];
}


int main()
{
  fast;
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cout<<setprecision(10)<<fixed;
  c(t);
  rep(o,t)
  {
    c(n);
    if(n==1) cout<<1<<endl;
    else
    {
	    ll c = n%3;
	    ll n1;
	    if(c==2) n1 = (n-2)/3;
	    else if(c==1) n1 = (n-4)/3;
	    else n1 = n/3;
	    ll ans = pow_of_3(n1);
	    if(n%3==2) ans = (ans*2)%mod;
	    else if(n%3==1)  ans = (ans*4)%mod;
	    cout<<ans<<endl;
    }
  }
  return 0;
}
