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
 
ll fen[500010],pref[500010],a[500010],Upd[500010];
ll n,r,k;

ll check(ll target)
{
	rep(i,n+5)Upd[i]=0;
	ll total=0;ll ADDED=0;
	ll left=1;
	repn(i,1,n)
	{
		ll lo=max((ll)1,i-r);
		ll ro=min(n,i+r);

		while(left<=max(i,(ll)1))
			{ADDED+=Upd[left];left++;}
		
		ll ok=pref[ro]-pref[lo-1]+ADDED;
		
		if(ok>=target)continue;
		total+=target-ok;
		if(total>k)return 0;
		ADDED+=target-ok;
		Upd[min(i+r+r+1,n+1)]+=(ok-target);
		
	}
	return 1;
}
 
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>r>>k;
	repn(i,1,n){cin>>a[i];pref[i]=pref[i-1]+a[i];}

	ll low=0,high=9223372036854775807;
	
	while(low<high)
	{
		ll mid=low+(high-low)/2;
		
		if(low==mid)break;
		if(check(mid))
			low=mid;
		else high=mid;

		
	}
	cout<<low;

}