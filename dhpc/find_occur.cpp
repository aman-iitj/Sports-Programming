/*
Author : Aman Singh
Solution for problem code find occuurence.
 
==============================================
A programmer started to cuss,
'cause getting to sleep was a fuss.
As he lay there awake in his bed,
Looping around and 'round in his head,
Was: while(!asleep()) sheep++;
==============================================
 
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define sz(a) int((a).size()) 
// #define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define buli(x) (__builtin_popcountll(x))
#define all(c) (c).begin(),(c).end() 
#define foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define input(s, n) for(int i=0;i<n;i++)cin >> s[i];
#define F(i, f, t) for(int i=f;i<t;i++)
#define R(i,n) for(ll i=0;i<n;i++)
#define cint(x) int x; cin >> x;

#define print(cnt,x) cout<<"Case #"<<cnt<<": "<<x<<"\n";

template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

#ifdef LOCAL
#define fr freopen("in.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

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

inline void scf(int &x)
{
	bool f=0; x=0; char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') { f=1; c=getchar(); }
	while(c>='0' && c<='9') { x=x*10+c-'0'; c=getchar(); }
	if(f) x=-x; return;
}

void sc(int &x,int &y) { scf(x); return scf(y); }
void sc(int &x,int &y,int &z) { scf(x); scf(y); return scf(z); }

#define inf 1e9
const double eps = 1e-7;

int main(){
	std::ios::sync_with_stdio(false);
	fr;
	int tt = 1; F(tc, 1, tt + 1){
		cint(n); vi inp(1000009,0);
		R(i, n) {cint(x); inp[x]++;}
		cint(x);
		R(i, x){
			cint(q);
			cout << inp[q] << endl;
		}
	}
	return 0;
}