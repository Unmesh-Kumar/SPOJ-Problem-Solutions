////////////////<------------- Xorcestor_X -------------->////////////////
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#include <sstream>
#include <algorithm>
#include <map>
#include <iterator>
#include <queue>
#include <utility>
#include <set>
#include <deque>
#include <string>

using namespace std;
#define endl "\n"
#define ll long long int
#define c(x) ll x;cin>>x
#define cc(x,y) ll x,y;cin>>x>>y
#define ccc(x,y,z) ll x,y,z; cin>>x>>y>>z
#define db long double
#define fast cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false)
#define inf 1e16
#define mod 1000000007
#define mod2 998244353
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
#define print(arr,n) cout<<" :: "<<#arr<<" :: "<<endl; rep(i,n) cout<<arr[i]<<" "; cout<<endl
#define carr(arr,n) fr(i,0,n-1) cin>>arr[i]

ll n,k;
ll arr[1000010];

ll func(ll gap)
{
  ll count=0;
  ll pre=-inf;
  rep(o,n)
  {
    if(arr[o]-pre>=gap)
    {
      pre=arr[o];
      count++;
    }
  }

  if(count>=k) return true;
  else return false;
}

ll bs(ll low,ll high,ll target)
{
  while(low+4<high)
  {
    ll mid=(low+high)/2;
    //increasing function with inclusion
    if(func(mid))
    {
      low=mid;
    }
    else
    {
      high=mid-1;
    }
  }

  frr(o,high,low)
  {
    if(func(o)) return o;
  }

  return -1;
}



int main()
{
  fast;

  // #ifndef ONLINE_JUDGE
  // // for getting input from input.txt
  // freopen("input.txt", "r", stdin);
  // // for writing output to output.txt
  // freopen("output.txt", "w", stdout);
  // #endif

  c(t);
  while(t--)
  {
    cin>>n>>k;
    carr(arr,n);
    sort(arr,arr+n);
    ll maxo=arr[n-1]-arr[0];
    cout<<bs(1,maxo,0)<<endl;
  }
  return 0;
}
