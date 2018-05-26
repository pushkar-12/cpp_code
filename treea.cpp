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
 
int c[ee5],sz[ee5],st[ee5],ok[ee5],ANS[ee5],no[ee5];
vvi g(ee5);int timed;
vector<vpr>q(ee5);set<pr>sto;
void dfs(int v,int p)
{
	ok[timed]=v;
	st[v]=timed;timed++;
	for(auto i:g[v])
	{
		if(i==p)continue;
		dfs(i,v);
		sz[v]+=sz[i];
	}
	sz[v]++;
}

void d(int v,int p,int keep)
{
	int mx=-1,big=-1;
	for(auto i:g[v])
	{
		if(i!=p and mx>sz[i])
		{mx=sz[i];big=i;}
	}

	for(auto i:g[v])
	{
		if(i==p or i==big)continue;
		d(i,v,0);
	}
	if(~big)
		d(big,v,1);

	for(auto i:g[v])
	{
		if(i==big)continue;
		for(int timed=st[i];timed<st[i]+sz[i];timed++)
		{
			if(sto.find(mp(no[c[ok[timed]]],c[ok[timed]]))!=sto.end())
			sto.erase(mp(no[c[ok[timed]]],c[ok[timed]]));no[c[ok[timed]]]++;
			sto.insert(mp(no[c[ok[timed]]],c[ok[timed]]));
		}
	}
			if(sto.find(mp(no[c[v]],c[v]))!=sto.end())
			sto.erase(mp(no[c[v]],c[v]));no[c[v]]++;
			sto.insert(mp(no[c[v]],c[v]));

	rep(i,q[v].size())
	{
		ANS[q[v][i].second]=distance(sto.lower_bound(mp(q[v][i].first,-1)),sto.end());
	}

	if(keep==0)
		for(int timed=st[v];timed<st[v]+sz[v];timed++)
			{int ver=ok[timed];
			sto.erase(mp(no[c[ver]],c[ver]));no[c[ver]]--;
			if(no[c[ver]])
			sto.insert(mp(no[c[ver]],c[ver]));}



}
 
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;cin>>n>>m;
	rep(i,n)cin>>c[i];
	rep(i,n-1){int a,b;cin>>a>>b;a--;b--;g[a].pb(b);g[b].pb(a);}
	rep(i,m)
	{
		int v,k;cin>>v>>k;v--;
		q[v].pb(mp(k,i));
	}
	dfs(0,-1);

	d(0,-1,1);
	rep(i,m)cout<<ANS[i]<<"\n";
}	