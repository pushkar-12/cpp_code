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
#define ff first
#define ss second

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
 
vector<vpr> g(2*ee5);vector<pair<pr,ll> >edges;

struct djs{
	ll N;
	vi rank,parent;
	djs(const ll n):N(n){rank.resize(N),parent.resize(N);rep(i,N)parent[i]=i;}
	ll par(ll v)
	{return (parent[v]==v)?v:(parent[v]=par(parent[v]));}
	void merge(ll v1,ll v2)
	{
		ll vp1=par(v1),vp2=par(v2);
		if(vp1==vp2)return;
		if(rank[vp1]>rank[vp2]){parent[vp2]=vp1;}
		else {parent[vp1]=vp2;if(rank[vp1]==rank[vp2])rank[vp2]++;}
	}
};

int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	ll n,m;cin>>n>>m;djs dj=djs(n);

	rep(i,m){ll u,v,we;cin>>u>>v>>we;u--;v--;g[u].pb({v,we});g[v].pb({u,we});edges.pb({{u,v},we});}
	
	sort(all(edges),[](const auto lhs,const auto rhs){return (lhs.ss<rhs.ss);});

	ll W=0;
	rep(i,edges.size())
	{ll st=edges[i].ff.ff,en=edges[i].ff.ss;ll w=edges[i].ss;if(dj.par(st)==dj.par(en))continue;
		dj.merge(st,en);W+=w;}

	cout<<W;

}