#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct _QJ {
    int lf;
    int z,y;
    int rt;
} QJ;
QJ a[500005];
int cmp(const void *p, const void *q) {
    QJ *v1=(QJ *)p;
    QJ *v2=(QJ *)q;
    if(v1->z > v2->z) return 1;
    else if(v1->z < v2->z) return -1;
    else {
        if((v1->lf)>(v2->lf))
            return -1;
        else if((v1->lf)<(v2->lf))
            return 1;
        else
            return 0;
    }
}
int main() {
    int i=0,n;
        char l,r,mid;
    while(scanf("%c%d,%d%c ",&l,&a[i].z,&a[i].y,&r)!=EOF)
    {
         if(l=='(')
         a[i].lf=1;
         else
         a[i].lf=2;
         if(r==')')
         a[i].rt=1;
   else{
   a[i].rt=2;
   }
         
        i++;
    }    
	n=i;
	for(i=0;i<n;i++){
		printf("%d %d\n",a[i].z,a[i].y);
	}
    /*qsort(a,n,sizeof(QJ),cmp);
    int zb,yb,flag=0,khz,khy;
    for(i=0; i<n; i++) {
        if(flag==0) {
            zb=a[i].z;
            yb=a[i].y;
            khz=a[i].lf;
            khy=a[i].rt;
            flag=1;
        } else {
            if(((a[i].z)>yb)||(a[i].z==yb&&(khy==1)&&(a[i].lf==1))) {
                if(khz==1)
                printf("(");
                else
                printf("[");
    printf("%d,%d",zb,yb);
    if(khy==1)
    printf(")\n");
    else
    printf("]\n");
                zb=a[i].z;
                yb=a[i].y;
                khz=a[i].lf;
                khy=a[i].rt;
            } else {
                if(yb<a[i].y) {
                    yb=a[i].y;
                   khy=a[i].rt;
                } else if(yb==a[i].y) {
                    if(khy==2||a[i].rt==2)
                        khy=2;
                }
            }
        }
    }*/
    return 0;
}
