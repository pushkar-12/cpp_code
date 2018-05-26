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
const int LVL=20;

vvi g(N); 
int par[N][LVL];
int dep[N],sz[N];


void dfs(int v,int p)
{
	for(auto vv:g[v])
	{if(vv==p)continue;par[vv][0]=v;dep[vv]=dep[v]+1;dfs(vv,v);sz[v]+=sz[vv];}
	sz[v]++;
}

void pre(int n)
{
	mem(par,-1);dfs(0,-1);
	for(int level=1;level<LVL;level++)
	{rep(v,n)
	if(~par[v][level-1])par[v][level]=par[par[v][level-1]][level-1];}
}

int lca(int u,int v)
{
	if(dep[v]<dep[u])swap(u,v);
	int diff=dep[v]-dep[u];
	rep(i,LVL)if(diff&(1<<i))v=par[v][i];
	if(u==v)return u;
	for(int i=LVL-1;i>=0;i--)
	{if(par[u][i]!=par[v][i])v=par[v][i],u=par[u][i];}

	return par[u][0];
}

inline int dist(int u,int v)	
{return dep[u]+dep[v]-2*dep[lca(u,v)];}
//-----------------------------------------------------------------------------------------------
//this is the basic layout for hld...now after this it depends on the question how it is used...


int chainNo,ptr,chainInd[N],chainHead[N],posInBase[N];
void HLD(int curNode, int prev) {
	if(chainHead[chainNo] == -1) {
		//cout<<curNode<<" "<<chainNo<<"\n";
		chainHead[chainNo] = curNode; // Assign chain head
	}
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr++; // Position of this node in baseArray which we will use in Segtree
	
	int sc = -1;
	// Loop to find special child
	for(auto v:g[curNode]) if(v != prev) {
		if(sc == -1 || sz[sc] < sz[v]) {
			sc = v;
			
		}
	}

	if(sc != -1) {// Expand the chain
		HLD(sc, curNode);}

	for(auto v:g[curNode]) if(v != prev) {
		if(sc != v) {
			// New chains at each normal node
			chainNo++;
			HLD(v, curNode);
		}
	}
}

//------------------------------------------------------------------------------------------------ 
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;cin>>n;

	rep(i,n-1){int a,b;cin>>a>>b;a--;b--;g[a].pb(b);g[b].pb(a);}
    pre(n);
	rep(i,n)chainHead[i] = -1;
	HLD(0,-1);
	
	
}