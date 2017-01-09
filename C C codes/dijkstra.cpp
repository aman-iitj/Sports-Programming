/*
Author : Aman Singh
Solution for problem code Santa Claus and Tangerines.
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define sz(a) int((a).size())
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define buli(x) (__builtin_popcountll(x))
#define all(c) (c).begin(),(c).end()
#define foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define input(s, n) for(int i=0;i<n;i++) cin >> s[i];
#define F(i, f, t) for(int i=f;i<t;i++)
#define R(i,n) for(ll i=0;i<n;i++)
#define _ << ' ' <<

#define print(cnt,x) cout<<"Case #"<<cnt<<": "<<x<<"\n";

template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

#ifdef LOCAL
#define fr freopen("in.txt","r",stdin)
#define fo freopen("out.txt","w",stdout)

#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define dbg(x) F(i,0,sz(x)) cout << x[i] << " ";
#define dbgg(x) F(i,0,sz(x)){F(j,0,sz(x[0])) cout << x[i][j] << " "; cout << endl;}
#else
#define fr 1
#define fo 1
#define error(x)
#define Error(a,b)
#define errop(a)
#define dbg(x)
#define dbgg(x)
#endif

inline void sc(int &x)
{
	bool f=0; x=0; char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') { f=1; c=getchar(); }
	while(c>='0' && c<='9') { x=x*10+c-'0'; c=getchar(); }
	if(f) x=-x; return;
}

void sc(char &x) {scanf("%c", &x); }
void sc(int &x,int &y) { sc(x); return sc(y); }
void sc(int &x,int &y,int &z) { sc(x); sc(y); return sc(z); }

#define inf 2e9
const double eps = 1e-7;

#define N 2000005
int n, k, m;
vii graph[N];
char str[N];

int rec(vi &P, int k){
	error(k);
	if(P[k] != -1) rec(P, P[k]);
	cout << k << " ";
}

int main(){
	std::ios::sync_with_stdio(false);
	// fr;
	int a, b, c;
	sc(n, m); R(i, m) {
		sc(a, b, c);
		graph[a].pb({b, c});
		graph[b].pb({a, c});
	};

	priority_queue<ii,vector<ii>, greater<ii> > Q; 
	
	vi V(n + 1, 0); vi P(n + 1, 0);
	vi D(n + 1, inf * 10000);

	D[1] = 0;
	//V[1] = 1;

	Q.push({0, 1});
	P[1] = -1;

	while(!Q.empty()){
		ii temp = Q.top();
		Q.pop();
		V[temp.se] = 1;
		if(temp.se == k) break;
		if(D[temp.se] >= temp.fi){
			for(auto nxt: graph[temp.se]){
				if(!V[nxt.fi] && D[nxt.fi] > temp.fi + nxt.se){
					P[nxt.fi] = temp.se;
					Q.push({temp.fi + nxt.se, nxt.fi});
					D[nxt.fi] = temp.fi + nxt.se;
				}
			}
		}
	}
	k = n;
	//cout << D[5] << endl;
	//F(i, 1, n + 1) Error(i, P[i]);
	if(D[k] != inf) rec(P, k);
	else cout << -1 << " " ;

	return 0;
}