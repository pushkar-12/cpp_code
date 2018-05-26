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
const int LEVEL=20; 

ll timed,sz[ee5],dep[ee5],ok[ee5],st[ee5],ANS[ee5],CNT[ee5],name[ee5];
vector<vpr> q(ee5);vvi g(ee5);ll n;
map<ll,ll> mapt[ee5];
void dfs(ll v)
{
	ok[timed]=v;st[v]=timed;timed++;
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
	{if(sz[i]>mx){mx=sz[i];big=i;}}	

	for(auto i:g[v])
	{if(i==big)continue;dfs2(i,0);}
	
	if(~big){dfs2(big,1);}
	

	for(auto i:g[v])
	{
		if(i==big)continue;
		for(ll timed=st[i];timed<st[i]+sz[i];timed++)
		{	int ver=ok[timed];
			int dept=dep[ver];
		if(mapt[dept].count(name[ver]) and mapt[dept][name[ver]]>0)
			{mapt[dept][name[ver]]++;}
		else
			{CNT[dept]++;mapt[dept][name[ver]]=1;}}
	}


	if(mapt[dep[v]].count(name[v]) and mapt[dep[v]][name[v]]>0)
		{mapt[dep[v]][name[v]]++;}
	else
		{CNT[dep[v]]++;mapt[dep[v]][name[v]]=1;}
		

	for(auto i:q[v]){
	ANS[i.second]=CNT[i.first];}
	
	if(keep==0)
		for(ll timed=st[v];timed<st[v]+sz[v];timed++)
		{
			if(mapt[dep[ok[timed]]].count(name[ok[timed]]) and mapt[dep[ok[timed]]][name[ok[timed]]]==1)
				CNT[dep[ok[timed]]]--;
			mapt[dep[ok[timed]]][name[ok[timed]]]--;
		}
}

ll pow73[22];
ll HASH;
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	rep(i,21)
	pow73[i]=(i==0?1:pow73[i-1]*73)%MOD;

	cin>>n;
	repn(i,1,n+1){string s;cin>>s;HASH=0;rep(i,s.length()){HASH=(HASH+pow73[i]*s[i])%MOD;} 
	name[i]=HASH;ll p;cin>>p;g[p].pb(i);}

	n++;
	
	dfs(0);ll m;cin>>m;
	rep(i,m)
	{
		ll v,h;cin>>v>>h;
		q[v].pb(mp(h+dep[v],i));
	}

	dfs2(0,1);
	rep(i,m)cout<<ANS[i]<<"\n";
}