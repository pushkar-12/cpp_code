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
ll in[500005]; vpr ok,v;ll dp[500005];

ll query(ll l,ll ele)
{
	ll j=in[l],k=in[l+1];
	/*ok[j+1].second dp[j]
	ok[k+1].second dp[k]
	these two lines check if poll of llersection lies to left of current query poll ele*/
	return 1.0*(1.0*dp[j]-1.0*dp[k])/(1.0*ok[k+1].second-ok[j+1].second)<=ele;
	
} 

ll query2(ll r,ll i)
{
/*
	polls dp[in[r]] ok[in[r]+1].second
	dp[in[r-1]] ok[in[r-1]+1].second
	dp[i] ok[i+1].second
*/
	return 1.0*(1.0*dp[i]-dp[in[r]])/((1.0*ok[in[r]+1].second-ok[i+1].second))<=(1.0*dp[in[r]]-dp[in[r-1]])/((1.0*ok[in[r-1]+1].second-1.0*ok[in[r]+1].second));
}


int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n;cin>>n;
	rep(i,n){ll w,h;cin>>w>>h;v.pb(mp(w,h));}

	sort(all(v));
	ok.pb({0,0});
	rep(i,n-1)
	{if(v[i].first<=v[i+1].first and v[i].second<=v[i+1].second)in[i]=-1;}
	rep(i,n)if(~in[i])ok.pb(v[i]);

	//rep(i,ok.size())cout<<ok[i].first<<" "<<ok[i].second<<"\n";

	rep(i,n+2)in[i]=0;
	// O(n2)solution
	/*
	repn(i,1,ok.size())
	{
		dp[i] has to be calculated
		rep(j,i)
		dp[i]=min(dp[i],dp[j]+ok[j+1].second*ok[i].first);
	}*/

// need an O(n) solution
	ll l=0,r=0;
	repn(i,1,ok.size())
	{	
		while(l<r and query(l,ok[i].first))
			l++;
		//cout<<in[l]<<" "<<ok[in[l]+1].second<<" "<<ok[i].first<<"\n";
		dp[i]=dp[in[l]]+ok[in[l]+1].second*ok[i].first;

		//cout<<i<<" "<<dp[i]<<"\n";
		//now new point i to be inserted into hull
		while(l<r and query2(r,i))
			r--;
		r++;in[r]=i;		 
	}
	cout<<dp[ok.size()-1];



}