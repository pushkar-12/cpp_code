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
#define repn(i,k1,k2) for(ll i=k1;i<k2;i++)
#define sz(x) (ll)(x).size()
#define first ff
#define second ss

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
 
const int N=ee5;

vvi g(N);int st[N],sz[N],clocked[N];

int timed=0;
void pre(int v,int p)
{
	st[v]=timed;clocked[timed]=v;timed++;
	for(auto vv:g[v])
	{if(vv==p)continue;pre(vv,v);sz[v]+=sz[vv];}
	sz[v]++;
}
map<int,int>mt;
int cnt[N],maxi[N],c[N];
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
    if(bigChild != -1)
        {dfs(bigChild, v, 1);cnt[v]=cnt[bigChild],maxi[v]=maxi[bigChild];}// bigChild marked as big and not cleared from cnt
    for(auto u : g[v])
	if(u != p && u != bigChild)
	    for(int timed = st[u]; timed < st[u]+sz[u]; timed++)
		{/*here we are traversing the subtrees of lighter childs of v*/
	    	mt[c[clocked[timed]]]++;
	    	if(mt[c[clocked[timed]]]>maxi[v])maxi[v]=mt[c[clocked[timed]]],cnt[v]=c[clocked[timed]];
	    	else if(mt[c[clocked[timed]]]==maxi[v]) cnt[v]+=c[clocked[timed]];
		}
		
	mt[c[v]]++;
	if(mt[c[v]]>maxi[v])maxi[v]=mt[c[v]],cnt[v]=c[v];
	else if(mt[c[v]]==maxi[v])cnt[v]+=c[v];
    /*here you need to consider contribution of v itself*/

    if(keep == 0)
        for(int p = st[v]; p < st[v]+sz[v]; p++)
        {mt[c[clocked[p]]]--;}	
	    /*if v was a light child of its parent remove its contribution*/
}

int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	int n;cin>>n;rep(i,n)cin>>c[i];
	rep(i,n-1)
	{int a,b;cin>>a>>b;a--;b--;g[a].pb(b);g[b].pb(a);}

	pre(0,-1);
	dfs(0,-1,0);rep(i,n)cout<<cnt[i]<<" ";
}