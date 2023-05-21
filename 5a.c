#include<stdio.h>
int main()
{
    int masters,s[20];
    char f[20][20][20];
    char d[20][20];
    int i,j;
    printf("Enter number of directories:");
    scanf("%d",&masters);
    printf("Enter name of directories:");
    for(i=0;i<masters;i++)
        scanf("%s",&d[i]);
    printf("Enter the size of directories:");
    for(i=0;i<masters;i++)
        scanf("%d",&s[i]);
    printf("Enter the file name:");
    for(i=0;i<masters;i++)
    for(j=0;j<s[i];j++)
        scanf("%s",&f[i][j]);
    printf("\n");
    printf("Directory \t Size \t File Names \n");
    printf("\n");
    for(i=0;i<masters;i++)
    {
        printf("%s \t\t%d \t",d[i],s[i]);
        for(j=0;j<s[i];j++)
            printf("%s\n\t\t\t",f[i][j]);
        printf("\n");
    }
    printf("\t\n");
}
