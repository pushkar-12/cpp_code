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
 

ll getlevel(ll x)
{
	return (ll)log2(x);
}
ll pow2[101];
vi ok;ll shift[100];
void go(ll x)
{
	ll l=getlevel(x);
	
	//cout<<x<<" ";
	
	if(l==0){return;}

	ll effect=(x+shift[l])/2-x/2-shift[l-1];
	//cout<<"effect "<<effect<<"\n";
	//if(x==8 and effect==0)return;

	ll cell=x/2+effect;
	cell=cell-pow2[l-1];
	cell=pow2[l-1]+(cell%pow2[l-1]+pow2[l-1])%pow2[l-1];
	//cout<<cell<<" ";
	/*
	if(cell<pow2[l-1]) cell=pow2[l]-1-(pow2[l-1]-cell-1)%pow2[l-1];
	else if(cell>=pow2[l]) cell=pow2[l-1]+(cell-pow2[l])%pow2[l-1];*/
	//cout<<cell<<"\n";
	ok.pb(cell);
	go(ok.back());
}


int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	ll q;cin>>q;

	pow2[0]=1;
	for(ll i=1;i<=60;i++)
		pow2[i]=pow2[i-1]<<1;
	
	while(q--)
	{
		ll type;cin>>type;
		if(type==1)
		{
			ll x,k;cin>>x>>k;
			ll in=getlevel(x);
			shift[in]+=k;
		}
		else if(type==2)
		{

			ll x,k;cin>>x>>k;int ok=0;
			ll in=getlevel(x);
			while(in<=60)
				{shift[in]=(shift[in]+pow2[ok]*k)%pow2[in];in++;ok++;}
			
		}
		else
		{

			ll x;cin>>x;ok.pb(x);
			go(x);

			rep(i,ok.size())cout<<ok[i]<<" ";cout<<"\n";ok.clear();
			
		}
	}
}	