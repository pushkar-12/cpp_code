#include<bits/stdc++.h>
using namespace std;



typedef long long int ll;

ll pos[105];
int main()
{
	ll n;cin>>n;
	for(ll i=0;i<n/2;i++)cin>>pos[i];

		sort(pos,pos+n/2);

	for(int i=0;i<n/2;i++)
		cout<<pos[i]<<" ";
	ll x=1;
ll sum=0;
	for(ll i=0;i<n/2;i++){sum+=((pos[i]-x)>0?(pos[i]-x):(x-pos[i]));x+=2;}

	x=2;
ll sum2=0;
for(ll i=0;i<n/2;i++){sum2+=((pos[i]-x)>0?(pos[i]-x):(x-pos[i]));x+=2;}

	cout<<(min(sum,sum2));

}		