#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int k=0,n,len,d,e;
char s[35],a[23][23];
int b[23][23];
void CZ(int x,int y,int z)
{
	b[x][y]=1; 
	if(a[x][y]==s[z])
	{
		if(z==len-1)
		{
		k=len;
		d=x;
		e=y; 
		return;
	    }
		if(x<n-1&&a[x+1][y]==s[z+1]&&b[x+1][y]==0)
		{
		CZ(x+1,y,z+1);
	    }
		if(x>0&&a[x-1][y]==s[z+1]&&b[x-1][y])
		CZ(x-1,y,z+1);
		if(y<n-1&&a[x][y+1]==s[z+1]&&b[x][y+1]==0)
		CZ(x,y+1,z+1);
		if(y>0&&a[x][y-1]==s[z+1]&&b[x][y-1]==0)
		CZ(x,y-1,z+1);
	}
	b[x][y]=0;
	return ;
}
int main()
{
	int i,j;
	scanf("%d",&n);
	scanf("%s",s);
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	len=strlen(s);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			CZ(i,j,0);
			if(k==len)
			{
				break;
			}
		}
		if(k==len)
		break;
	}
	printf("%d %d",d+1,e+1);
	return 0;
 }