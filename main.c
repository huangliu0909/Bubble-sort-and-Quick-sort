#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX 100
#define MAX1 1000000

int m0[MAX];
int m[MAX1];
int p;

void Sort(int n,int x[])
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(x[j]>x[j+1])
            {
                t=x[j];
                x[j]=x[j+1];
                x[j+1]=t;
            }
        }
    }
}

void Sort1(int n,int x[])
{
    int i,j,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(x[j]<x[j+1])
            {
                t=x[j];
                x[j]=x[j+1];
                x[j+1]=t;
            }
        }
    }
}

void quicksort(int array[], int begin, int end)
{
    int i,j,t;
    if(begin < end)
    {
        i = begin + 1;
        j = end;
        while(i < j)
        {
            if(array[i] > array[begin])  // ����Ƚϵ�����Ԫ�ش��ڻ�׼�����򽻻�λ�á�
            {
                t=array[i];
                array[i]=array[j];
                array[j]=t;
                j--;
            }
            else
            {
                i++;  // �����������һλ���������׼���Ƚϡ�
            }
        }
        if(array[i] >= array[begin])  // �������Ҫȡ�ȡ�>=������������Ԫ������ͬ��ֵʱ������ִ���
        {
            i--;
        }
        t=array[i];
        array[i]=array[begin];
        array[begin]=t;
        quicksort(array, begin, i);
        quicksort(array, j, end);
    }
}

int Search1 (int x[],int n,int k )
{
    int low,high,mid;
   low = 1;
   high =n;     // �������ֵ
   while (low <= high)
    {
      mid = (low + high) / 2;
      if   ( k == x[mid]  )
              return  mid;       // �ҵ�����Ԫ��
      else  if ( k < x[mid] )
              high = mid - 1;   // ������ǰ��������в���
      else  low  = mid + 1;  // �����ں��������в���
    }
   return 0;
}

int Search2 (int x[],int low, int high,  int k)
{
    int mid;
    if(low>high)
        return -1;
    else{
        mid = (low+high)/ 2;
        if(x[mid]==k)
            return mid;
        if(k>x[mid])
            return Search2(x,mid+1,high,k);
        else
            return Search2(x,low,mid-1,k);
    }
}


int main()
{
    printf("�ļ�����ʱ��1.�������    2.��������   3.��������\n");
    int oopp;
    scanf("%d",&oopp);
    FILE *fp;
    int i=0,op;
    switch(oopp)
    {
    case 1:
        {
            fp=fopen("insert0.txt","r");
            if(fp==NULL)
            {
                printf("Reading failed!\n");
                exit(0);
            }
            else
            {
                printf("the insert file is:");
                do
                {
                    fscanf(fp,"%d",&m0[i]);
                    printf("%d ",m0[i]);
                    i++;
                }while(!feof(fp));
                printf("\n");
                p=i;
            }
            //printf("lll");
            printf("1.ð������\n2.��������\n");
            scanf("%d",&op);
            switch(op)
            {
            case 1:
                {
                    int a=clock();
                    Sort(p,m0);

                    for(i=0;i<p;i++)
                    {
                        printf("%d ",m0[i]);
                    }
                    int b=clock();
                    printf("\n������ʱ��%d ms",b-a);
                    break;

                }
            case 2:
                {
                    int a=clock();
                    quicksort(m0, 0, p-1);
                    int b=clock();
                    for(i=0;i<p;i++)
                    {
                        printf("%d ",m0[i]);
                    }
                    printf("\n������ʱ��%d ms",b-a);
                    break;
                }
            }
            int num1,u,num2;
            printf("\ninput a num to search:\n");
            scanf("%d",&u);
            num1=Search1(m0,p,u);
            if(num1>=0)
                printf("�ݹ�%d---%d",u,num1);
            else printf("do not exist");
            printf("\n");
            num2=Search2(m0,0,p-1,u);
            if(num2>=0)
                printf("�ǵݹ�%d---%d",u,num2);
            else printf("do not exist");
            break;
        }
    case 2:
        {
            fp=fopen("insert1.txt","r");
            if(fp==NULL)
            {
                printf("Reading failed!\n");
                exit(0);
            }
            else
            {
                printf("the insert file is:");
                do
                {
                    fscanf(fp,"%d",&m0[i]);
                    printf("%d ",m0[i]);
                    i++;
                }while(!feof(fp));
                printf("\n");
                p=i;
            }
            //printf("lll");
            printf("1.ð������\n2.��������\n");
            scanf("%d",&op);
            switch(op)
            {
            case 1:
                {
                    int a=clock();
                    Sort(p,m0);

                    for(i=0;i<p;i++)
                    {
                        printf("%d ",m0[i]);
                    }
                    int b=clock();
                    printf("\n������ʱ��%d ms",b-a);
                    break;

                }
            case 2:
                {
                    int a=clock();
                    quicksort(m0, 0, p-1);
                    int b=clock();
                    for(i=0;i<p;i++)
                    {
                        printf("%d ",m0[i]);
                    }
                    printf("\n������ʱ��%d ms",b-a);
                    break;
                }
            }
            int num1,u,num2;
            printf("\ninput a num to search:\n");
            scanf("%d",&u);
            num1=Search1(m0,p,u);
            if(num1>=0)
                printf("�ݹ�%d---%d",u,num1);
            else printf("do not exist");
            printf("\n");
            num2=Search2(m0,0,p-1,u);
            if(num2>=0)
                printf("�ǵݹ�%d---%d",u,num2);
            else printf("do not exist");
            break;
        }
    case 3:
        {
            fp=fopen("insert2.txt","r");
            if(fp==NULL)
            {
                printf("Reading failed!\n");
                exit(0);
            }
            else
            {
                printf("the insert file is:");
                do
                {
                    fscanf(fp,"%d",&m0[i]);
                    printf("%d ",m0[i]);
                    i++;
                }while(!feof(fp));
                printf("\n");
                p=i;
            }
            //printf("lll");
            printf("1.ð������\n2.��������\n");
            scanf("%d",&op);
            switch(op)
            {
            case 1:
                {
                    int a=clock();
                    Sort(p,m0);

                    for(i=0;i<p;i++)
                    {
                        printf("%d ",m0[i]);
                    }
                    int b=clock();
                    printf("\n������ʱ��%d ms",b-a);
                    break;

                }
            case 2:
                {
                    int a=clock();
                    quicksort(m0, 0, p-1);
                    int b=clock();
                    for(i=0;i<p;i++)
                    {
                        printf("%d ",m0[i]);
                    }
                    printf("\n������ʱ��%d ms",b-a);
                    break;
                }
            }
            int num1,u,num2;
            printf("\ninput a num to search:\n");
            scanf("%d",&u);
            num1=Search1(m0,p,u);
            if(num1>=0)
                printf("�ݹ�%d---%d",u,num1);
            else printf("do not exist");
            printf("\n");
            num2=Search2(m0,0,p-1,u);
            if(num2>=0)
                printf("�ǵݹ�%d---%d",u,num2);
            else printf("do not exist");
            break;
        }
    }

    printf("\n�������ʱ");
    printf("input num:");
    int pp;
    scanf("%d",&pp);
    for(p=0;p<pp;p++)
    {
        m[p]=rand()%pp;
    }
    double st=clock();
    Sort(pp,m);
    double nd=clock();
    printf("\n���ʱð������%d������Ҫ%lf ms",pp,nd-st);
    for(p=0;p<pp;p++)
    {
        m[p]=rand()%pp;
    }
    double st1=clock();
    quicksort(m,0,pp-1);
    double nd1=clock();
    printf("\n���ʱ��������%d������Ҫ%lf ms",pp,nd1-st1);
    for(p=0;p<pp;p++)
    {
        m[p]=rand()%pp;
    }
    quicksort(m,0,pp-1);
    double st2=clock();
    Sort(pp,m);
    double nd2=clock();
    printf("\n����ʱð������%d������Ҫ%lf ms",pp,nd2-st2);
     for(p=0;p<pp;p++)
    {
        m[p]=rand()%pp;
    }
    quicksort(m,0,pp-1);
    double st3=clock();
    quicksort(m,0,pp-1);
    double nd3=clock();
    printf("\n����ʱ��������%d������Ҫ%lf ms",pp,nd3-st3);
    for(p=0;p<pp;p++)
    {
        m[p]=rand()%pp;
    }
    Sort1(pp,m);
    double st4=clock();
    Sort(pp,m);
    double nd4=clock();
    printf("\n����ʱð������%d������Ҫ%lf ms",pp,nd4-st4);
     for(p=0;p<pp;p++)
    {
        m[p]=rand()%pp;
    }
    Sort1(pp,m);
    double st5=clock();
    quicksort(m,0,pp-1);
    double nd5=clock();
    printf("\n����ʱ��������%d������Ҫ%lf ms",pp,nd5-st5);
    return 0;
}
