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
#define mxn       	105
using namespace std;

pii r[mxn];

int n,m;
int c[mxn];
int ar[mxn];
int use[mxn];
int ans,cnt;

void read(){
//	freopen( ".in" , "r" , stdin );
//	freopen( ".out" , "w" , stdout );

	int i;
	string str;

	scanf( "%d %d" , &n , &m );

	for( i=1 ; i<=n ; i++ ){

		cin>>str>>r[i].st;

		if( str=="ATK" )	r[i].nd = 1;
		else				r[i].nd = 0;

	}

	for( i=1 ; i<=m ; i++ )		scanf( "%d" , c+i );

	return;

}

void solve1(){

	int ind,i,j;

	cnt = 0;
	ind = 0;

	for( i=1 ; i<=n ; i++ )
	if( r[i].nd==0 )	ar[++ind] = r[i].st+1;

	sort( ar+1,ar+ind+1 );

	j = 1;

	for( i=1 ; i<=ind ; i++ ){

		while( j<=m && ar[i]>c[j] )	j++;

		if( j==m+1 )	return;

		use[j] = 1;
		j++;

	}

	ind = 0;
	for( i=1 ; i<=n ; i++ )
	if( r[i].nd==1 )	ar[++ind] = r[i].st;

	sort( ar+1,ar+ind+1 );

	j=1;

	for( i=1 ; i<=ind ; i++ ){

		while( j<=m && ( use[j] || ar[i]>c[j] ) )	j++;

		if( j==m+1 )	return;

		j++;

		cnt -= ar[i];

	}

	for( i=1 ; i<=m ; i++ )
	if( !use[i] )	cnt += c[i];

	ans = max( ans,cnt );

}

void solve2(){

	int ind,i,j;

	cnt = 0;
	ind = 0;

	for( i=1 ; i<=n ; i++ )
	if( r[i].nd==1 )	ar[++ind] = r[i].st;

	sort( ar+1,ar+ind+1 );

	i = 1;
	j = m;

	while( i<=ind && j>=1 && c[j]>=ar[i] ){
		cnt += c[j] - ar[i];
		i++;
		j--;
	}

	ans = max( ans , cnt );

	return;
}

int main(){

	read();

	sort( r+1 , r+n+1 );
	sort( c+1 , c+m+1 );

	solve1();
	solve2();

	printf( "%d\n" , ans );

	return 0;
}
