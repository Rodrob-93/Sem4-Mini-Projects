#include<stdio.h>
#include<string.h>
int max(int x, int y)
{
    if (x<y)
        return y;
    return x;
}
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void main()
{
    int nd,nc,i,j,k,hpd[20],mpc[20],ca[20],mpce[20],lavail=1000,temp,cn[i],t;
    char ns[20];
    static int demp[20],noc[20],da[20],hpde[20],cnn[20][3];
    printf("\n\t\tEXAM STUDY TIME TABLE\n");
    printf("\nPrepared By :Robin     60004170093\nRomil     60004170096\nRushikesh 60004170097\n");
    printf("\nEnter Name Of Subject : ");
    scanf("%s",&ns);
    printf("\nEnter Number Of Days Remaining For Exam Of %s : ",ns);
    scanf("%d",&nd);
    printf("Enter the hours available for studying :\n");
    for(i=1;i<=nd;i++)
    {
        printf("Enter available hours for Day %d : ",i);
        scanf("%d",&hpd[i]);
        hpde[i]=hpd[i];
    }
    printf("\nEnter Number Of Chapters In %s : ",ns);
    scanf("%d",&nc);
    printf("Enter the chapterwise weightage : \n");
    for(i=1;i<=nc;i++)
    {
        printf("Enter the weightage for Chapter %d : ",i);
        scanf("%d",&mpc[i]);
        cn[i]=i;
    }
   for(i=1;i<=nc;i++)
        for(j=1;j<nc-i+1;j++)
            if(mpc[j]<mpc[j+1])
            {
                swap(&mpc[j],&mpc[j+1]);
                swap(&cn[j],&cn[j+1]);
            }
   for(i=1;i<=nc;i++)
       if(mpc[i]/3!= 0) 
           mpce[i]=mpc[i]/3;
       else
           mpce[i]=mpc[i];
    for(i=1,k=0;i<=nc;i++)
    {
        for(j=1;j<=nd;j++)
        {
            if(hpde[j]!=0)
            {
                temp=hpde[j]-mpce[i];
                if(temp>=0)
                {
                    if(lavail>temp)
                    {
                        da[i]=j;
                        lavail=temp;
                    }
                }
            }
        }
        hpde[da[i]]=hpde[da[i]]-mpce[i];
        noc[da[i]]++;
        lavail=1000;
        if(cnn[da[i]][k]!=0)
        {
            k++;
        }
        cnn[da[i]][k]=cn[i];
    }
    //BEST FIT
    printf("\nAccording To Modified Best Fit...");
    printf("\nTime Table:\n+-----|---------------|------------|------------|-------------------+\n");
    printf("| Day | Hours Alloted | Chapter No | Hours free | Chapters Assigned |\n");
    printf("|-----|---------------|------------|------------|-------------------|\n");
    for(i=1;i<=max(nd,nc);i++)
    {
        k=0;
        if(cnn[i][k+1]!=0)
            t=i;
        do
        {
            if(t==i)
                printf("|  %d* |       %d       |      %d     |     %d      |         %d         |\n",i,hpd[i],cnn[i][k],hpde[i],noc[i]);
            else if(cnn[i][k]==0)
                printf("|  %d  |       %d       |      -     |     %d      |         -         |\n",i,hpd[i],cnn[i][k],hpde[i],noc[i]);
            else if(i<=nc && i<=nd)
                printf("|  %d  |       %d       |      %d     |     %d      |         %d         |\n",i,hpd[i],cnn[i][k],hpde[i],noc[i]);
            else if(i>nc)
                printf("|  %d  |       %d       |      -     |     %d      |         -         |\n",i,hpd[i],hpde[i]);
            else{}
            printf("|-----|---------------|------------|------------|-------------------|\n");
            k++;
        }while(cnn[i][k]!=0);
    }
    printf("\n* indicates multiple chapters on that day!\n");
    //WORST FIT
    lavail=0;
    t=0;
    for(i=1;i<=nd;i++)
    {
        hpde[i]=hpd[i];
        da[i]=0;
        noc[i]=0;
        for(k=0;k<=3;k++)
            cnn[i][k]=0;
    }
    for(i=1,k=0;i<=nc;i++)
    {
        for(j=1;j<=nd;j++)
            if(hpde[j]!=0)
            {
                temp=hpde[j]-mpce[i];
                if(temp>=0)
                {
                    if(lavail<temp)
                    {
                        da[i]=j;
                        lavail=temp;
                    }
                }
            }
        hpde[da[i]]=hpde[da[i]]-mpce[i];
        noc[da[i]]++;
        lavail=0;
        if(cnn[da[i]][k]!=0)
            k++;
        cnn[da[i]][k]=cn[i];
    }
    // printf("\t\t\tSUBJECT NAME %s : ",ns);
    printf("\nAccording To Modified Worst Fit...");
    printf("\n\n+-----|---------------|------------|------------|-------------------+\n");
    printf("| Day | Hours Alloted | Chapter No | Hours free | Chapters Assigned |\n");
    printf("|-----|---------------|------------|------------|-------------------|\n");
    for(i=1;i<=max(nd,nc);i++)
    {
        k=0;
        if(cnn[i][k+1]!=0)
            t=i;
        do
        {
            if(i==t)
                printf("|  %d* |       %d       |      %d     |     %d      |         %d         |\n",i,hpd[i],cnn[i][k],hpde[i],noc[i]);
            else if(cnn[i][k]==0)
                printf("|  %d  |       %d       |      -     |     %d      |         -         |\n",i,hpd[i],cnn[i][k],hpde[i],noc[i]);
            else if(i<=nc && i<=nd)
                printf("|  %d  |       %d       |      %d     |     %d      |         %d         |\n",i,hpd[i],cnn[i][k],hpde[i],noc[i]);
            else if(i>nc)
                printf("|  %d  |       %d       |      -     |     %d      |         -         |\n",i,hpd[i],hpde[i]);
            else{}
            printf("|-----|---------------|------------|------------|-------------------|\n");
            k++;
        }while(cnn[i][k]!=0);
    }
    printf("\n* indicates multiple chapters on that day!\n");
    //FIRST FIT
    lavail=0;
    t=0;
    for(i=1;i<=nd;i++)
    {
        hpde[i]=hpd[i];
        da[i]=0;
        noc[i]=0;
        for(k=0;k<=3;k++)
            cnn[i][k]=0;
    }
     k=0;
    for(i=1;i<=nc;i++)
        for(j=1;j<=nd;j++)
        {
            temp=hpde[j]-mpce[i];
            if(temp>=0)
            {
                hpde[j]=hpde[j]-mpce[i];
                noc[j]++;
                if(cnn[j][k]!=0)
                {
                    k++;
                }
                cnn[j][k]=cn[i];
                break;
            }
        }
    printf("\nAccording To Modified First Fit...");
    printf("\n\n+-----|---------------|------------|------------|-------------------+\n");
    printf("| Day | Hours Alloted | Chapter No | Hours free | Chapters Assigned |\n");
    printf("|-----|---------------|------------|------------|-------------------|\n");
    for(i=1;i<=max(nd,nc);i++)
    {
        k=0;
        if(cnn[i][k+1]!=0)
            t=i;
        do
        {
            if(i==t)
                printf("|  %d* |       %d       |      %d     |     %d      |         %d         |\n",i,hpd[i],cnn[i][k],hpde[i],noc[i]);
            else if(cnn[i][k]==0)
                printf("|  %d  |       %d       |      -     |     %d      |         -         |\n",i,hpd[i],cnn[i][k],hpde[i],noc[i]);
            else if(i<=nc && i<=nd)
                printf("|  %d  |       %d       |      %d     |     %d      |         %d         |\n",i,hpd[i],cnn[i][k],hpde[i],noc[i]);
            else if(i>nc)
                printf("|  %d  |       %d       |      -     |     %d      |         -         |\n",i,hpd[i],hpde[i]);
            else{}
            printf("|-----|---------------|------------|------------|-------------------|\n");
            k++;
        }while(cnn[i][k]!=0);
    }
    printf("\n* indicates multiple chapters on that day!\n");
}