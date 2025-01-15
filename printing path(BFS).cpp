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
vector<ll>adj[mx];
ll level[mx];
map<ll,ll>parent;// map er jaygay array use koreo hobe;
void bfs(ll source){
    memset(level,-1,sizeof(level));
    level[source]=0;
    queue<ll>q;
    q.push(source);
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(auto v:adj[u]){
        if(level[v]==-1){
            level[v]=level[u]+1;
            parent[v]=u;// normal bfs e ,just jei path dhore
                        //path dhore astece oita map/array te store;;
            q.push(v);
        }
        }
    }
}

void solve()
{
  ll n,m; cin>>n>>m;
  for(ll i=0;i<m;i++){
    ll u,v; cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  ll source=1,terminant=6;
  bfs(source);
  if(level[source]==-1) {
    cout<<"No route"<<nl;
    return;
  }
  vll path;// path store process;;;;
  parent[source]=0;
  path.pb(terminant);
  while(parent[terminant]>0){
    path.pb(parent[terminant]);
    terminant=parent[terminant];
  }
  reverse(all(path));
  coutv(path); cout<<nl;

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


