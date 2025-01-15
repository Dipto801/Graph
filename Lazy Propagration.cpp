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
vll v(mx); 
 struct info{
  ll prop,sum;
 } t[mx*3];
void segment(ll node,ll shuru,ll shesh){
  t[node].prop=0;
  t[node].sum=0;
    if(shuru==shesh){
      t[node].sum=v[shuru];// jodi vector thake
         return;
    }
     ll mid=(shuru+shesh)/2;
     segment(node*2,shuru,mid);
     segment(node*2+1,mid+1,shesh);
    // t[node].sum=t[node*2].sum+t[node*2+1].sum;
}
//kono range er sum bolle
ll query(ll node,ll shuru,ll shesh,ll i,ll j,ll carry){
  if(shuru>j || shesh<i) return 0; //range er baire 
  if(shuru>=i and shesh<=j){
    return t[node].sum+carry*(shesh-shuru+1); // range a porle store kora value return;
  }
  // r jodi purata range a na pore
  ll mid=(shuru+shesh)/2;
  ll leftsum=query(node*2,shuru,mid,i,j,carry+t[node].prop);
  ll rightsum=query(node*2+1,mid+1,shesh,i,j,carry+t[node].prop);
  return leftsum+rightsum;
}
void update(int node, int b, int e, int i, int j, ll x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j) 
    {
        t[node].sum += ((e - b + 1) * x);
        t[node].prop += x; 
        return;
    }
    int mid = (b + e) / 2;
    update(node*2, b, mid, i, j, x);
    update(node*2+1, mid + 1, e, i, j, x);
    t[node].sum = t[node*2].sum + t[node*2+1].sum + (e - b + 1) * t[node].prop;
}

void solve()
{
  ll n,k; cin>>n>>k;
  //for(ll i=1;i<=n;i++) cin>>v[i];
 // memset(v,0,sizeof(v));
  segment(1,1,n);
  ll c,p,q,val;
  while(k--){
    cin>>c;
    if(c==0){
      cin>>p>>q>>val;
      update(1,1,n,p,q,val);
    }
    else{
      cin>>p>>q;
      cout<<query(1,1,n,p,q,0)<<nl;
    }
  }
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


