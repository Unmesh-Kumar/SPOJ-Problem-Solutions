/////////// <----------------------  QuickSilver ---------------------> ///////////

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
#include <set>
#include <cstring>

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
typedef pair<ll,ll> pii;
typedef vector<pii> vpii;

inline ll maxim(ll a,ll b) {if(a>b) return a; else return b;}
inline ll minim(ll a,ll b) {if(a<b) return a; else return b;}
inline bool equals(double a, double b){ return fabs(a - b) < 1e-9; }
ll gcd(ll a, ll b){ return b==0 ? a : gcd(b, a%b); }


bool prime[3001];
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    prime[1]=false;
    for (int p=2; p*p<=3000; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=3000; i += p)
                prime[i] = false;
        }
    }
}

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

// ll gcd(ll a,ll b,ll& x,ll& y)
// {
//   if(a==0)
//   {
//     x=0;
//     y=1;
//     return b;
//   }
//   else
//   {
//     ll x1,y1;
//     ll g=gcd(b%a,a,x1,y1);
//     x=y1-(b/a)*x1;
//     y=x1;
//     return g;
//   }
// }

ll ncr(ll n,ll r)
{
  if(n<r) return 0;
  if(r==0) return 1;
  if(n==r) return 1;
  if(n-r<r) return ncr(n,n-r);
  return ncr(n-1,r)+ncr(n-1,r-1);
}

ll arr[1000010];
ll brr[1000010];

map<ll,ll> love;

ll rec(ll n)
{
  if(n<=4) return n;
  if(love.find(n)==love.end())
  {
    love[n]=maxim(n,rec(n/2)+rec(n/3)+rec(n/4));
  }
  return love[n];
}

int main()
{
  fast;
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cout<<setprecision(10)<<fixed;
  ll n;
  while(cin>>n)
  {
    ll f=rec(n/2)+rec(n/3)+rec(n/4);
    if(f>n) cout<<f<<endl;
    else cout<<n<<endl;
  }
  return 0;
}
