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
#define first ff
#define second ss

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
 
const int N=5*ee5;

vvi g(N);int st[N],sz[N],clocked[N],dep[N];

int timed=0;
void pre(int v,int p)
{
	st[v]=timed;clocked[timed]=v;timed++;
	for(auto vv:g[v])
	{if(vv==p)continue;dep[vv]=dep[v]+1;pre(vv,v);sz[v]+=sz[vv];}
	sz[v]++;
}

map<pr,int>ANS;int freq[N][26];char ch[N];vpr ok;
vi queries[N];
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
    if(bigChild != -1)
        dfs(bigChild, v, 1);//GainInfo from bigchild & bigChild marked as big and not cleared from cnt
    for(auto u : g[v])
	if(u != p && u != bigChild)
	    for(int timed = st[u]; timed < st[u]+sz[u]; timed++)
		{/*here we are traversing the subtrees of lighter childs of v*/
	    	freq[dep[clocked[timed]]][ch[clocked[timed]]-97]++;
		}
		
    /*here you need to consider contribution of v itself*/
	freq[dep[v]][ch[v]-97]++;
	for(auto qq:queries[v])
	{
		int sum=0;
		rep(i,26)sum+=(freq[qq][i]%2);
		if(sum<2)ANS[{v,qq}]=1;
	}

    if(keep == 0)
        for(int timed = st[v]; timed < st[v]+sz[v]; timed++)
        	freq[dep[clocked[timed]]][ch[clocked[timed]]-97]--;
	    /*if v was a light child of its parent remove its contribution*/
}

int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	int n,q;cin>>n>>q;
	repn(i,1,n)
	{int a;cin>>a;g[a-1].pb(i);}

	rep(i,n)cin>>ch[i];
	rep(i,q){int v,h;cin>>v>>h;v--;queries[v].pb(h);ok.pb({v,h});}
	dep[0]=1;
	pre(0,-1);
	dfs(0,-1,0);
	for(auto pp:ok)cout<<(ANS.count(pp)?"Yes\n":"No\n");

}