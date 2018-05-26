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
 
bool compare(pair<pr,ll> a,pair<pr,ll> b)
{
	if(a.first.first!=b.first.first)
		return a.first.first<b.first.first;
	return a.first.second>b.first.second;
}
vector<pair<pr,ll> > v;
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
		ll l,r;cin>>l>>r;
		v.pb(mp(mp(l,r),i));
	}

	sort(v.begin(),v.end(),compare);
/*
	for(auto i:v)
		cout<<i.second<<" "<<i.first.first<<" "<<i.first.second<<"\n";
*/
	ll maxi=v[0].first.second;ll ind=v[0].second;
	repn(i,1,n)
	{
		if(v[i].first.second<=maxi)
			{
				
				cout<<v[i].second+1<<" "<<ind+1;return 0;}
		if(v[i].first.second>=maxi)
		{
			maxi=v[i].first.second;ind=v[i].second;
		}
		
	}
	cout<<"-1 -1";


}