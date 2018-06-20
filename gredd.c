#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define tape_size 300
#define MAX 20

typedef struct files
{
	char name[MAX];
	int size;
}files;

void merge(struct files f[],int min,int mid,int max)
{
	//int tmp[30];
	struct files tmp[MAX];
  	int i,j,k,m;
        //struct files A[n1];
  	j=min;
  	m=mid+1;
  	for(i=min; j<=mid && m<=max ; i++)
  	{
     		if(f[j].size<=f[m].size)
     		{
         		tmp[i].size=f[j].size;
			strcpy(tmp[i].name,f[j].name);
         		j++;
     		}
     		else
     		{
         		tmp[i].size=f[m].size;
			   strcpy(tmp[i].name,f[m].name);
         		m++;
     		}
  	}
  	if(j>mid)
  	{
     		for(k=m; k<=max; k++)
     		{
         		tmp[i].size=f[k].size;
                         strcpy(tmp[i].name,f[k].name);
         		i++;
     		}
  	}
  	else
  	{
     		for(k=j; k<=mid; k++)
     		{
        		tmp[i].size=f[k].size;
			strcpy(tmp[i].name,f[k].name);
        		i++;
     		}
  	}
  	for(k=min; k<=max; k++)
  	{
     	f[k].size=tmp[k].size;
        strcpy(f[k].name,tmp[k].name);
  	}
}

void part(struct files f[],int min,int max)
{
	int mid;
 	if(min<max)
 	{
   		mid=(min+max)/2;
   		part(f,min,mid);
   		part(f,mid+1,max);
   		merge(f,min,mid,max);
 	}
}

int main()
{
	int n,i=0,m,j=0,k=0;

	files f[MAX];

	printf("\nEnter the number of files:");
	scanf("%d", &n);

	printf("\nEnter the name and size of each file:");

	for(i=0; i<n; i++)
	{
		printf("\nFile %d:\n", i+1);
		scanf("%s%d", f[i].name, &f[i].size);
	}

	int flag=0;
	for(i=0;i<n-1;i++)
	{
		if(f[i].size > f[i+1].size)
		{
			flag=1;
			break;
		}
	}
	printf("\nvalue of i:%d",i);
	if(flag==1)
	{
               //printf("\nvalue of i and n:%d%d",i,n);
		part(f,i,n-1);
	}

	printf("\nFiles sorted according to size and name:\n");
	for(i=0; i<n; i++)
		printf("%d %s\t",f[i].size,f[i].name);

	printf("\nEnter the number of tapes\n");
	scanf("%d",&m);

	struct files tapes[m][10];

	int sum[m];
	for(i=0; i<m; i++)
	{
		for(j=0; j<10; j++)
		{
			tapes[i][j].size=-1;
		}
		sum[i]=0;
	}

	i=0,j=0;
	while(i<=m)
	{
		if(k==n)
			break;
		if(k<n && i<m)
		{
			sum[i]=sum[i]+f[k].size;
			//printf("%d\n",sum[i] );
			if(sum[i]<=tape_size)
			{
				tapes[i][j].size=f[k].size;
				strcpy(tapes[i][j].name,f[k].name);
				k++;
			}
			else
			{
				if(i>0)
				{
					i=0;
					j++;//j becomes 1 increament by 1
					sum[i]=sum[i]+f[k].size;
					if(sum[i]<=tape_size)
					{
						tapes[i][j].size=f[k].size;
						strcpy(tapes[i][j].name,f[k].name);
						k++;
					}
					else
						break;
				}
			}
		}
		if(i==m)
		{
			if(j<9)
			{
				j++;
				i=0;
				continue;
			}
			else
				break;
		}
		i++;
	}

	for(i=0; i<m; i++)
	{
		printf("\nTape %d:\t",i+1);
		for(j=0; j<10; j++)
		{
			if(tapes[i][j].size!=-1)
			{
				printf("%s %d\t",tapes[i][j].name,tapes[i][j].size);
			}
			else
				continue;
		}
		printf("\n");
	}
	return 0;
}
