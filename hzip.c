#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define ArraySize(x) (sizeof(x)/sizeof(x[0]))
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define FD(i,l,r) for(int i=(l);i<(r);i++)
#define SWAP(a,b) x^=y,y^=x,x^=y
#define eps 1e-8
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
#define MAXSIZE  32
struct cc {	 //字符及出现次数结构
    char c;
    int count;
} ;
struct tnode { //Huffman树结构
    struct cc ccount; //字符及出现次数
    struct tnode *left,*right;  //树的左右节点指针
    struct tnode *next;  //一个有序链表的节点指针
} ; 
struct tnode *Head=NULL; //一个有序链表的头节点，也是最后Huffman树的根节点
char Huffman[MAXSIZE]; //用于生成Huffman编码
char HCode[128][MAXSIZE]; //字符的Huffman编码，Hcode[0]为文件结束符的编码
struct cc ccount[128];

void createHCode(struct tnode *p,char code, int level)
{
    if(level != 0)
        Huffman[level-1] = code;  
    if(p->left == NULL && p->right == NULL){
        Huffman[level] ='\0' ;
        strcpy(HCode[p->ccount.c], Huffman);
    }
    else {
        createHCode(p->left, '0', level+1);
        createHCode(p->right, '1', level+1);
    }
} 
void insertSortLink(struct tnode* p){
	struct tnode* q=NULL;
	struct tnode* r=NULL;
	q = (struct tnode*)malloc(sizeof(struct tnode));
	r = (struct tnode*)malloc(sizeof(struct tnode));
	if(Head==NULL){
		Head=p;
		return ;
	}
	else{
		for(q=Head;q!=NULL;r=q,q=q->next){
			if(p->ccount.count<q->ccount.count){
				if(q==Head){
					p->next=Head;
					Head=p;
					return ;
				}
				else{
					p->next=q;
					r->next=p;
					return ;
				}
			}
		}
		r->next=p;
		p->next=NULL;
		return ;
	}
}   
void madeHZIP(FILE *src, FILE *obj)
{
    unsigned char *pc,hc=0;
    int c=0,i=0;
    fseek(src,0, SEEK_SET); //从src文件头开始
    do {
        c=fgetc(src) ;	 //依次获取源文件中每个字符
        if (c == EOF) c=0; 	//源文件结束
        for(pc = HCode[c]; *pc != '\0'; pc++){ 	//转换为huffman码
            hc = (hc << 1) | (*pc-'0'); i++; 
            if(i==8){ 	//每满8位输出一个字节
                fputc(hc,obj); i = 0;
            }
        }
        if(c==0 && i!=0){ //处理文件结束时不满一个字节的情况
             while(i++<8) hc = (hc << 1);
             fputc(hc,obj); 
        }
     } while (c ); //c=0时文件结束
}

int main()
{
	char c;
	int i=0;
	FILE*fp,*fp1;
	fp=fopen("myfile.txt","r+");
	fp1=fopen("myfile.hzip","w");
	while( (c=fgetc(fp)) != EOF){
   		ccount[c].c=c; ccount[c] .count++;
	} 
	struct tnode *p;
	for(i=0; i<128; i++)
    	if(ccount[i].count != 0){
        	p = (struct tnode *)malloc(sizeof(struct tnode));
        	p->ccount = ccount[i];
        	p->left = p->right = p->next = NULL;
       	insertSortLink(p);
    	}
while(Head->next != NULL){
    p = (struct tnode *)malloc(sizeof(struct tnode));  
    p ->ccount.count = Head->ccount.count + Head->next->ccount.count;
    p->left = Head; p->right = Head->next;  /*将新树的根结点加入到有序结点链表中*/
    p->next = NULL;
    Head = Head->next->next; 
    insertSortLink(p);
}
createHCode(Head,'0', 0);
madeHZIP(fp,fp1);
fclose(fp);
fclose(fp1);
return 0;	
}