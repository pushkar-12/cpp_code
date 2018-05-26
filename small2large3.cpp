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
 
ll powmod(ll base,ll pow)
{
   ll res=1;
   while(pow)
   {
         if (pow%2!=0)  res=(res*base)%MOD;
         base=(base*base)%MOD;
         pow/=2;
   }
   return res;
}


ll timed=1;ll ok[ee5],st[ee5],sz[ee5],dep[ee5],CNT[ee5],pri[ee5],name[ee5],pow73[23];
vvi g(ee5);
map<ll,ll>mt [ee5];
map<ll,ll>qmp[ee5];
map<ll,ll>in[ee5];
 void dfs(ll v)
 {
 	st[v]=timed;
 	ok[timed]=v;timed++;
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
 		if(sz[i]>mx)
 			{mx=sz[i];big=i;}
 	}

 	for(auto i:g[v])
 	{if(i==big)continue;dfs2(i,0);}

 	if(big!=-1)
 		dfs2(big,1);

 	for(auto i:g[v])
 	{
 		if(i==big)continue;
 		for(ll timed=st[i];timed<st[i]+sz[i];timed++)
 		{
 			if(mt[dep[ok[timed]]].count(name[ok[timed]]) and mt[dep[ok[timed]]][name[ok[timed]]]>0);
 			else {CNT[dep[ok[timed]]]++;mt[dep[ok[timed]]]=1;}
 			if(qmp[v].count(dep[ok[timed]]-dep[v]))
 				qmp[v][dep[ok[timed]]-dep[v]]+=CNT[dep[ok[timed]]];

 		}
 	}
 	if(mt[dep[v]].count(name[v]) and mt[dep[v]][name[v]]>0)
 	mt[dep[v]][name[v]]++;
 	else {mt[dep[v]][name[v]]=1;CNT[dep[v]]++;}

 	if(keep==0)
 		for(ll timed=st[v];timed<st[v]+sz[v];timed++)
 			{
 				
 				if(mt[dep[ok[timed]]][name[ok[timed]]]==1)
 					CNT[dep[ok[timed]]]--;
 				else mt[dep[ok[timed]]][name[ok[timed]]]--;	
 				
 			}
}

vi roots;
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

	ll n;cin>>n;
	rep(i,n){string s;cin>>s;HASH=0;rep(j,s.length())HASH=(HASH+(pow73[j]*s[j]))%MOD; name[i]=HASH;ll p;cin>>p;
		p--;if(p==-1){roots.pb(i);continue;} g[p].pb(i);
	}

	ll m;cin>>m;rep(j,m){ll v,k;cin>>v>>k;v--;qmp[v][k]=0;in[v][k]=j;}

	for(auto root:roots)
	{
		dep[root]=1;timed=1;dfs(root);
		dfs2(root,0);
	}

	rep(i,n)
	for(map<ll,ll>::iterator it=qmp[i].begin();it!=qmp[i].end();it++)
	{
		pri[in[i][it->first]]=it->second;
	}
	rep(i,m)cout<<pri[i]<<"\n";



}