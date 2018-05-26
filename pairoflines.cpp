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

void print(pr a){cout<<a.first<<" "<<a.second<<"\n";}

ll check(pr a,pr b,pr c)
{
	return (b.second-a.second)*(c.first-b.first)==(b.first-a.first)*(c.second-b.second);
}
 vpr v;
const ll m=1e15;
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
		ll x,y;cin>>x>>y;v.pb(mp(x,y));
	}

	pr p1={m,m},p2={m,m},p3={m,m},p4={m,m};

	if(n<=4){cout<<"YES";return 0;}
	p1=v[0];
	p2=v[1];

	ll flag=1;
	repn(i,2,n)
	{
		if(check(p1,p2,v[i]))
			continue;
		else if(flag)
		{p3=v[i];flag=0;continue;}
		else if(check(p1,p2,v[i]) or check(p1,p3,v[i]) or check(p2,p3,v[i]))
		continue;

		else {p4=v[i];break;}
	}
	if(p3.first==m)
		{cout<<"YES";return 0;}
	else if(p4.first==m)
		{ 
			int flag=1;
			//p1 is common 
			rep(i,n){if(!(check(v[i],p1,p2) or check(v[i],p1,p3))){flag=0;break;}}if(flag){cout<<"YES";return 0;}flag=1;
			//p2 is common 
			rep(i,n){if(!(check(v[i],p1,p2) or check(v[i],p2,p3))){flag=0;break;}}if(flag){cout<<"YES";return 0;}flag=1;
			//p3 is common
			rep(i,n){if(!(check(v[i],p3,p2) or check(v[i],p1,p3))){flag=0;break;}}if(flag){cout<<"YES";return 0;}
			cout<<"NO";return 0;
		}
	
	

	flag=1;
	rep(i,n)
	{
		if(check(v[i],p1,p2) or check(v[i],p3,p4))
			continue;
		else
			{flag=0;break;}
	}
	if(flag){cout<<"YES";return 0;}

	flag=1;
	rep(i,n)
	{
		if(check(v[i],p1,p3) or check(v[i],p2,p4))
			continue;
		else
			{flag=0;break;}
	}
if(flag){cout<<"YES";return 0;}
	flag=1;
	rep(i,n)
	{
		if(check(v[i],p1,p4) or check(v[i],p2,p3))
			continue;
		else
			{flag=0;break;}
	}
	if(flag){cout<<"YES";return 0;}
	cout<<"NO";

}