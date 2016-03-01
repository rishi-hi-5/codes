#include<stdio.h>

int main()
{
int i=-3, j=2, m, k=0;
m=++i && ++j || ++k;
printf("%d %d %d %d", i, j, m, k);
}
