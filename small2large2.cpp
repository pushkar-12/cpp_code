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

 
 ll timed=1;ll ok[ee5],st[ee5],sz[ee5],dep[ee5],pow2[40],val[ee5],ANS[ee5],asd[ee5];
 map<ll,ll> mt;map<ll,ll> qmp[ee5];vvi g(ee5);map<ll,ll> in[ee5];
void dfs(ll v)
{
	ok[timed]=v;
	st[v]=timed;timed++;
	for(auto i:g[v])
	{
		dep[i]=dep[v]+1;
		dfs(i);
		sz[v]+=sz[i];

	}
	sz[v]++;
}


void dfs2(ll v,ll keep)
{
	ll mx=-1,big=-1;
	for(auto i:g[v])
	{
		if(sz[i]>mx)mx=sz[i],big=i;
	}

	for(auto i:g[v])
		if(i!=big)dfs2(i,0);
	if(big!=-1)dfs2(big,1);

	for(auto i:g[v])
	{
		if(i==big)continue;
		for(ll timed=st[i];timed<st[i]+sz[i];timed++)
		{

			ANS[dep[ok[timed]]]=ANS[dep[ok[timed]]] xor val[ok[timed]];
			if(dep[ok[timed]]==3)cout<<ok[timed]<<" "<<ANS[dep[ok[timed]]];
			 if(qmp[v].count(dep[ok[timed]]))
			 {
			 	if(mt.count(ANS[dep[ok[timed]]]) and mt[ANS[dep[ok[timed]]]]==1)
			 		qmp[v][dep[ok[timed]]]=1;
			 	else
			 		qmp[v][dep[ok[timed]]]=0;
			 }

		}
	}

	if(qmp[v].count(dep[v]))
		{qmp[v][dep[v]]=1;}
	ANS[dep[v]]=ANS[dep[v]] xor val[v];

	if(keep==0)
		for(ll timed=st[v];timed<st[v]+sz[v];timed++)
			ANS[dep[ok[timed]]]=ANS[dep[ok[timed]]] xor val[ok[timed]];
}

int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	rep(i,27)
	{pow2[i]=(i==0?1:pow2[i-1]<<1);mt[pow2[i]]=1;}
	mt[0]=1;

	ll n,m;cin>>n>>m;
	rep(i,n-1)
	{
		ll p;cin>>p;p--;
		g[p].pb(i+1);
	}

	rep(i,n){char ch;cin>>ch;val[i]=pow2[ch-97];}
	dep[0]=1;
	dfs(0);

	rep(i,m)
	{
		ll v,h;cin>>v>>h;v--;
		qmp[v][h]=1;
		in[v][h]=i;
	}

	dfs2(0,1);
	rep(i,n)
	for(map<ll,ll>::iterator it=qmp[i].begin();it!=qmp[i].end();it++)
	{
		asd[in[i][it->first]]=it->second;
	}
	rep(i,m)cout<<(asd[i]==1?"Yes":"No")<<"\n";
}