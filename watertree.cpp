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

const int N=2*ee5;vvi g(N);
int o=1;int fen[N],feno[N],sbsz[N],pos[N];
void dfs(int v,int p)
{
	pos[v]=o;o++;
	for(auto i:g[v])
	{
		if(i==p)continue;
		dfs(i,v);
		sbsz[v]+=sbsz[i];
	}
	sbsz[v]++;
}

int add(int in,int val,int fen[])
{
	while(in<=N)
	{
		fen[in]+=val;
		in+=(in&-in);
	}

}
int sum(int in,int fen[])
{
	int s=0;
	while(in>0)
	{
		s+=(fen[in]);
		in-=(in&-in);
	}
	return s;
}


int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	int n;cin>>n;
	rep(i,n-1)
	{
		int a,b;cin>>a>>b;
		a--;b--;g[a].pb(b);g[b].pb(a);

	}
	dfs(0,-1);

	int q;cin>>q;
	while(q--)
	{
		int c,v;cin>>c>>v;v--;
		if(c==1)
		{add(pos[v],1,fen);add(pos[v]+sbsz[v],-1,fen);}

		else if(c==2)
		{add(pos[v],1,feno);add(pos[v]+1,-1,feno);}
		else
		{
			cout<<sum(pos[v],fen)<<" ";
			cout<<sum(pos[v]+sbsz[v]-1,feno)-sum(pos[v]-1,feno)<<"\n";
			/*if(sum(pos[v],fen)-sum(pos[v]+sbsz[v]-1,feno)+sum(pos[v]-1,feno)>0)
				cout<<"1\n";else cout<<"0\n";*/
		}

	}
}