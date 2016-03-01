#include <stdio.h>

int main(void)
{
  int a[2], *p1=&a[0], *p2=&a[1];
  printf("p2=%p\n",p2);
  printf("p1=%p\n",p1);	
  printf(" p2-p1 = %lu\n", p2-p1);
  printf(" (int)p2-(int)p1 = %u\n", (int)p2-(int)p1);
  
  return 0;
}
