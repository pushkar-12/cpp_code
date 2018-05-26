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
/*
ll tree[4*ee5];
const ll MaxVal=3*ee5;
void update(ll idx ,ll val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

ll query(ll idx){
    ll sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
*/
ll a[4*ee5]; 
set<ll>seg[16*ee5];

void build(ll low,ll high,ll index)
{
	if(low==high){
		seg[index].insert(a[low]);return;
	}

	ll mid=(low+high)/2;
	build(low,mid,index+index+1);
	build(mid+1,high,index+index+2);

	seg[index]=seg[index+index+1];
	seg[index].insert(all(seg[index+index+2]));
	

}

ll query(ll low,ll high,ll in,ll q,ll value)
{
	if(high<=q)
	{
		return distance(seg[in].lower_bound(value),seg[in].end());
	}
	else if(low>q) return 0;

	ll mid=(low+high)/2;
	if(mid>=q)
		return query(low,mid,in,q,value);
	else
		return query(low,mid,in,q,value)+query(mid+1,high,in,q,value);
}




 
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;cin>>n;ll sum=0;
	rep(i,n)
	{
		cin>>a[i];
		a[i]--;
	}
	build(0,n-1,0);



	rep(i,n)
	{
		if(i==0)continue;
		sum+=query(0,n-1,0,a[i],i);
	}
	cout<<sum;



}