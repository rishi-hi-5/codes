    #include<stdio.h>
    #include<string.h>
    int t,i,l;
    long int n;
    char s[100000];
    int main()
    {
    scanf("%d",&t);
    while(t--)
    {
    n=1;
    scanf("%s",s);
    // puts(s);
    l=strlen(s);
    for(i=0;i<l;i++)
    {
    if(s[i]=='l')
    {
    n=(2*n-1)+(1-i%2);
    }
    else
    {
    n=(2*n+1)+(1-i%2);
    }
    n=n%1000000007;
    }
    printf("%ld\n",n);
    }
    return 0;
     
    }

