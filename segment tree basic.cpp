#include<bits/stdc++.h>
#define dipto ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define nl '\n'
#define yes             cout<<"YES"<<'\n';
#define no              cout<<"NO"<<'\n';
#define gcd(x,y)        __gcd(x,y)
#define lcm(x,y)        y*x/__gcd(x,y)
#define pb              push_back
#define nextp(x)        next_permutation(x.begin(),x.end())
#define all(ar)         ar.begin(), ar.end()
#define rall(ar)        ar.rbegin(), ar.rend()
#define Unique(x)       x.erase(unique(all(x)), x.end());
#define MAX(x)          *max_element(all(x));
#define MIN(x)          *min_element(all(x));
#define SUM(a)          accumulate(all(a),0LL);
#define fixpoint(x)     cout<<fixed<<setprecision(x)
#define clz(x)          __builtin_clz(x) // count leading zeros of 32 bits.
                                         //like 4=00000000....100(leading 29 ta)
#define ctz(x)          __builtin_ctz(x) //count trailing zeros                                         
#define popcount(x)     __builtin_popcount(x)    //count number of ones's(bits)

#define vll             vector<ll>
#define F               first
#define S               second
#define cinv(v)         for(auto& i:v)cin>>i;
#define coutv(v)        for(auto& i:v)cout<<i<<' ';

//int dx[]={-1,+1,0,0}; //[Grid move's]
//int dy[]={0,0,-1,+1};

using namespace std;
typedef long long ll;
const int mx=1e5+123;
vll v(mx),t(3*mx); //  tree vec a all seg_tree er node value
                     // store kore rakhbo

void segment(ll node,ll shuru,ll shesh){
    if(shuru==shesh){
         t[node]=v[shuru];
         return;
    }
     ll mid=(shuru+shesh)/2;
     segment(node*2,shuru,mid);
     segment(node*2+1,mid+1,shesh);
     t[node]=t[node*2]+t[node*2+1];
}
//kono range er sum bolle
ll query(ll node,ll shuru,ll shesh,ll i,ll j){
  if(shuru>j || shesh<i) return 0; //range er baire 
  if(shuru>=i and shesh<=j){
    return t[node]; // range a porle store kora value return;
  }
  // r jodi purata range a na pore
  ll mid=(shuru+shesh)/2;
  ll leftsum=query(node*2,shuru,mid,i,j);
  ll rightsum=query(node*2+1,mid+1,shesh,i,j);
  return leftsum+rightsum;
}
ll update(ll node,ll shuru,ll shesh,ll i,ll val){
  if(i>shesh or i<shuru) return 0;
  if(i==shuru and i==shesh){
    return t[node]=val;
  }
  ll mid=(shuru+shesh)>>1;
  update(node*2,shuru,mid,i,val);
  update(node*2+1,mid+1,shesh,i,val);
  t[node]=t[node*2]+t[node*2+1];

}

void solve()
{
  ll n; cin>>n;
  for(ll i=1;i<=n;i++) cin>>v[i];
  segment(1,1,n);
  for(ll i=1;i<=15;i++) cout<<t[i]<<" ";
   cout<<nl;
  cout<<query(1,1,n,3,7)<<nl; //range(3-7) er sum;
  update(1,1,n,3,10);
  cout<<query(1,1,n,3,7)<<nl;
}
int main()
{
    dipto
    ll test=1;//cin>>test;
    while(test--)
    {
      solve();
    }
}


