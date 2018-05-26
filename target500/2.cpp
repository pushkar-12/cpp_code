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
 
const int ALPHABET_SIZE = 2;
 
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
    int mini;
};
 

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
    pNode->isEndOfWord = false;
    pNode->mini=INF;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}

void insert(struct TrieNode *root, int no)
{
    struct TrieNode *pCrawl = root;
 	
    for(int i=16;i>=0;i--)
    {
        int bit = (no>>i)&(1);
      
        if (!pCrawl->children[bit])
            pCrawl->children[bit] = getNode();
 		
        pCrawl = pCrawl->children[bit];
        pCrawl->mini=min(no,pCrawl->mini);
    }
 
   pCrawl->isEndOfWord = no;
}

int ans(TrieNode *root,int x,int s)
{
   struct TrieNode *pCrawl = root;
   for(int i=16;i>=0;i--)
   {
   	    int bit = (x>>i)&(1);
   	    if(!pCrawl->children[bit] and !pCrawl->children[1-bit])return -1;
        if (!pCrawl->children[1-bit])
        	{if(pCrawl->children[bit]->mini>s-x)
        		return -1;
        	else
        	pCrawl = pCrawl->children[bit];}
        else if(pCrawl->children[1-bit]->mini>s-x)
        	if(pCrawl->children[bit] and pCrawl->children[bit]->mini>s-x)
        		return -1;
        	else pCrawl=pCrawl->children[bit];
 		
        else pCrawl = pCrawl->children[1-bit];

        
   }
   return pCrawl->isEndOfWord;

}
 
struct TrieNode *roots[ee5]; 
vvi factors(ee5);

int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0;i<ee5;i++)
		roots[i]=getNode();

	for(int i=1;i<ee5;i++)
	{
		for(int j=i;j<ee5;j+=i)
			factors[j].pb(i);
	}


	int q;cin>>q;
	while(q--)
	{
		int t;cin>>t;
		if(t==1)
		{
			int u;cin>>u;	
			for(auto f:factors[u])
			insert(roots[f],u);
		}
		else
		{
			int x,k,s;cin>>x>>k>>s;
			if(x%k){cout<<"-1\n";continue;}
			cout<<ans(roots[k],x,s)<<"\n";

		}
		
	}
}