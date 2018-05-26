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
 
ll powmod(ll a, ll e) {
	if (e == 0) return 1;
	ll x = powmod(a * a % MOD, e >> 1);
	return e & 1 ? x * a % MOD : x;
}

unordered_map<char,int>mt; 

int len,n;
inline int fun(int x)
{if(x==len and n==1)return len-1; else return len>=n+x?x+n:(len);}

int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	string a,b,c;cin>>a>>b>>c;
	len=a.length();
	//cout<<len<<" ";
	int maxi=-INF;
	rep(i,len){mt[a[i]]++;maxi=max(maxi,mt[a[i]]);}
	int maxa=maxi;mt.clear();

	maxi=-INF;
	rep(i,len){mt[b[i]]++;maxi=max(maxi,mt[b[i]]);}
	int maxb=maxi;mt.clear();

	maxi=-INF;
	rep(i,len){mt[c[i]]++;maxi=max(maxi,mt[c[i]]);}
	int maxc=maxi;

	//cout<<maxa<<" "<<maxb<<" "<<maxc<<"\n";
	//cout<<fun(maxa)<<" "<<fun(maxb)<<" "<<fun(maxc)<<"\n";

	int winner=max(fun(maxa),max(fun(maxb),fun(maxc)));
	vi v;v.pb(fun(maxa)),v.pb(fun(maxb)),v.pb(fun(maxc));
	
	sort(all(v));if(v[1]==v[2])cout<<"Draw";
	else if(winner==fun(maxa))cout<<"Kuro";
	else if(winner==fun(maxb))cout<<"Shiro";
	else cout<<"Katie";

}