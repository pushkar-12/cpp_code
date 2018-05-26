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
 


double ANS;ll t[200001],coeff[200001],A[200001];
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(19);
	int n;double T;double sum=0;
	cin>>n>>T;
	rep(i,n){cin>>A[i];sum+=A[i];}rep(i,n)cin>>t[i];
	rep(i,n)coeff[i]=t[i]-T;

	rep(i,n)ANS+=(A[i]*coeff[i]);
	int flag=0;
	double maxi=(double)-(1e17);
	rep(i,n){if(coeff[i]==0)continue;
		double tryans=ANS-A[i]*coeff[i];
	if(coeff[i]>0)
	if(-1.0*tryans>=0 and -1.0*tryans<=A[i]*coeff[i])
		{maxi=max(maxi,sum-A[i]-1.0*tryans/coeff[i]);flag=1;}
	else
	if(-1.0*tryans<=0 and -1.0*tryans>=A[i]*coeff[i])
		{maxi=max(maxi,sum-A[i]-1.0*tryans/coeff[i]);flag=1;}

	}
	
	if(!flag)cout<<"0";else cout<<maxi;


}