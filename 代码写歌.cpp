#include<stdio.h>
int main()
{
    int i=0;
	int n,s,p,l;
	int f[100];
	int t[100];
	scanf("%d%d",&n,&s);
	
	while(i<n){
		scanf("%d%d",&p,&l);
		if(p==0){f[i]=0;
		}
		else if(p==1){f[i]=523;
		}
		else if(p==2){f[i]=587;
		}
		else if(p==3){f[i]=659;
		}
		else if(p==4){f[i]=698;
		}
		else if(p==5){f[i]=784;
		}
		else if(p==6){f[i]=880;
		}
		else if(p==7){f[i]=988;
		}
		t[i]=l*s;
		i++;
		}
		i=0;
		printf("#include<stdio.h>\n#include<stdlib.h>\n\nint main(){\n");
		while(i<n){printf("    _beep(%d, %d);\n",f[i],t[i]);
		i++;
		}
	printf("}");
	return 0;
}