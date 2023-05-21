#include<stdio.h>
#include<stdlib.h>
struct pstruct
{
    int fno;
    int pbit;
}
ptable[10];
int pmsize,lmsize,psize,frame,page,ftable[20],frameno;
void info()
{
    printf("\n\t\tMEMORY MANAGEMENT USING PAGING\n\t\t	\n");
    printf("Enter the Size of Physical memory: ");
    scanf("%d",&pmsize);
    printf("Enter the size of Logical memory: ");
    scanf("%d",&lmsize);
    printf("Enter the partition size: ");
    scanf("%d",&psize);
    frame = (int) pmsize/psize;
    page = (int) lmsize/psize;
    printf("The physical memory is divided into %d no.of frames\n",frame);
    printf("The Logical memory is divided into %d no.of pages\n",page);
}
void assign()
{
    int i;
    for(i=0;i<page;i++)
    {
        ptable[i].fno = -1;
        ptable[i].pbit= -1;
    }
    for(i=0; i<frame;i++)
        ftable[i] = 32555;
    for (i=0;i<page;i++)
    {
        printf("Enter the Frame number where page %d must be placed: ",i);
        scanf("%d",&frameno);
        ftable[frameno] = i;
        if(ptable[i].pbit == -1)
        {
            ptable[i].fno = frameno;
            ptable[i].pbit = 1;
        }
    }
    printf("\n\tPAGE TABLE\n\t	\n");
    printf("PageAddress FrameNo. PresenceBit\n");
    for(i=0;i<page;i++)
    printf("%d\t\t%d\t\t%d\n",i,ptable[i].fno,ptable[i].pbit);
    printf("\n\tFRAME TABLE\n\t	\n");
    printf("FrameAddress PageNo\n");
    for(i=0;i<frame;i++)
        printf("%d\t\t%d\n",i,ftable[i]);
}
void cphyaddr()
{
    int laddr,paddr,disp,phyaddr,baddr;
    printf("\n\tProcess to create the Physical Address\n");
    printf("Enter the Base Address: ");
    scanf("%d",&baddr);
    printf("Enter theLogical Address: ");
    scanf("%d",&laddr);
    paddr = laddr / psize;
    disp = laddr % psize;
    if(ptable[paddr].pbit == 1 )
    phyaddr = baddr + (ptable[paddr].fno*psize) + disp;
    printf("The Physical Address where the instruction present: %d",phyaddr);
}
void main()
{
    info();
    assign();
    cphyaddr();
}
