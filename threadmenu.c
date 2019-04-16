#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h>
#include "PSO.c"
#include "round2.c"
#include<time.h>
int main()
{
    struct arrays *Allen = (struct arrays *)malloc(sizeof(struct arrays));
    Allen->load=(int*)malloc(sizeof(int)*numofparticles);
    Allen->exectime=(int*)malloc(sizeof(int)*numofparticles);
    Allen->execution=(int*)malloc(sizeof(int)*numofparticles);
    Allen->bestmax=(int*)malloc(sizeof(int)*nop);
    Allen->maxload=(int*)malloc(sizeof(int)*nop);
    Allen->fitness=(float*)malloc(sizeof(float)*numofparticles);
    Allen->bestfit=(float*)malloc(sizeof(float)*numofparticles);
    Allen->maxlod=(int*)malloc(sizeof(int)*nop);
    Allen->timequantum=(int*)malloc(sizeof(int)*nop);	
	create(&q);
    int i=0,counter1=0;
	clock_t start,end;//For calculating throughput
         pthread_t thread[4][10]; 
    int index[10];
    int gbestindex[10];
	int counter2=0;
int index1[10];
int gbestindex1[10];
	pthread_t thread1[4][20];
	 srand(time(0));//FOR RANDOM FUNCTION
double cpu_time_used,throughput;
	int menu;
	printf("Enter no. of processes ");
	scanf("%d",&numofparticles);
	printf("\n");
	printf("Program you want to run\n");
	printf("1.Press 1 for PSO\n");
	printf("2.Press 2 for Round Robin\n");
	scanf("%d",&menu);
	switch(menu)
	{
	case 1:
  
	start = clock();
        maxloadprocessor(Allen);
        bestmaxloadprocessor(Allen);
        loaddelayfunc(Allen);
        fitnessvalue(Allen);
	
   
    while(counter<numofparticles)
    {
       
        printf("Value of processor is %d\t",c);
        switch(c)
        {
            case 0:
                index[counter]=0;
                gbestindex[counter]=gbest;
                pthread_create(&thread[0][gbest],NULL,pso,(void*)Allen);
                sleep(2);
                break;
                
            case 1:
                index[counter]=1;
                gbestindex[counter]=gbest;
                pthread_create(&thread[1][gbest],NULL,pso,(void*)Allen);
                sleep(2);
                break;
            case 2:
                index[counter]=2;
                gbestindex[counter]=gbest;
                pthread_create(&thread[2][gbest],NULL,pso,(void*)Allen);
                sleep(2);
                break;
            case 3:
                index[counter]=3;
                gbestindex[counter]=gbest;
                pthread_create(&thread[3][gbest],NULL,pso,(void*)Allen);
                sleep(2);
                break;
        }
        counter++;
    }
    
  
   
    for(i=0;i<numofparticles;i++)
    {
        pthread_join(thread[index[i]][gbestindex[i]],NULL);
    }
    end=clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   
throughput=(numofparticles/cpu_time_used);
		
    printf("Throughput of PSO is %f\n",throughput);
	for(i=0;i<numofparticles;i++)
    {
        printf("Load and Execution of process %d is %d and %d ",i,((struct arrays *)Allen)->load[i],((struct arrays *)Allen)->exectime[i]);
        printf("   Fitness is %f \n",((struct arrays *)Allen)->fitness[i]);
    }
	for(i=0;i<nop;i++)
	{
	printf("Max load of processor %d is %d \n",i,((struct arrays *)Allen)->maxload[i]);
	}
        sortarray();
	for(i=0;i<numofparticles;i++)
    {
        printf("The process %d goes on processor %d\n",pinfo[i][0],pinfo[i][1]);
    }
	break;
	case 2:
start = clock();
maxloadprocessor(Allen);
loaddelayfunc(Allen);
timeq(Allen);
while(x>=0)
{
switch(g)
{
case 0:
index1[counter2]=0;
gbestindex1[counter2]=t;
pthread_create(&thread1[0][t],NULL,round1,(void*)Allen);
sleep(2);
break;
case 1:
index1[counter2]=1;
gbestindex1[counter2]=t;
pthread_create(&thread1[1][t],NULL,round1,(void*)Allen);
sleep(2);
break;
case 2:
index1[counter2]=2;
gbestindex1[counter2]=t;
pthread_create(&thread1[2][t],NULL,round1,(void*)Allen);
sleep(2);
break;
case 3:
index1[counter2]=3;
gbestindex1[counter2]=t;
pthread_create(&thread1[3][t],NULL,round1,(void*)Allen);
sleep(2);
break;
}
counter2++;

}
 for(i=0;i<counter2;i++)
    {
        pthread_join(thread[index1[counter2]][gbestindex1[counter2]],NULL);
    }

 end=clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   
throughput=(numofparticles/cpu_time_used);
		
    printf("Throughput of RoundRobin is %f\n",throughput);

printf("AFTER EXECUTION\n");
for(i=0;i<numofparticles;i++)
    {
        printf("Load and Execution of process %d is %d and %d \n",i,((struct arrays *)Allen)->load[i],((struct arrays *)Allen)->exectime[i]);
       
    }
	for(i=0;i<nop;i++)
	{
	printf("Max load of processor %d is %d \n",i,((struct arrays *)Allen)->maxlod[i]);
	}

break;
 }
}
