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


template<class X,int ary>class heap{
		
	public:
		int size;
		X data[ee6];
		heap(){size=0;}
		void heapify(int i);
		X &get_root();
		X &pop_root();
		int insert(X element);

	};

	template<class X,int ary>
	int heap<X,ary>::insert(X element)
	{	
		try{if(size==ee6)throw 0;}catch(int e){cout<<"Full Stack";return 0;}

		data[size]=element;
		int index=size;
		while(index)
		{
			if(data[index]>data[(index-1)/ary])
				{swap(data[index],data[(index-1)/ary]);index=(index-1)/ary;}
			else {break;}
		}
		size++;
		return 1;
	}

	template<class X,int ary>
	void heap<X,ary>::heapify(int i)
	{
		int index=i;
		while(1)
		{
			X maxi=data[index];
			for(int child=index*ary+1;child<=index*ary+ary and child<size;child++)
			maxi=max(maxi,data[child]);

			if(maxi==data[index])return;
						
			for(int child=index*ary+1;child<=index*ary+ary and child<size;child++)
			{if(maxi==data[child]){data[child]=data[index];data[index]=maxi;heapify(child);break;}}
		}
	}

	template<class X,int ary>
	X &heap<X,ary>::get_root()
	{return data[0];}

	
	template<class X,int ary>
	X &heap<X,ary>::pop_root()
	{
		try{if(size==0)throw 0;}catch(int e){cout<<"Empty Stack";}
		X result=data[0];
		data[0]=data[size];
		data[size]=result;
		size--;
		heapify(0);
		return data[size+1];	
		
	}



int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//implemenation of n-ary heap
			
	heap<char,1000>h;
	
	
}