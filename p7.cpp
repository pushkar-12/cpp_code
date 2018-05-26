#include <bits/stdc++.h>
 
#if DEBUG && !ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...)
#endif
 
using namespace std;
 
/*******  All Required define Pre-Processors and typedef Constants *******/

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

#define tt ll t;cin>>t; while(t--)
typedef long long int ll;
typedef pair<ll, ll> pr;
typedef vector<ll> vi;

int pref[101][4*100001];
int dp[101][4*100001];
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int a,b,k,t;cin>>a>>b>>k>>t;
	int off=2*(ll)1e5;

	for(int diff=-2*(ll)1e5;diff<=2*(ll)1e5;diff++)
		{if(diff<=2*k and diff>=-2*k)dp[0][diff+off]=2*k+1-diff;
		pref[0][diff+off]=((diff==-2*(ll)1e5?0:pref[0][diff-1+off])+dp[0][diff+off])%MOD;}


	repn(i,1,t)
	{
		for(int diff=-2*(ll)1e5;diff<=2*(ll)1e5;diff++)//A-B
		{
			if(diff+2*k<=2*(ll)1e5)
			dp[i][diff+off]=(pref[i-1][diff+2*k+off]-(diff-2*k-1>=-2*(ll)1e5?pref[i-1][diff-2*k-1+off]:0)+MOD)%MOD;
			else
			dp[i][diff+off]=(pref[i-1][2*(ll)1e5+off]-(diff-2*k-1>=-2*(ll)1e5?pref[i-1][diff-2*k-1+off]:0)+MOD)%MOD;
			pref[i][diff+off]=((diff==-2*(ll)1e5?0:pref[i][diff-1+off])+dp[i][diff+off])%MOD;
		}
	}
	int WAYS=0;
	for(int diff=b-a+1;diff<=2*(ll)1e5;diff++)
		WAYS=(WAYS+dp[t-1][diff+off])%MOD;

	cout<<WAYS;
		
}