#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<climits>
#include<ctime>
#include<sstream>
#define mp       	make_pair
#define pb       	push_back
#define st       	first
#define nd       	second
#define wait     	getchar();getchar();
#define lint     	long long
#define KARE(a)	 	( (a)*(a) )
#define MAX(a,b) 	( (a)>(b) ? (a) : (b) )
#define MIN(a,b) 	( (a)<(b) ? (a) : (b) )
#define MAX3(a,b,c)	( MAX( a,MAX(b,c) ) )
#define MIN3(a,b,c)	( MIN( a,MIN(b,c) ) )
#define FILL(ar,a)	memset( ar,a,sizeof ar )
#define oo	 		1e9
#define pii       	pair<int,int>
#define pll			pair<lint,lint>
#define pdd			pair<double,double>
#define y1			yy1
#define eps      	(1e-9)
#define esit(a,b)  	( abs( (a)-(b) ) < eps )
#define sol(a)		( (a)<<1 )
#define sag(a)		( sol(a)|1 )
#define orta(a,b)	( ( (a)+(b) )>>1 )
#define mxn       	100005
using namespace std;

vector< pii >adj[mxn];

int vis[mxn],v;
int n,m;
int del[mxn];
int sum[mxn];
char ans[mxn];

void read(){
//	freopen( ".in" , "r" , stdin );
//	freopen( ".out" , "w" , stdout );

	int a,b;

	scanf( "%d" , &n );

	for( int i=1 ; i<n ; i++ ){
		scanf( "%d %d" , &a , &b );
		adj[a].pb( mp(b,i) );
		adj[b].pb( mp(a,i) );
	}

	return;
}

int find( int nod ){

	int i,b,p,t,f;

	vis[nod] = v;
	sum[nod] = 1;

	p = -1;
	f = 1;

	for( i=0 ; i<adj[nod].size() ; i++ )
	if( !del[ adj[nod][i].nd ] ){

		b = adj[nod][i].st;

		if( vis[b]==v )	p = b;
		else{

			t = find( b );
			if( t )		return t;

			sum[nod] += sum[b];
			if( sum[b] > (m+1)/2 )	f = 0;

		}

	}

	if( p!=-1 && ( m-sum[nod] )>(m+1)/2 )	f = 0;

	if( f )	return nod;
	else	return 0;

}

void dfs( int nod ){

	int i,b;

	vis[nod] = v;
	m++;

	for( i=0 ; i<adj[nod].size() ; i++ ){

		b = adj[nod][i].st;
		if( !del[ adj[nod][i].nd ] && vis[b] != v )		dfs( b );
	}

	return;

}

void rec( int nod , char c ){

	int i,u;

	for( i=0 ; i<adj[nod].size() ; i++ )
	if( !del[ adj[nod][i].nd ] )	break;

	if( i==adj[nod].size() ){
		ans[nod] = c;
		return;
	}

	m = 0;
	v++;
	dfs( nod );

	v++;
	u = find( nod );

	ans[u] = c;

	for( i=0 ; i<adj[u].size() ; i++ )
	if( !del[ adj[u][i].nd ] ){

		del[ adj[u][i].nd ] = 1;
		rec( adj[u][i].st,c+1 );

	}

	return;

}

void solve(){

	read();

	rec(1,'A');

	for( int i=1 ; i<=n ; i++ )		printf( "%c " , ans[i] );
	puts("");

	return;
}

int main(){
	solve();
	return 0;
}
