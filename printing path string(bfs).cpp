///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


map<string, vector<string>> adj;
map<string, string> par;
map<string, int> lev;

void bfs ( string s )
{
    lev.clear();

    queue<string> q;
    q.push( s );
    lev[s]= 1;

    while ( !q.empty() ) {
        string u = q.front();
        q.pop();

        for ( auto v : adj[u] ) {
            if ( lev[v] == 0 ) {
                lev[v] = lev[u] + 1;
                par[v] = u;
                q.push( v );
            }
        }
    }
}


int main()
{
    optimize();

    int n;
    bool ok = 0;

    while ( cin >> n ) {
        if ( ok ) cout << endl;
        ok = 1;

        adj.clear();
        par.clear();

        for ( int i = 1; i <= n; i++ ) {
            string u, v;
            cin >> u >> v;
            adj[u].PB ( v );
            adj[v].PB ( u );
        }

        string s, t;
        cin >> s >> t;

        bfs ( s );

        if ( lev[t] == 0 ) {
            cout << "No route\n";
            continue;
        }

        vector<pair<string, string>> path;

        while ( !par[t].empty() ) {
            path.PB ( { par[t], t } );
            t = par[t];
        }

        reverse( path.begin(), path.end() );

        for ( auto u : path ) cout << u.first << " " << u.second << endl;

    }

    return 0;
}