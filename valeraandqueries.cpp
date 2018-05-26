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
 
 const ll N=2*ee5;
 ll o=1,e=1;
 ll evenst[N],oddst[N],dep[N],firstchild[N],pos[N],ODD[N],EVEN[N],val[N];
vvi g(N);
void dfs(ll v,ll p)
{
	if(dep[v]%2){pos[v]=o;o++;}
	else {pos[v]=e;e++;}

	for(auto i:g[v])
	{
		if(i==p)continue;
		dep[i]=1+dep[v];
		dfs(i,v);
		if(firstchild[v]==-1)
		firstchild[v]=i;
		evenst[v]+=evenst[i];oddst[v]+=oddst[i];
	}
	if(dep[v]%2)oddst[v]++;else evenst[v]++;
}

ll add(ll in,ll val,ll v[])
{
	while(in<=200001)
	{
		v[in]+=val;
		in+=(in&-in);		
	}
}

ll sum(ll in,ll v[])
{
	ll s=0;
	while(in>0)
	{
		s+=v[in];
		in-=(in&-in);
	}
	return s;
}

int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	mem(firstchild,-1);

	ll n,m;cin>>n>>m;rep(i,n)cin>>val[i];
	rep(i,n-1)
	{ll x,y;cin>>x>>y;x--;y--;g[x].pb(y);g[y].pb(x);}
	dfs(0,-1);
	rep(i,m)
	{
		ll op,x;cin>>op>>x;x--;
		if(op==1)
		{
			ll val;cin>>val;
			if(dep[x]%2){
				add(pos[x],val,ODD);add(pos[x]+oddst[x],-val,ODD);
				if(firstchild[x]==-1)continue;
				add(pos[firstchild[x]],-val,EVEN);add(pos[firstchild[x]]+evenst[x],val,EVEN);
			}
			else
			{	
				add(pos[x],val,EVEN);add(pos[x]+evenst[x],-val,EVEN);
				if(firstchild[x]==-1)continue;
				add(pos[firstchild[x]],-val,ODD);add(pos[firstchild[x]]+oddst[x],val,ODD);
			}

		}
		else
		{
			if(dep[x]%2)
				cout<<val[x]+sum(pos[x],ODD)<<"\n";
			else cout<<val[x]+sum(pos[x],EVEN)<<"\n";
		}
	}



	
}