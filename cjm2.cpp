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
 
vi a,b,v;
int main()
{
	//#if !ONLINE_JUDGE
	//freopen("in.txt","r",stdin);
	//#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;cin>>t;
	int ttt=t;
	while(t--)
	{
		int flag=0;a.clear();b.clear();v.clear();
		cout<<"Case #"<<(ttt-t)<<": ";
		int n;cin>>n;
		rep(i,n){int x;cin>>x;if(i%2)b.pb(x);else a.pb(x);}
		sort(all(a));sort(all(b));
		//for(auto i:a)cout<<i<<" ";cout<<"\n";for(auto i:b)cout<<i<<" ";cout<<"\n";
		int ak=0,bk=0;
		rep(i,n){if(i%2)v.pb(b[bk++]);else v.pb(a[ak++]);}
		//for(auto i:v)cout<<i<<" ";cout<<"\n";
		rep(i,n-1){if(v[i]>v[i+1]){cout<<i<<"\n";flag=1;break;}}
		if(!flag)cout<<"OK\n";
	}
}