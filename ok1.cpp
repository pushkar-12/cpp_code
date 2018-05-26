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
set<pr,greater<pr> >st[ee5];
map<ll,ll>w2len [ee5];
map<ll,ll>len2w [ee5];

ll findlen(ll v,ll w)//find in list of v the first vertex with lastweight<w
{

	auto it= st[v].upper_bound(mp(w,-1));
	
	if(it!=st[v].end())return it->second;
	return 0;
}




int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,m;cin>>n>>m;

	ll maxi=-INF;

	rep(i,m)
	{
		ll a,b,w;cin>>a>>b>>w;a--;b--;
		
		//longest path ending at a <w
		ll len=findlen(a,w);
		// pair to be inserted is {w,len+1}
		
		
		if(w2len[b].count(w) and w2len[b][w]>=len+1)continue;
		else if(len2w[b].count(len+1) and len2w[b][len+1]<=w)continue;
		
		else 
		{
			st[b].insert({w,len+1});
			if(w2len[b].count(w))
			st[b].erase({w,w2len[b][w]});
			
			if(len2w[b].count(len+1))
			st[b].erase({len2w[b][len+1],len+1});
			
		}
		w2len[b][w]=len+1;
		len2w[b][len+1]=w;
		maxi=max(maxi,len+1);

		
	}

	cout<<maxi;
	
}