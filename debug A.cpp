#include <stdio.h>

char num[20][10] = {       
    "0000", "0001", "0010", "0011", 
    "0100", "0101", "0110", "0111", 
    "1000", "1001", "1010", "1011", 
    "1100", "1101", "1110", "1111"
};
int main(){
    int c;
    int a = 0;
    while(scanf("%c", &c) != EOF){
        if(c >= '0' && c <= '9')
            printf("%s", num[c - '0']);
        else if(c >= 'a' && c <= 'f')
            printf("%s", num[c - 'a' + 10]);
        else
            printf("\n");
    }
    return 0;
}