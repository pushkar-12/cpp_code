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

vpr v;vi r,g,b;
ll finish1,finish2; 
vi rg,bg;
ll go(ll first,ll last)
{
	ll i;
	ll st=first;
	ll ans=-(ll)100*INF;
	for(i=finish1;i<r.size();i++)
	{
		if(r[i]>first and r[i]<last)
			{ans=max(ans,(ll)r[i]-st);
			st=r[i];}
		if(r[i]>last)break;
	}
	finish1=i;

	if(ans==-(ll)100*INF)return 0;
	return max(ans,last-st);
}


ll go2(ll first,ll last)
{
	ll i;
	ll st=first;
	ll ans=-(ll)100*INF;
	for(i=finish2;i<b.size();i++)
	{
		if(b[i]>first and b[i]<last)
			{ans=max(ans,(ll)b[i]-st);
			st=b[i];}

		if(b[i]>last)break;
	}
	finish2=i;

	if(ans==-(ll)100*INF)return 0;
	return max(ans,last-st);
}



int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	ll n;cin>>n;
	rep(i,n)
	{
		ll x;char ch;cin>>x>>ch;
		if(ch=='R'){v.pb({x,1});r.pb(x);rg.pb(x);}
		else if(ch=='B'){v.pb({x,2});b.pb(x);bg.pb(x);}
		else {v.pb({x,0});g.pb(x);rg.pb(x);bg.pb(x);}
	}

	ll opti=0;
	rep(i,g.size())
	{
		if(i==g.size()-1)break;//cout<<g[i]<<"\n";
		ll dist1=go(g[i],g[i+1]);
		ll dist2=go2(g[i],g[i+1]);
//		cout<<dist1<<" "<<dist2<<"\n";

		if(dist1+dist2>g[i+1]-g[i])
			opti-=(dist1+dist2-(g[i+1]-g[i]));
	}


	rep(i,rg.size())
	{
		if(i==rg.size()-1)
			break;
		opti+=rg[i+1]-rg[i];

	}


	rep(i,bg.size())
	{
		if(i==bg.size()-1)
			break;
		opti+=bg[i+1]-bg[i];

	}

	rep(i,g.size())
	{
		if(i==g.size()-1)
			break;
		opti-=g[i+1]-g[i];
	}
	cout<<opti;
}	