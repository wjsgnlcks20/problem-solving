#include<bits/stdc++.h>
using namespace std;

#define nn 10001
#define f first
#define s second
typedef vector<pair<int,int>> vpii;

int n, a[nn], b1[nn], b2[nn];
int m=0, l1=1, r1=1, l2=1, r2=1;
vpii seg;

void turn(int l, int r){
    for( int i=l; i<=r; i++ ) b2[i] = b1[i];
    for( int i=l,j=r; i<=r; i++,j-- ) b1[i] = b2[j];
}
void dfs( int x, vpii now ){
    if( m<0 ) return;
    if( x==2 ){
        vpii tmp = seg;
        int s1 = now[0].f, s2 = now[0].s;
        int L1 = seg[s1].f, R1 = seg[s2].s;
        for( int i=1; i<=n; i++ ) b1[i] = a[i];
        
        turn( L1, R1 ); // 첫 번째 뒤집기
        for( int i=s1; i<=s2; i++ ){
            tmp[i].f = L1+R1 - tmp[i].f;
            tmp[i].s = L1+R1 - tmp[i].s;
            swap(tmp[i].f,tmp[i].s);
        }
        for( int i=0; i<=(s2-s1)/2; i++ ) swap(tmp[s1+i],tmp[s2-i]);
        int L2 = tmp[now[1].f].f, R2 = tmp[now[1].s].s;
        turn( L2, R2 ); // 두 번째 뒤집기
        
        for( int i=1; i<=n; i++ ) if( i!=b1[i] ) return;
        m=-1, l1 = L1, r1 = R1, l2 = L2, r2 = R2;
        return;
    }
    for( int i=0; i<m; i++ ){
        for( int j=i; j<m; j++ ){
            now.push_back({i,j});
            dfs(x+1,now);
            now.pop_back();
        }
    }
}
int main(){
    scanf("%d",&n);
    int l=n+1, r=0;
    for( int i=1; i<=n; i++ ){
        scanf("%d",&a[i]);
        if(i!=a[i]) l = min(l,i), r = max(r,i);
    }
    for( int i=l; i<=r; i++ ){
        int nl = i, nr = i, j = i+1;
        if( i<r ){
            if( a[i]-1==a[i+1] ){ 
                while( j+1<=r && a[j]-1==a[j+1] ) j++;
                nr = i = j;
            }else if(a[i]+1==a[i+1]){
                while( j+1<=r && a[j]+1==a[j+1] ) j++;
                nr = i = j;
            }
        }
        seg.push_back({nl,nr}); // 뒤집기 후보 구간 추가
        m++;
    }
    if( m==1 ) l1=seg[0].f, r1=seg[0].s;
    else{
        vpii tmp;
        if( m==2 ){ // 예외 케이스를 위한 후보 구간 분할
            if( seg.back().s-seg.back().f==1 ){
                int i = seg.back().f;
                seg.back().s = i;
                seg.push_back({i+1,i+1});  
            }
            if( seg.front().s-seg.front().f==1 ){
                int i = seg.front().f;
                seg.front().s = i;
                seg.push_back({i+1,i+1}); 
            }
            sort(seg.begin(),seg.end());
            m = int( seg.size() );
        }
        dfs(0,tmp); // 후보 구간을 조합하여 모든 두 번 뒤집기에 대한 완전 탐색
    }
    printf("%d %d\n%d %d",l1,r1,l2,r2);
    return 0;
}