#include<stdio.h>
#include <stdlib.h> 
#include<time.h>
#define MAX 100
//#include "thread11.c"
//int Dimensions=3;
struct arrays{
int *load;
int *maxlod;
int *exectime;
int *execution;
int *bestmax;
int *timequantum;
float *bestfit;
float *fitness;
int *maxload;
int front;
int  rear; 
int elements[MAX]; 
};
int h=0;
int w1,w2,w3=0;
struct arrays *pq, q;
int w,t,g,z=0;
int l=0,x=0,m=0,r=0;
int f;
int s[4],s1[4],st[4];
int b=0,j=0;
static int counter=0;
int nop=4;//no. of processors
int numberofiterations;
int numofparticles;//numberofparticles
int pbest,i;
clock_t start[100], end[100];
//int time_t;
int d[100];
int c,max,j,imax;
int pinfo[100][2];
//int temp[]={0,0,0,0};
float c1=0.5,c2=0.5,compare=-1;
int i=0,gbest;

int swap,swap1;
int lower=70;
//cpu_time_used;     
//int load[numofparticles];
//int delay[numofparicles];
//int maxload[nop];
//int xbest[numofparticles];
//int bestmax[nop];//Best processor
void sortarray()
{
for(i=0;i<numofparticles;i++)
{
	for(j=i;j<numofparticles;j++)
	{
 		if(pinfo[i][0]>pinfo[j][0])
		{
		swap=pinfo[i][0];
		pinfo[i][0]=pinfo[j][0];
		pinfo[j][0]=swap;
		swap1=pinfo[i][1];
		pinfo[i][1]=pinfo[j][1];
		pinfo[j][1]=swap1;
		}
	}
}
}
			 

void *fitnessvalue(void *Allen)//We calculate everytime to compare with gbest
{
for(i=0;i<numofparticles;i++)
	{
	//printf("\nexectime %d\n",((struct arrays *)Allen)->exectime[i]);
	//printf("\nloadtime %d\n",((struct arrays *)Allen)->load[i]);
	//printf("\nc1 %f\n",c1);
	//printf("\nc2 %f\n",c2);
	((struct arrays *)Allen)->fitness[i]=1-(c1*(float)((struct arrays *)Allen)->exectime[i]+c2*(float)((struct arrays *)Allen)->load[i]);
	((struct arrays *)Allen)->bestfit[i]=((struct arrays *)Allen)->fitness[i];
	//printf("\nfitness %f\n",((struct arrays *)Allen)->fitness[i]);
	}
}


/*int comparator (const void * a, const void * b)
	{
		return ( *(int*)a - *(int*)b );
	}
void bestfitprocess(int bestfit[])
{

              
		qsort(bestfit, numofparticles, sizeof(int), comparator );

}*/
void *bestfitprocess(void *Allen)
{

compare=((struct arrays *)Allen)->bestfit[0];
int j;
	for(j=0;j<numofparticles;j++)
	{
		if(compare<=((struct arrays *)Allen)->bestfit[j])
		{
		gbest=j;	
		compare=((struct arrays *)Allen)->bestfit[j];
		}
	}
	//for(j=0;j<numofparticles;j++)
	//{
	 //  printf("bestfit[%d]=%f \t",j,((struct arrays *)Allen)->bestfit[j]);
	//}
}

/*void *maxloadprocessor(void *Allen)//Max load on each processor
{
	for(int i=0;i<nop;i++)
	{
	((struct arrays *)Allen)->maxload[i]=rand()%150;	
		if(((struct arrays *)Allen)->maxload[i]<lower)
		{
		((struct arrays *)Allen)->maxload[i]+=lower;
		}
	
         printf("Max load of processor %d is %d \n",i,((struct arrays *)Allen)->maxload[i]);
	}
	
}*/
void *bestmaxloadprocessor(void *Allen)
{

max=((struct arrays *)Allen)->maxload[0];
int j;
	for(j=0;j<nop;j++)
	{
		if(max<=((struct arrays *)Allen)->maxload[j])
		{
		c=j;	
		max=((struct arrays *)Allen)->maxload[j];
		}
	}
printf("\n max is %d\n",max);
}


/*void *loaddelayfunc(void *Allen)
{
	for(i=0;i<numofparticles;i++)
	{
	((struct arrays *)Allen)->load[i]=rand()%40;
	if(((struct arrays *)Allen)->load[i]<15)
	{
	((struct arrays *)Allen)->load[i]+=15;
	}
        //minload[i]=load[i];
	((struct arrays *)Allen)->exectime[i]=rand()%10;//Execute time
	if(((struct arrays *)Allen)->exectime[i]<5)
	{
	((struct arrays *)Allen)->exectime[i]+=5;
	}
        ((struct arrays *)Allen)->execution[i]=((struct arrays *)Allen)->exectime[i];
	}
}*/

/*void minloadtask()
{
qsort(minload, nop, sizeof(int), comparator );
}*/
/*void gbestcalc()
{
if(gbestbestmax[nop-1])
{
*/
/*void *loadprocessor(void *Allen)
{
for(i=0;i<=imax;i++)
{	
	if(((double)(start[i]-clock())/CLOCKS_PER_SEC)-clock()!=0)
	{
	temp[i]++;
	printf("true");
	((struct arrays *)Allen)->execution[i]--;
	}
	
	if(temp[i]==((struct arrays *)Allen)->exectime[i])
	{
	end[i]=clock();
	j=pinfo[i][1];
	printf("%d maxloadfuncbeforeexec \t",((struct arrays *)Allen)->maxload[j]);
	((struct arrays *)Allen)->maxload[j]=((struct arrays *)Allen)->maxload[j]+((struct arrays *)Allen)->load[i];
	printf("%d maxloadfuncaftereexec \t",((struct arrays *)Allen)->maxload[j]);	
	}

	
}

}*/
void *pso(void *Allen)
{
	

         	
        bestfitprocess(Allen);
	int y2=gbest;
	int y1=c;//INDEX OF MAXLOAD PROCESSOR
	printf("gbest = %d \t",y2);
	printf("load[gbest]=%d \n",((struct arrays *)Allen)->load[y2]);
	((struct arrays *)Allen)->bestfit[y2]=-100;
	while(((struct arrays *)Allen)->maxload[y1]<((struct arrays *)Allen)->load[y2]);
        ((struct arrays *)Allen)->maxload[y1]=((struct arrays *)Allen)->maxload[y1]-((struct arrays *)Allen)->load[y2];
	time_t start,end;
	start=time(NULL);
        //start[i] = clock();
	pinfo[z][0]=y2;//process and processor info
	pinfo[z][1]=y1;
	int k1=z;
	z++;
	
	//int k2=gbest;
	//int k3=c;
	
	bestmaxloadprocessor(Allen);
        while(end-start<((struct arrays *)Allen)->execution[y2])
	{
	end=time(NULL);
	}
	//sleep(((struct arrays *)Allen)->execution[y2]);
	//int y=pinfo[k1][0];
        //int y1=pinfo[k1][1];
	//printf("load[gbest]=%d \n",((struct arrays *)Allen)->load[y]);
	((struct arrays *)Allen)->maxload[y1]=((struct arrays *)Allen)->maxload[y1]+((struct arrays *)Allen)->load[y2];
	//printf("Value of k is %d",k1);
	//printf("Value");
	//bestfitprocess(Allen);
	
        //printf("\n fit load %d \n",((struct arrays *)Allen)->load[gbest]);
        //printf("\n Compare %f \n",compare);
	//imax=i;
	//loadprocessor(Allen);
        //j=pinfo[i][1];
	//printf("%d maxloadfuncbeforeexec \t",((struct arrays *)Allen)->maxload[j]);
	//end[i]= clock();
        //time_t[i]=(int)start[i]-end[i];
		//if(exec_t[i]==time_t)
		/*{
	j=pinfo[i][1];
	maxload[j]=maxload[j]+load[i];
		}*/
	/*for(i=0;i<numofparticles;i++)
	{
	while(((struct arrays *)Allen)->execution[i]!=0)
	loadprocessor(Allen);
	}*/
//for(i=0;i<nop;i++)
//	printf("%d maxload \t",maxload[i]);
//printf("\n");
//for(i=0;i<nop;i++)
//	printf("%d load \t",load[i]);
//printf("\n");
/*for(i=0;i<nop;i++)
{
printf("%d exectime\t",((struct arrays *)Allen)->exectime[i]);
printf("%d temp \t ",temp[i]);
}*/

}    

//while (exec_t!=0)
		
		 
	 		
	
/*int main()
{
clock_t startend;
startend=clock();
int *bestmax=(int*)malloc(sizeof(int)*nop);
int *maxload=(int*)malloc(sizeof(int)*nop);
int *load=(int*)malloc(sizeof(int)*numofparticles);
int *exectime=(int*)malloc(sizeof(int)*numofparticles);
int *execution=(int*)malloc(sizeof(int)*numofparticles);
int *fitness=(int*)malloc(sizeof(int)*numofparticles);
int *bestfit=(int*)malloc(sizeof(int)*numofparticles);
srand(time(0));
maxloadprocessor(Allen);
//bestprocessor(maxload,bestmax);
loaddelayfunc(Allen);
fitnessvalue(Allen);
pso(Allen);
clock_t endmain;
endmain=clock();
double time1=(double)(endmain-startend) / CLOCKS_PER_SEC;
printf("%f",time1);
}*/
//To calculate dynamically we use memory copy



