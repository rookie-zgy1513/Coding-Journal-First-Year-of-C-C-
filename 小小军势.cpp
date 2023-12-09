#include<stdio.h>
int main()
{
	char ch;
	int use[128]={0},m,max=0,i;
	while(ch=getchar()!=EOF){
		if(ch=='a'){m=1;
		}
		
		else if(ch=='b'){m=2;
		}
		
		else if(ch=='c'){m=3;
		}
		
		else if(ch=='d'){m=4;
		}
		
		else if(ch=='e'){m=5;
		}
		
		else if(ch=='f'){m=6;
		}	
	
		else if(ch=='g'){m=7;
		}
		
		else if(ch=='h'){	m=8;
		}
	
		else if(ch=='i'){	m=9;
		}
	
		else if(ch=='j'){m=10;
		}
		
		else if(ch=='k'){m=11;
		}
		
		else if(ch=='l'){m=12;
		}
		
		else if(ch=='m'){m=13;
		}
		
		else if(ch=='n'){m=14;
		}
		
		else if(ch=='o'){	m=15;
		}
	
		else if(ch=='p'){	m=16;
		}
	
		else if(ch=='q'){	m=17;
		}
	
		else if(ch=='r'){	m=18;
		}
	
		else if(ch=='s'){	m=19;
		}
	
		else if(ch=='t'){m=20;
		}
		
		else if(ch=='u'){m=21;
		}
		
		else if(ch=='v'){m=22;
		}
		
		else if(ch=='w'){m=23;
		}
		
		else if(ch=='x'){	m=24;
		}
	
		else if(ch=='y'){m=25;
		}
		
		else if(ch=='z'){	m=26;
		}
	
		use[m]++;
	}
	for(i=1;i<=128;i++){
		if(use[i]>max)
		max=use[i];
	}
	printf("%d",max);
	return 0;
}