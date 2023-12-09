#include <stdio.h>
int main(void) {
int num, i, key;
//不定组数据的各种输入方式还请各位牢记
while (scanf("%d%d%d", &num, &i, &key) != EOF) {
int tmp = ~(((1<<4)-1)<< i);//15的二进制码为1111左移并取反之后为111……100001……11的形式
num &= tmp;//进行按位与操作后，num需要修改的位的二进制码变为0，其余位不变
num |= (key << i);//将替换上去的数字移动到对应的区域进行按位或，得到最终结果
printf("%d\n", num);//与例题不同，本体以十进制输出结果，使用%d格式符
}
return 0;
}