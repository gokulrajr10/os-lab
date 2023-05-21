#include<stdio.h>
int f[50],inde[50],i,j,k,c,p,n,count=0;
void main()
{
    for(i=0;i<50;i++)
        f[i]=0;
    X:
        printf("Enter index block\t");
        scanf("%d",&p);
        if(f[p]==0)
        {
            f[p]=1;
            printf("Enter no. of files on index\t");
            scanf("%d",&n);
        }
        else
        {
            printf("Block already allocate\n");
            goto X;
        }
        for(i=0;i<n;i++)
            scanf("%d",&inde[i]);
        for(i=0;i<n;i++)
            if(f[inde[i]]==1)
            {
                printf("Block alreay allocated");
                goto X;
            }
        for(j=0;j<n;j++)
        f[inde[j]]=1;
            printf("\nallocated");
            printf("\nfile indexed");
        for(k=0;k<n;k++)
            printf("\n%d->%d:%d",p,inde[k],f[inde[k]]);
        printf("\nEnter 1 to enter more files and 0 to exit\t");
        scanf("%d",&c);
        if(c==1)
            goto X;
        else
            exit(0);
}
