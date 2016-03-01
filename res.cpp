    #include<stdio.h>
    int main()
    {
    int t,n,i,swap;
    //int a=new int[5];
    scanf("%d",&t);
    while(t!=0)
    {
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    if(i==0)
    continue;
    else if(i%2==1)
    {
    if(a[i]<a[i-1])
    {
    swap=a[i];
    a[i]=a[i-1];
    a[i-1]=swap;
    }
    else continue;
    }
    else if(i%2==0)
    {
    if(a[i]>a[i-1])
    {
    swap=a[i];
    a[i]=a[i-1];
    a[i-1]=swap;
    }
    else continue;
    }
    }
    for(i=0;i<n;i++)
    {
    if(i!=n-1)
    printf("%d ",a[i]);
    else
    printf("%d",a[i]);
    }
	printf("\n");
    t--;
    }
    }

