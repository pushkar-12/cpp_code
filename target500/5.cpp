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

const int LVL=22;

vvi g(ee5); 
int par[ee5][LVL];
int dep[ee5];
vi ok[ee5][LVL];
void dfs(int v,int p)
{
	for(auto i:g[v])
	{
		if(i==p)continue;
		par[i][0]=v;
		dep[i]=dep[v]+1;
		dfs(i,v);
	}
}

void go(vi &a,vi &b,vi &result)
{
	int idxa=0,idxb=0;
	while(idxa<a.size() and idxb<b.size() and result.size()<10)
		{if(a[idxa]<b[idxb])result.pb(a[idxa++]);else result.pb(b[idxb++]);}
	while(idxa<a.size() and result.size()<10)result.pb(a[idxa++]);
	while(idxb<b.size() and result.size()<10)result.pb(b[idxb++]);
}

void pre(int n)
{
	mem(par,-1);
	dfs(0,-1);

	for(int level=1;level<LVL;level++)
	{
		rep(v,n)
		{
			if(~par[v][level-1])
			par[v][level]=par[par[v][level-1]][level-1];
		}
	}

	for(int i=1;i<LVL;i++)
	{
		rep(v,n)
		{
			//ok[v][i] is a vector from v to 2^(i-1) parent
			//ok[v][1] is a vector from v to immediate parent
			//	merge ok[v][i-1] and ok[par[v][i-1]][i-1] to get ok[v][i]
			
			if(i==1 and v)
			ok[v][1]=ok[par[v][0]][0];
			if(i>1 and ~par[v][i-1])
			go(ok[v][i-1],ok[par[v][i-2]][i-1],ok[v][i]);
		}
	}
}


int lca(int u,int v)
{
	if(dep[v]<dep[u])
		swap(u,v);
	int diff=dep[v]-dep[u];

	for(int i=0;i<LVL;i++)
	{
		if(diff&(1<<i))
			v=par[v][i];

	}
	if(u==v)return u;

	for(int i=LVL-1;i>=0;i--)
	{
		if(par[u][i]!=par[v][i])
			v=par[v][i],u=par[u][i];
	}
	return par[u][0];
}

void ans(int u,int v,int a)
{
	int anc=lca(u,v);
	vi temp1=ok[u][0];
	vi temp2=ok[v][0];
	
	int diff=dep[u]-dep[anc];
	for(int i=0;i<LVL;i++)
	{
		vi temp;
		if((1<<i)&diff)
			{go(temp1,ok[u][i+1],temp);
			temp1=temp;u=par[u][i];
			
		}
		
	}
	diff=dep[v]-dep[anc];
	
	for(int i=0;i<LVL;i++)
	{
		vi temp;
		if((1<<i)&diff)
			{go(temp2,ok[v][i+1],temp);
			temp2=temp;v=par[v][i];
		}
	}
	set<int>s;int cnt=0;
	for(auto i:temp1)s.insert(i);
	for(auto i:temp2)s.insert(i);
	if(s.size()>a)cout<<a<<" ";else cout<<s.size()<<" ";
	for(auto i:s){cout<<i+1<<" ";cnt++;if(cnt==a)break;}cout<<"\n";
	
}
 
int c[ee5];
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;cin>>n;
	int m,q;cin>>m>>q;

	rep(i,n-1){int a,b;cin>>a>>b;a--;b--;g[a].pb(b);g[b].pb(a);}
	rep(i,m){cin>>c[i];c[i]--;if(ok[c[i]][0].size()<10)ok[c[i]][0].pb(i);}

	pre(n);
	while(q--)
	{int v,u,a;cin>>v>>u>>a;v--;u--;ans(u,v,a);}
}