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



 

vi djikstra(int source,vector<vpr> &g,int n)
{
	vi dist;dist.resize(n);rep(i,n)dist[i]=INF;
	dist[source]=0;set<pr>ss;ss.insert({0,source});

	while(!ss.empty())
	{
		pr x=*ss.begin();
		ss.erase(ss.begin());
		for(auto i:g[x.ss])
		{
			//i.ff city  i.ss length
			//x.ff distance x.ss city
			if(ss.find({dist[i.ff],i.ff})!=ss.end()){
				if(dist[i.ff]>dist[x.ss]+i.ss)
				{ss.erase({dist[i.ff],i.ff});dist[i.ff]=dist[x.ss]+i.ss;ss.insert({dist[i.ff],i.ff});}
			}
			else {dist[i.ff]=dist[x.ss]+i.ss;ss.insert({dist[i.ff],i.ff});}
		}
	}
	return dist;

}
vector<vpr> g(ee5),grev(ee5);
vvi tmp(ee5);
int yes
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m,s,t;cin>>n>>m>>s>>t;s--;t--;

	rep(i,m)
	{
		int a,b,l;cin>>a>>b>>l;a--;b--;
		g[a].pb({b,l});grev[b].pb({a,l});roads[i]={a,b};len[i]=l;
	}

	vi fron=djikstra(s,g,n);
	vi rever=djikstra(t,grev,n);

	rep(i,n)cout<<i<<" "<<fron[i]<<"\n";cout<<"\n\n";
	rep(i,n)cout<<i<<" "<<rever[i]<<"\n";cout<<"\n\n";

	rep(i,m){if(fron[roads[i].ff]+rever[roads[i].ss]+len[i]==fron[t])yes[i]=1;mt{a,b}
		else if(len>fron[roads[i].ff]+rever[roads[i].ss]+len[i]-fron[t]+1)
			ANS[i]=fron[roads[i].ff]+rever[roads[i].ss]+len[i]-fron[t]+1;
		else ANS[i]=-1;

	}
	rep(i,m){if(yes[i]==1){tmp[roads[i].ff].pb(roads[i].ss);tmp[roads[i].ss].pb(roads[i].ff);}}



}
