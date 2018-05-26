#include <bits/stdc++.h>
 
#if DEBUG && !ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...)
#endif
 
using namespace std;
 
/*******  All Required define Pre-Processors and typedef Constants *******/
#define scd(t) scanf("%d",&t)
#define scld(t) scanf("%ld",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define mem(a, b) memset(a, (b), sizeof(a))
#define repd(i,k) for(ll i=k;i>=0;i--)
#define rep(i,k) for(ll i=0;i<k;i++)
#define repn(i,k1,k2) for(ll i=k1;i<=k2;i++)
 
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define ee6 (ll)1000001
#define ee5 (ll)100001
#define read(type) readInt<type>()
#define tt ll t;cin>>t; while(t--)
typedef long long int ll;
 
typedef pair<ll, ll> pr;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<pr> vpr;
typedef vector<vpr>vvpr;
typedef vector<vi> vvi;
typedef map<ll,ll> MPII;
typedef set<ll> SETI;
typedef multiset<ll> MSETI;

/*This template is for dynamic hull which allows line of any slope to be added at any time
to the existing hull*/


bool cmpA;
struct Line {
   ll a, b;
   mutable long double xl;
   bool operator < (const Line &l) const { if (cmpA) return a < l.a; else return xl < l.xl; }
};
/* this implementation maintains MAX convex hull and multiset contains lines in increasing order of 
slopes hence to obtain MIN, insert lines reflected with respect to X-axis (-m,-c) in the hull*/
struct DynamicHull : multiset<Line> {

	vector<pair<ll, ll> > everything;
   bool bad (iterator y) {
      iterator z = next(y), x;
      if (y == begin()) {
         if (z == end()) return 0;
         return y->a == z->a && y->b <= z->b;
      }
      x = prev(y);
      if (z == end()) {
         return y->a == x->a && y->b <= x->b;
      }
      return 1.0L * (x->b - y->b) * (z->a - y->a) >= 1.0L * (y->b - z->b) * (y->a - x->a);
   }
   void add (ll a, ll b) {
   		everything.push_back({a, b});
   		a *= -1;b *= -1; //uncomment these to obtain min
      cmpA = 1;
      iterator y = insert((Line){a,b,-INF});
      if (bad(y)) { erase(y); return; }
      while (next(y) != end() && bad(next(y))) erase(next(y));
      while (y != begin() && bad(prev(y))) erase(prev(y));
      if (next(y) != end()) next(y)->xl = 1.0L * (y->b - next(y)->b) / (next(y)->a - y->a);
      if (y != begin()) y->xl = 1.0L * (y->b - prev(y)->b) / (prev(y)->a - y->a);
   }
   ll eval (ll x) {
      if (empty()) return INF;
      cmpA = 0;
      iterator it = prev(lower_bound((Line){0,0,1.0L*x}));
      return -(it->a * x + it->b);// add a -ve sign to obtain min
   }
};


vvi g(ee5);
DynamicHull *dh[ee5];
ll dp[ee5],st[ee5],ok[ee5],sz[ee5],a[ee5],b[ee5];
ll timed;
void dfs(ll v,ll ver)
{
   st[v]=timed;ok[timed]=v;timed++;
   for(auto i:g[v])
   {
      if(i==ver)continue;
      dfs(i,v);
      sz[v]+=sz[i];
   }
   sz[v]++;
}

void dfs2(ll v,ll ver,ll keep)
{
   ll maxi=-1,heavy=-1;
   for(auto i:g[v])   {
      if(i==ver)continue;
      if(sz[i]>maxi)
         {maxi=sz[i];
         heavy=i;}
   }
   for(auto i:g[v])
   {
      if(i==ver or heavy==i)continue;
      dfs2(i,v,0);
   }
   if(heavy!=-1){dfs2(heavy,v,1);dh[v]=dh[heavy];}

   else {dh[v]=new DynamicHull();dh[v]->add(b[v],0);return;}
   
   for(auto i:g[v])
   {
      if(i==heavy or i==ver)continue;
      for(ll timed=st[i];timed<st[i]+sz[i];timed++)
      {
         dh[v]->add(b[ok[timed]],dp[ok[timed]]);

      }
   }
   
   dp[v]=dh[v]->eval(a[v]);
   dh[v]->add(b[v],dp[v]);
}  

int main()
{
   #if !ONLINE_JUDGE

   freopen("in.txt","r",stdin);
   #endif
//   ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  

   ll n;cin>>n;
   rep(i,n)cin>>a[i];rep(i,n)cin>>b[i];   

   rep(i,n-1){ll x,y;cin>>x>>y;x--;y--; g[x].pb(y);g[y].pb(x);}
   dfs(0,-1);
   
   dfs2(0,-1,0);
   rep(i,n)cout<<dp[i]<<" ";

}