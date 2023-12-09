#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[200010],sum[200010],ans,temp[200010];
//sum为前缀和
int n,m;
void merge(int l,int mid,int r){
    int p1=l,p2=mid+1,k=l-1;
    while(p1<=mid&&p2<=r){
        if(sum[p1]<sum[p2]){
            ans+=(mid-p1+1);
            ans%=92084931;
            temp[++k]=sum[p2];
            p2++;
        }
        else if(sum[p1]>=sum[p2]){
            temp[++k]=sum[p1];
            p1++;
        }
    }
    while(p1<=mid) temp[++k]=sum[p1++];
    while(p2<=r) temp[++k]=sum[p2++];
    for(int i=l;i<=r;i++)
        sum[i]=temp[i];
}
void mergesort(int l,int r){
    if(l<r){
        int mid=(l+r)>>1;
        mergesort(l,mid);
        mergesort(mid+1,r);
        merge(l,mid,r);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]-=m;
        sum[i]=sum[i-1]+a[i];
    }
    mergesort(0,n);
    printf("%d\n",ans);
    return 0;
}