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

int k,X,n,m,ans;
int mx,ra,rb,rx,ry;
int ar[mxn];
int pr[5] = { 'A','C','Z' };

void read(){

//	freopen( ".in" , "r" , stdin );
//	freopen( ".out" , "w" , stdout );

	scanf( "%d %d %d %d" , &k , &X , &n , &m );

	return;

}

int coun( int a,int b,int uz,int mx ){

	int i,cnt=0;

	ar[1] = a;
	for( i=2 ; i<uz ; i++ )		ar[i] = !ar[i-1];
	ar[uz] = b;

	for( i=1 ; i<uz ; i++ )		cnt += ( ar[i]==0 ) && ( ar[i+1]==1 );

	if( cnt>mx && ar[1]==0 && ar[2]==1 ){
		ar[2] = 2;
		cnt--;
	}

	for( i=2 ; i<uz && cnt>mx ; i++ )
	if( ar[i]==0 && ar[i+1]==1 ){

		ar[i] = 2;
		cnt--;

	}


	return cnt;

}

bool check( int aa , int bb , int xx , int yy ){

	int a,b,x,y,i;
	int s1,s2,ss1,ss2,p,q;
	int t1,t2,ta,tb,tx,ty;

	ss1 = coun( aa,bb,n,n );
	ss2 = coun( xx,yy,m,m );

	for( p=0 ; p<=ss1 ; p++ )
	for( q=0 ; q<=ss2 ; q++ ){

		if( p==0 && n==2 && aa==0 && bb==1 )	continue;
		if( q==0 && m==2 && xx==0 && yy==1 )	continue;

		s1 = p;
		s2 = q;
		a = aa;
		b = bb;
		x = xx;
		y = yy;

		for( i=3 ; i<=k ; i++ ){

			ta = x;
			tb = y;
	
			tx = a;
			ty = y;
	
			t1 = s2;
			t2 = s1+s2 + ( b==0 && x==1 );


			a = ta;
			b = tb;
			x = tx;
			y = ty;
			s1 = t1;
			s2 = t2;

			if( s2>X )	break;

		}

		if( s2==X ){

//			cout<<aa<<" "<<bb<<" "<<xx<<" "<<yy<<" "<<p<<" "<<q<<endl;

			coun( aa,bb,n,p );
			for( i=1 ; i<=n ; i++ )		printf( "%c" , pr[ ar[i] ] );
			puts( "" );

			coun( xx,yy,m,q );
			for( i=1 ; i<=m ; i++ )		printf( "%c" , pr[ ar[i] ] );
			puts( "" );

			return 1;

		}

	}

	return 0;

}

void solve(){

	int a,b,x,y;

	for( a=0 ; a<3 ; a++ )
	for( b=0 ; b<3 ; b++ )
	for( x=0 ; x<3 ; x++ )
	for( y=0 ; y<3 ; y++ ){

		if( n==1 && a!=b ) 	continue;
		if( m==1 && x!=y )	continue;

		if( check( a,b,x,y ) )	return;

	}
	
	puts( "Happy new year!" );

	return;

}

int main(){
	read();
	solve();
	return 0;
}
