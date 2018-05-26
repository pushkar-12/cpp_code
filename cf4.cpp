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
#define INF (ll)1e9
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
 
vpr v;

int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,a,b;cin>>n>>a>>b;
	b=min(b,n);
	ll sum=0;

	rep(i,n)
	{
		int x,y;cin>>x>>y;
		v.pb({x,y});
		sum+=y;
	}
	sort(all(v),[](pr a,pr b){return a.first-a.second>b.first-b.second;});
/*
	for(auto i:v)
		cout<<i.first<<" "<<i.second<<"\n";*/

	if(b==0){cout<<sum;return 0;}

	rep(i,b){if(v[i].first-v[i].second>0)sum+=v[i].first-v[i].second;else break;}

	ll ans;ll ANS=(ll)-1e12;
	rep(i,n)
	{
		ans=sum;
		if(i<b){
			ans+=max((v[i].first<<a),v[i].second)-v[i].second;
			ans-=max(0ll,v[i].first-v[i].second);
		}
		else
		{
			ans+=max((v[i].first<<a),v[i].second)-v[i].second;
			ans-=max(0ll,v[b-1].first-v[b-1].second);
		}
		ANS=max(ANS,ans);
	}
	cout<<ANS;
}