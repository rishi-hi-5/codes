#include<stdio.h>
 
int main()
{
char str[100001];
int i,t,l;
long long int ans;
ans=0;i=0;t=0;
scanf("%d",&t);
while(t--)
{
scanf("%s",str);
ans=1;
l=1;
for(i=0;str[i]!='\0';i++)
{
if(str[i]=='l')
{
if(l%2==1)
ans=(ans*2)%1000000007;
else
ans=((ans*2)-1)%1000000007;
}
else
{
if(l%2==1)
ans=((ans+1)*2)%1000000007;
else
ans=((ans*2)+1)%1000000007;
}
l++;
}
printf("%lld\n",ans);
}
return(0);
}
