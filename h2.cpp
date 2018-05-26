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

ll dp[2*ee5][51],rem[2*ee5][51],a[2*ee5];
ll n,k,p;

int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k>>p;
	rep(i,n){cin>>a[i];}

	for(ll i=n-1;i>=0;i--)
	{
		for(ll k=1;k<=n-i;k++)
		{
			if(k==1){dp[i][1]=(dp[i+1][1]+a[i])%p;continue;}
			if(dp[i+1][k-1]+(a[i]%p)>dp[i][k])
			{
				dp[i][k]=dp[i+1][k-1]+a[i]%p;
				rem[i][k]=a[i]%p;
			}
			
			if(k!=n-i and dp[i+1][k]+(rem[i+1][k]+a[i])%p-rem[i+1][k]>dp[i][k])
			{
				dp[i][k]=dp[i+1][k]+(rem[i+1][k]+a[i])%p-rem[i+1][k];
				rem[i][k]=(rem[i+1][k]+a[i])%p;
			}
		}
	}
	cout<<dp[0][k];

}