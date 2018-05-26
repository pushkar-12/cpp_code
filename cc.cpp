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
 
int spf[5*ee6];int a[ee5],b[ee5];
set<int>s;
void go(int no)
{
	int temp=no;
	
	while(temp>1)
	{
		int fact=spf[temp];
		while(temp%fact==0)
			temp=temp/fact;
		

		for(int j=fact;j<ee6;j+=fact)
			s.erase(j);
		
	}


}
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=2;i<5*ee6;i++)spf[i]=i;
	for(int i=2;i*i<5*ee6;i++)
	{
		if(spf[i]==i)
		for(int j=i*i;j<ee6;j+=i)
		{
			if(spf[j]==j)spf[j]=i;
		}
	}
	

	
	for(int i=2;i<ee6;i++)
		s.insert(i);

	int n;cin>>n;
	rep(i,n)
	cin>>a[i];
int flag=0;
int start=-1;
	rep(i,n)
	{
		if(i==0){
			b[i]=a[i];
			go(b[i]);
			continue;
		}
		if(s.find(a[i])!=s.end())
			{b[i]=a[i];go(b[i]);continue;}
		else if(flag==0){
		b[i]=*(s.lower_bound(a[i]));
		go(b[i]);flag=1;}
		else {start=i;break;}
	}
	set<int>::iterator it=s.begin();
	if(start!=-1)
	while(start<n)
	{
		b[start]=*it;
		it++;start++;
	}
	rep(i,n)
	cout<<b[i]<<" ";
}