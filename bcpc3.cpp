#include <bits/stdc++.h>
#include<chrono>
#if DEBUG && !ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...)
#endif
 
using namespace std;
using namespace std::chrono;
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

ll ranked[5001];
ll parent[5001];


ll no[5005];

//------------------------------------------------------------------------------

ll par(ll a)
{
	return ((a==parent[a])?a:parent[a]=par(parent[a]));
}

void merge(ll a,ll b)
{
	ll aa=par(a),bb=par(b);
	if(ranked[aa]>ranked[bb])
	{parent[bb]=aa;
	}
	else{
		parent[aa]=bb;
		if(ranked[aa]==ranked[bb])ranked[bb]++;
	}
}
 
ll square(ll a,ll b)
{
	if((a<0 and b>0) or (a>0 and b<0))return 0;
	else if(a==0 or b==0)return 1;
	ll prod=a*b;ll sq=sqrt(prod);ll s=sq*sq;if(s==(prod) or (s+sq+sq+1)==(prod) or (s-sq-sq+1)==(prod))
		return 1;
	return 0;
}
vi heads; ll a[5001];
int present[5001];
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	auto start = high_resolution_clock::now();
	ll n;cin>>n;
	rep(i,n){cin>>a[i];}

	rep(i,n){parent[i]=i;}
	heads.pb(0);
	for(ll i=1;i<n;i++)
	{
		ll flag=0;
		for(auto head:heads)
		{
			if(square(a[head],a[i]))
				{merge(head,i);flag=1;break;}
		}
		if(!flag)heads.pb(i);
	}

	//for(auto i:heads)cout<<i<<" ";

	rep(i,n)
	parent[i]=par(i);
	//rep(i,n)cout<<parent[i]<<" ";cout<<"\n";
	
	ll freq=0;
	
	rep(i,n)
	{
		if(i%2)
			{present[parent[i-1]]--;if(present[parent[i-1]]==0)freq--;}
		
		if(i%2==0)
		for(ll j=i;j<n;j++)
		{
			if(present[parent[j]])present[parent[j]]++;
			else freq++,present[parent[j]]=1;
			//cout<<i<<" "<<j<<" "<<freq<<"\n";
			no[freq]++;
		}
		else
		for(ll j=n-1;j>=i;j--)
		{
			no[freq]++;//cout<<i<<" "<<j<<" "<<freq<<"\n";
			present[parent[j]]--;
			if(present[parent[j]]==0)freq--;
		}

	}

	for(ll ok=1;ok<=n;ok++)
	{
		cout<<no[ok]<<" ";
	}/*
	auto stop = high_resolution_clock::now();
	  auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
 */
}