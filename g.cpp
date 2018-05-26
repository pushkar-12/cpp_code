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

bool compare(pair<pr,pr>a,pair<pr,pr>b)
{
    if(a.first.first==b.first.first) return a.first.second<=b.first.second;
    return a.first.first<b.first.first;
}
vector<vector<pair<pr,pr> > >ok(ee5);
vector<pair<pr,pr> >v;
vi g;int sum[ee5];
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;cin>>n;
	int x;cin>>x;
	rep(i,n)
	{
	    int u,np,bp,ts;cin>>u>>np>>bp>>ts;
	    v.pb(mp(mp(-bp,np),mp(u,ts)));
	}
	int players;cin>>players;
	sort(all(v),compare);

	rep(i,v.size())
	cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second.first<<" "<<v[i].second.second<<"\n";	

	int prev=-1;int in=-1;
	rep(i,n)
	{
	   if(v[i].first.first!=prev) {prev=v[i].first.first;in++;}
	   
	   ok[in].pb(v[i]);
	   sum[in]+=v[i].first.second;
	}



	int ans=-1;
	rep(i,ok.size())
	{
		if(players>=ok[i].size())
			players-=sum[in];
		else{
			for(int j=ok[i].size()-1;j>=players;j--)
				g.pb(ok[i][j].second.first);

			players=0;}
		if(players<=0)
			{ans=i+1;break;}

	}
	
	if(ans!=-1)
		for(int i=ans;i<ok.size();i++)
		{
			for(int j=0;j<ok[i].size();j++)
			{
				g.pb(ok[i][j].second.first);
			}
		}
		sort(all(g));
		rep(i,g.size())
		cout<<g[i]<<" ";

	




}