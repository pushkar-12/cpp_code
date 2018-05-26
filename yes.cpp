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
 
multiset<pr> seg[12*ee5];
ll A[3*ee5];
void build(ll low,ll high,ll index)
{
	
	if(low==high)
	{
		seg[index].insert(mp(A[low],1));return;
	}
	ll mid=(low+high)/2;
	build(low,mid,index*2+1);build(mid+1,high,index*2+2);

	multiset<pr>s1=seg[index+index+1];multiset<pr>s2=seg[index+index+2];
	int k=1;
	while(seg[index].size()!=seg[index*2+1].size()+seg[index*2+2].size())
	{
		if(s1.size() and (!s2.size() or s1.begin()->first<s2.begin()->first)){
			seg[index].insert(mp(s1.begin()->first,k++));s1.erase(s1.begin());}
		else
			{
			seg[index].insert(mp(s2.begin()->first,k++));s2.erase(s2.begin());}
	}
}
 
ll query(ll low,ll high,ll index,ll in,ll value)
{
	if(low>in or low>high)return 0;
	if(high<=in)
		{auto it=seg[index].lower_bound(mp(value,-1));
		return (it==seg[index].end()?0:seg[index].size()-it->second+1);}
	ll mid=(low+high)/2;
	return query(low,mid,index+index+1,in,value)+query(mid+1,high,index+index+2,in,value);

}

int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n;cin>>n;
	rep(i,n){cin>>A[i];A[i]--;}
	build(0,n-1,0);
	ll ANS=0;

	rep(i,n)
	{
		if(i==0)continue;
		ANS+=query(0,n-1,0,min(A[i],i-1),i);
	}
	cout<<ANS;


	
}