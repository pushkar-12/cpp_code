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
 

vpr v;
 
int main()
{
	//#if !ONLINE_JUDGE
	//freopen("in.txt","r",stdin);
	//#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	ll t;cin>>t;ll ttt=t;
	while(t--)
	{
		v.clear();
		cout<<"Case #"<<(ttt-t)<<": ";
 		ll d;string p;cin>>d>>p;
 		ll n=-1;

 		for(ll i=p.length()-1;i>=0;i--){if(p[i]=='S'){n=i+1;break;}}
 		if(n==-1){cout<<"0\n";continue;}

 		ll freq=0,damage=1;char ch=p[0];
 		rep(i,n)
 		{
 			if(p[i]==ch){freq++;continue;}
 			v.pb(mp((ll)ch,freq));
 			ch=p[i];freq=1;
 		}
 		v.pb(mp((ll)ch,freq));
 /*		for(auto i:v)
 			cout<<(char)i.first<<" "<<i.second<<"\n";
*/
 		ll D=0,cnt=0;
 		rep(i,n){if(p[i]=='C')damage=damage<<1;else D+=damage;}
 		ll target=D-d;if(target<=0){cout<<"0\n";continue;}//cout<<target<<" "<<damage<<" "<<D<<"\n";
 		ll done=0;damage=damage/2;
 		for(ll i=v.size()-1;i>0;i-=2)
 		{
			rep(j,v[i-1].second){

 				if(target>v[i].second*damage){target-=v[i].second*damage;cnt+=v[i].second;}
 				else {cnt+=target/damage;if((target%damage))cnt++;done=1;break;}
 				damage/=2;
 			}

 			if(done)break;
 			
 			if(i>1)
 			v[i-2].second+=v[i].second;
 		}
 		if(done)cout<<cnt<<"\n";
 		else cout<<"IMPOSSIBLE\n";
 		
	}
		
}