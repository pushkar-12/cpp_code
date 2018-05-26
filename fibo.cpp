
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
#define sz(x) (ll)(x).size()
#define ff first
#define ss second

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
typedef vector<string> vs;
typedef vector<pr> vpr;
typedef vector<vpr>vvpr;
typedef vector<vi> vvi;
typedef map<ll,ll> MPII;
typedef set<ll> SETI;
typedef multiset<ll> MSETI;

struct Matrix {
	typedef Matrix M;
	vvi d;ll N;
	Matrix(const ll &n)
	{
		N=n;
		d.resize(N);
		rep(i,N)d[i].resize(N);
	}

	M operator*(const M& m) const {
		M a=M(N);
		rep(i,N) rep(j,N)
			rep(k,N) a.d[i][j] =(a.d[i][j] + (d[i][k]*m.d[k][j]))%MOD;
		return a;
	}
	vector<ll> operator*(const vector<ll>& vec) const { //this is for M*vec=vec
		vector<ll> ret(N);
		rep(i,N) rep(j,N) ret[i] =(ret[i]+ (d[i][j] * vec[j]))%MOD;
		return ret;
	}
	M operator^(ll p) const {
		assert(p >= 0);
		M a=M(N), b(*this);
		rep(i,N) a.d[i][i] = 1;
		while (p) {
			if (p&1) a = a*b;
			b = b*b;
			p >>= 1;
		}
		return a;
	}
};
vector<pair<pr,ll> >v;
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,m;cin>>n>>m;
	rep(i,n)
	{
		ll ak,lk,rk;cin>>ak>>lk>>rk;
		v.pb({{lk,0},ak});
		v.pb({{rk+1,1},ak});
	}
	
	sort(all(v),[](const auto lhs,const auto rhs)
		{if(lhs.ff.ff==rhs.ff.ff)return lhs.ff.ss<rhs.ff.ss;return lhs.ff.ff<rhs.ff.ff;});

	vi start={1,1,1};Matrix mm=Matrix(3);
	if(v[0].ff.ff!=2)
	{
		ll ok=v[0].ff.ff-2;
		rep(i,3)rep(j,3) if(!(i+j==2 and i!=j))mm.d[i][j]=1;
		start=(mm^ok)*start;
	}
	
	ll o_k[]={0,0,0};
	for(ll i=0;i<v.size();i++)
	{
		ll coord=v[i].ff.ff;set<pr>st;
		while(i<v.size() and v[i].ff.ff==coord)
		{if(v[i].ff.ss)o_k[v[i].ss-1]--;else o_k[v[i].ss-1]++;i++;}
		rep(i,3)rep(j,3) if(!(i+j==2 and i!=j))mm.d[i][j]=1;
		rep(col,3)
		{if(o_k[col])rep(row,3)mm.d[row][col]=0;}
		ll ok=(i==v.size()?m:v[i].ff.ff)-coord;
		start=(mm^ok)*start;	
		i--;
	}
	cout<<start[1];
}