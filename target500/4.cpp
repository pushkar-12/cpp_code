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

vector<vpr>g(ee5);
vector<vpr>grev(ee5);

struct Djikstra{

	vi dist;
	int source;
	vi done;
	vector<vpr> g;
	Djikstra(int n,int &source_,vector<vpr> &gr):source(source_){
		dist.resize(n,INF);done.resize(n,0);
		g=gr;
	}

	void compute()
	{
		//cout<<source<<"  l ";
		set<pr>st;
		st.insert({0,source});

		while(!st.empty())
		{
			pr x=*st.begin();
			dist[x.ss]=x.ff;
			done[x.ss]=1;
			//cout<<x.ss<<" ";
			st.erase(st.begin());
			for(auto v:g[x.ss])
			{
				if(done[v.ff])continue;
				if(st.find({dist[v.ff],v.ff})!=st.end())
				{
					if(dist[v.ff]>x.ff+v.ss)
						{
							st.erase({dist[v.ff],v.ff});dist[v.ff]=x.ff+v.ss;
							st.insert({dist[v.ff],v.ff});
						}
				}
				else {st.insert({x.ff+v.ss,v.ff});dist[v.ff]=x.ff+v.ss;}
			}

			//for(auto i:st)
			//	cout<<i.first<<" "<<i.second<<"\n";cout<<"---------------------------------\n";
		}
	}

	void printdist()
	{
		rep(i,dist.size())cout<<i<<" "<<dist[i]<<"\n";
	}

};
bool visited[ee5];int disc[ee5],low[ee5],parent[ee5];map<pair<pr,ll>,ll>mt;
void findbridges(int u, vector<vpr>&g)
{
    static int time = 0;
    visited[u] = true;
 
    disc[u] = low[u] = ++time;
 
    for(auto p:g[u])
    {

        int v = p.ff;  // v is current adjacent of u
        int len=p.ss;
 		cout<<v<<" ";
        if (!visited[v])
        {
            parent[v] = u;
            findbridges(v, g);
 
            low[u]  = min(low[u], low[v]);
            if (low[v] > disc[u]){
            	
              mt[{{u,v},len}]=1;}
        }
 
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}


vector<vpr>okg(ee5);
vector<pair<pr,ll> >ok;
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
		g[a].pb({b,l});
		grev[b].pb({a,l});
		ok.pb({{a,b},l});
	}
	Djikstra dj1=Djikstra(n,s,g);
	Djikstra dj2=Djikstra(n,t,grev);
	dj1.compute();dj2.compute();
	int base=dj1.dist[t];

	rep(i,m)
	{
		int start=ok[i].ff.ff;
		int end=ok[i].ff.ss;
		int len=ok[i].ss;
		
		int req=dj1.dist[start]+dj2.dist[end]+len-base;
		if(req==0)
			okg[start].pb({end,len}),okg[end].pb({start,len});
	}

	findbridges(s,okg);

	rep(i,m)
	{
		int start=ok[i].ff.ff;
		int end=ok[i].ff.ss;
		int len=ok[i].ss;

		int req=dj1.dist[start]+dj2.dist[end]+len-base+1;
		
		if(req==1 and mt.count({{start,end},len}))cout<<"YES\n";
		else if(req>=len)cout<<"NO\n";
		
		else cout<<"CAN "<<req<<"\n";
	}
}