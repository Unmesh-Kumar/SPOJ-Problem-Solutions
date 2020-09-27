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
#define print2(arr,n,m) cout<<" :: "<<#arr<<" :: "<<endl; rep(i,n){ rep(j,m) cout<<arr[i][j]<<" "; cout<<endl; }
#define dyn1(arr,n) ll* arr=new ll[n]; rep(i,n) arr[i]=0;
#define dyn2(arr,n,m) ll** arr=new ll*[(n)]; rep(i,n) arr[i]=new ll[m]; rep(i,n) rep(j,m) arr[i][j]=0
#define carr(arr,n) fr(i,0,n-1) cin>>arr[i]
#define carr2(arr,n,m) fr(i,0,n-1) fr(j,0,m-1) cin>>arr[i][j]
#define debug(a) cout<<" :: "<<#a<<" == "<<a<<endl
#define debug2(a,b) cout<<" :: "<<#a<<" == "<<a<<" :: "<<#b<<" == "<<b<<endl
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define debugx(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debugx("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef pair<ll,ll> pii;
typedef vector<pii> vii;
const ll N = 105;
typedef ll mt[N][N];

inline ll maxim(ll a,ll b) {if(a>b) return a; else return b;}
inline ll minim(ll a,ll b) {if(a<b) return a; else return b;}
inline bool equals(double a, double b){ return fabs(a - b) < 1e-9; }
ll gcd(ll a, ll b) { return b==0 ? a : gcd(b, a%b); }

ll reduce(ll a,ll m)
{
  a%=m;
  a+=m;
  a%=m;
  return a;
}

ll Extended_gcd(ll a,ll b,ll& x,ll& y)
{
  if(a==0)
  {
    x=0;
    y=1;
    return b;
  }
  else
  {
    ll x1,y1;
    ll g=Extended_gcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return g;
  }
}

bool leap(ll y)
{
  if(y%400==0) return true;
  if((y%4==0)&&(y%100!=0)) return true;
  return false;
}

ll isprime(ll n)
{
  if(n==1) return false;
  if(n==2) return true;
  if(n%2==0) return false;
  for(int i=3;i*i<=n;i+=2)
  {
    if(n%i==0) return false;
  }
  return true;
}


bool prime[2000010];
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    prime[1]=false;
    for (int p=2; p*p<=2000001; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=2000001; i += p)
                prime[i] = false;
        }
    }
}



// vector<ll> prime_vec[1000010];
// void modified_SieveOfEratosthenes()
// {
//     //prime[1]=false;
//     for (int p=2; p*p<=1000001; p++)
//     {
//         if (prime_vec[p].size()==0)
//         {
//             for (int i=p*2; i<=1000001; i += p)
//                 prime_vec[i].pb(p);
//         }
//     }
// }







////*** Various Exponentiation Functions ***////

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

// ll result[1000010];
// ll tempo[1000010];
// ll per[1000010];
//
//
// void permutation_exp(ll n,ll x)
// {
//   fr(o,1,n)
//   {
//     result[o]=o;
//   }
//
//   while(x>0)
//   {
//     if(x&1)
//     {
//       fr(o,1,n)
//       {
//         tempo[o]=result[o];
//       }
//
//       fr(o,1,n)
//       {
//         result[o]=tempo[per[o]];
//       }
//     }
//
//     fr(o,1,n)
//     {
//       tempo[o]=per[o];
//     }
//
//     fr(o,1,n)
//     {
//       per[o]=tempo[tempo[o]];
//     }
//     x>>=1;
//   }
// }

ll len;
ll ultimate[110][110];

void matrix_exp(ll arr[100][110],ll n)
{
  //ll len=4;
  ll res[110][110];
  rep(o,len)
  {
    rep(p,len)
    {
      if(o!=p)
      res[o][p]=0;
      else
      res[o][p]=1;
    }
  }

  ll temp[110][110];

  while(n)
  {
    if(n&1)
    {
      rep(x,len)
      {
        rep(y,len)
        {
          temp[x][y]=0;
        }
      }

      fr(i,0,len-1)
      {
        fr(j,0,len-1)
        {
          fr(z,0,len-1)
          {
            temp[i][j]+=reduce(res[i][z]*arr[z][j],mod);
          }
        }
      }

      fr(i,0,len-1)
      {
        fr(j,0,len-1)
        {
          res[i][j]=reduce(temp[i][j],mod);
        }
      }
    }

    rep(x,len)
    {
      rep(y,len)
      {
        temp[x][y]=0;
      }
    }

    fr(i,0,len-1)
    {
      fr(j,0,len-1)
      {
        fr(z,0,len-1)
        {
          temp[i][j]+=reduce(arr[i][z]*arr[z][j],mod);
          temp[i][j]%=mod;
        }
      }
    }

    fr(i,0,len-1)
    {
      fr(j,0,len-1)
      {
        arr[i][j]=reduce(temp[i][j],mod);
      }
    }

    n/=2;
  }

  fr(i,0,len-1)
  {
    fr(j,0,len-1)
    {
      ultimate[i][j]=reduce(res[i][j],mod);
    }
  }
}

//
// ll modpow(ll a, ll b,ll x)
// {
//     ll res = 1;
//     while (b > 0)
//     {
//         if (b & 1) res = (res * a)%x;
//         a = (a * a)%x;
//         b >>= 1;
//     }
//     return res;
// }
//
// ////*** End of Various Exponentiation Functions ***////
//
// int modInverse(int a, int m)
// {
//     int m0 = m;
//     int y = 0, x = 1;
//     if (m == 1)
//       return 0;
//     while (a > 1)
//     {
//         // q is quotient
//         int q = a / m;
//         int t = m;
//         // m is remainder now, process same as
//         // Euclid's algo
//         m = a % m, a = t;
//         t = y;
//         // Update y and x
//         y = x - q * y;
//         x = t;
//     }
//     // Make x positive
//     if (x < 0)
//        x += m0;
//     return x;
// }
//
// ll int_sqrt(ll h)
// {
//   ll g=(ll)sqrt(h);
//   g++;
//   if(g*g==h) return g;
//   g--;
//   if(g*g==h) return g;
//   g--;
//   if(g*g==h) return g;
//   return -1;
// }
//
//
// ll lpf[1000001] = {};
//
// void precompute()
// {
//   fr(i,2,1000000)
//   {
//     if(!lpf[i])
//     {
//       for(ll j=i;j<=1000000;j+=i)
//       {
//         if(!lpf[j])
//         lpf[j]=i;
//       }
//     }
//   }
// }
//
// ll fact[2000010];
//
// void compute_fact()
// {
//   fact[0]=1;
//   fr(o,1,2000004)
//   {
//     fact[o]=(fact[o-1]*o)%mod;
//   }
// }
//
// ll ncr_mod(ll n,ll r)
// {
//   if(r==0||n==r) return 1;
//   else return (((fact[n]*modInverse(fact[r],mod))%mod)*modInverse(fact[n-r],mod))%mod;
// }
//
//
ll f(ll x)
{
  ll total=0;
  return total;
}

ll ternary_search(ll l, ll r)
{              //set the error limit here
    while (r - l > 10)
    {
        ll m1 = l + (r - l) / 3;
        ll m2 = r - (r - l) / 3;
        ll f1 = f(m1);      //evaluates the function at m1
        ll f2 = f(m2);      //evaluates the function at m2
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    ll mino=f(l);
    ll mino_x=l;

    fr(o,l,r)
    {
      if(f(o)<mino)
      {
        mino_x=o;
        mino=f(o);
      }
    }
    return f(mino_x);
}


// // ll tree[2000010];
// // void build(ll* a,ll v,ll tl,ll tr)
// // {
// //   if(tl==tr)
// //   {
// //     tree[v]=((a[tl]==x)?1:0);
// //   }
// //   else
// //   {
// //     ll tm=(tl+tr)/2;
// //     build(a,v*2,tl,tm);
// //     build(a,v*2+1,tm+1,tr);
// //     tree[v]=tree[v*2]+tree[v*2+1];
// //   }
// // }
// //
// // ll query(ll v,ll tl,ll tr,ll l,ll r)
// // {
// //   if(l>r) return 0;
// //   if(l==tl&&r==tr) return tree[v];
// //   ll tm=(tl+tr)/2;
// //   return query(v*2,tl,tm,l,minim(r,tm))+query(v*2+1,tm+1,tr,maxim(l,tm+1),r);
// // }
// //
// //
// // void update(ll v,ll tl,ll tr,ll pos,ll new_val)
// // {
// //   if(tl==tr)
// //   {
// //     tree[v]=((arr[pos]==x)?1:0);
// //   }
// //   else
// //   {
// //     ll tm=(tl+tr)/2;
// //     if(pos<=tm) update(v*2,tl,tm,pos,new_val);
// //     else update(v*2+1,tm+1,tr,pos,new_val);
// //     tree[v]=tree[v*2]+tree[v*2+1];
// //   }
// // }
// //
// //
// // ll find_kth(ll v,ll tl,ll tr,ll k)
// // {
// //   if(k>tree[v]) return -1;
// //   if(tl==tr) return tl;
// //   ll tm=(tl+tr)/2;
// //   if(tree[v*2]>=k) return find_kth(v*2,tl,tm,k);
// //   else return find_kth(v*2+1,tm+1,tr,k-tree[v*2]);
// // }
//
//
bool opt_prime(ll n)
{
  if(n<2000000) return prime[n];
  else return isprime(n);
}


ll far[1000010];
ll farsum[1000010];

ll func(ll x)
{
  return x;
}

ll bs(ll low,ll high,ll target)
{
  while(low+4<high)
  {
    ll mid=(low+high)/2;
    //increasing function with inclusion
    if(func(mid)<=target)
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
    if(func(o)<=target) return o;
  }

  return -1;
}




ll lpfx(ll x)
{
  if(x%2==0) return 2;
  else
  {
    for(int z=3;z*z<=x;z+=2)
    {
      if(x%z==0) return z;
    }
  }
  return x;
}


ll fz(ll n)
{
  ll o=1;
  while(o<=n)
  {
    o*=2;
  }
  return o;
}

ll arr[1000010][7];
ll sign[7];
vector<pii> cont;
vector<ll> glob;

int main()
{
  fast;

  #ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for writing output to output.txt
  freopen("output.txt", "w", stdout);
  #endif

  cc(n,k);
  carr2(arr,n,k);
  rep(o,binpow(2,k))
  {
    rep(p,k)
    {
      if(o&(1<<p))
      {
        sign[p]=1;
      }
      else
      {
        sign[p]=-1;
      }
    }

    cont.clear();
    rep(o,n)
    {
      ll x=0;
      rep(p,k)
      {
        x+=arr[o][p]*sign[p];
      }
      cont.pb(mp(x,o));
    }
    sort(cont.begin(),cont.end());
    glob.pb(cont[n-1].ss);
  }

  ll maxo=0;

  rep(o,binpow(2,k))
  {
    rep(p,n)
    {
      ll x=0;
      rep(u,k)
      {
        x+=abs(arr[glob[o]][u]-arr[p][u]);
      }
      maxo=maxim(maxo,x);
    }
  }

  cout<<maxo<<endl;

  return 0;
}
