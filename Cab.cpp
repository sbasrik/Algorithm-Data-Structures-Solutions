#include<iostream>
#include<cstdlib>
#include<cstring>
#define llong long long long
#define maxN 100005
using namespace std;

long long A[maxN];
long long N,Q;
long long L,R;
long long powerOf2[20];
long long segTree[20][4*maxN];
long long lazy[20][4*maxN];

long long getSum(long long p, long long id, long long left, long long right){

    if(R<left || L>right)
        return 0;

    if(L<=left && R>=right){
        if(lazy[p][id]!=-1)
            return lazy[p][id]*(right-left+1);
        else
            return segTree[p][id];
    }

    long long mid = (left+right)>>1;

    if(lazy[p][id]!=-1){

        lazy[p][2*id]  = lazy[p][id];
        lazy[p][2*id+1] = lazy[p][id];
        segTree[p][id] = lazy[p][id]*(right-left+1);
        lazy[p][id] = -1;

    }

    return getSum(p,2*id,left,mid) +
           getSum(p,2*id+1,mid+1,right);

}

long long update(long long p,long long id,long long left,long long right,long long val){

    if(R<left || L>right){
        if(lazy[p][id]!= -1)
            return lazy[p][id]*(right-left+1);
        return segTree[p][id];
    }

    if(L<=left && R>=right){
        lazy[p][id] = val;
        return val*(right-left+1);
    }

    long long mid = (left+right)>>1;

    if(lazy[p][id]!=-1){

        lazy[p][2*id]  = lazy[p][id];
        lazy[p][2*id+1] = lazy[p][id];
        lazy[p][id] = -1;

    }

    return segTree[p][id] = update(p, 2*id, left, mid, val) +
                            update(p, 2*id+1, mid+1, right, val);

}

void init(){
    for(long long i=0;i<20;i++)
        powerOf2[i] = (1LL<<i);

    memset(lazy,-1,sizeof lazy);

    for(long long j=0;j<20;j++){

        for(long long i=0;i<N;i++)
        if( powerOf2[j] & A[i] ){
            L = R = i+1;
            update(j,1,1,N,1);
        }
    }

}

int main(){

    long long X,i,j,qType;
    long long sum = 0;

    scanf("%lli" , &N);

    for(long long i=0;i<N;i++)
        scanf("%lli", A+i);

    scanf("%lli",&Q);

    init();

    for(i=0;i<Q;i++){

        scanf("%lli %lli %lli" , &qType, &L , &R);

        if(qType==1){
            sum = 0;
            for(j=0;j<20;j++){
                sum += powerOf2[j]*getSum(j,1,1,N);
            }

            cout<<sum<<endl;

        }
        else{
            scanf("%lli", &X);
            update(X-1,1,1,N,3-qType);
        }

    }

    return 0;

}