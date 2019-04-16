#include<stdio.h>
#include <stdlib.h> 
#include<time.h>
#include<pthread.h> 
//#define MAX 60

/*struct arrays{
int *load;
int *maxlod;
int *exectime;
int *execution;
int *timequantum;
int *maxload;
int front;
int  rear; 
int elements[MAX]; 
};*/

//int nop=4;//no. of processors
//int numberofiterations;
//int numofparticles;//numberofparticles
int count=0;
//static int counter=0;
//int lower=70;
void *create(struct arrays *pq) 
  { 
   pq->front=pq->rear=-1; 
  } 
void *enQueue(struct arrays *pq,int value)
{
    if(pq->rear == MAX-1)
        printf("\nQueue is Full!!");
        else {
        if(pq->front == -1)
            pq->front = 0;
        pq->rear++;
        pq->elements[pq->rear] = value;
       // printf("\nInserted -> %d", value);
         count=0;
         }
}

void *deQueue(struct arrays *pq)
 {
    
       l= pq->elements[pq->front];
       x=pq->front;
      
      
        if(count==2){
        //printf("\nQueue is Empty!!");
	
	//if(count==2)
	//exit(0);
	//goto repeat;
	}
    else{
         if(pq->front == pq->rear)
	{ count=2;}
       // printf("\nDeleted : %d", pq->elements[pq->front]);
        pq->front++;
        if(pq->front > pq->rear)
            pq->front =pq->rear = -1;
        }
if(pq->front>0)
 h= pq->elements[pq->front-1];
}

void *maxloadprocessor(void *Allen)//Max load on each processor
{
	//
        for(int i=0;i<nop;i++)
	{
        ((struct arrays *)Allen)->maxload[i]=rand()%150;
	if(((struct arrays *)Allen)->maxload[i]<lower)
	   {
	     ((struct arrays *)Allen)->maxload[i]+=lower;
	    }
	  ((struct arrays *)Allen)->maxlod[i]=((struct arrays *)Allen)->maxload[i];
           //((struct arrays *)Allen)->timequantum[i]=rand()%9+1;  
	 ((struct arrays *)Allen)->timequantum[i]=rand()%5;	
		if( ((struct arrays *)Allen)->timequantum[i]<1)
		{
		 ((struct arrays *)Allen)->timequantum[i]+=1;
		}
		printf("Max load of processor %d is %d \n",i,((struct arrays *)Allen)->maxload[i]);
                  //
         
	}
//printf("THE MAXLOAD OF PROCESORS \n");

}
void *timeq(void *Allen)
{
printf("THE TIME QUANTUM OF PROCESORS \n");
for(int i=0;i<nop;i++)
{
printf("%d \n",((struct arrays *)Allen)->timequantum[i]);  
}
}
void *loaddelayfunc(void *Allen)
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
	 f=((struct arrays *)Allen)->execution[i];
           //printf("%d \n",((struct arrays *)Allen)->exectime[i]); 
           enQueue(&q,f);
	}
}
//
void *update(void *Allen)
{
int cou=0;
 for(int k=0;k<numofparticles;k++)
   {
     if(((struct arrays *)Allen)->execution[k]>=0)
       {
         if(l==((struct arrays *)Allen)->execution[k])
           { 
              if(t==k)
               cou=0;
              if(t==numofparticles-1)
                  t=0;
              else if(cou==0)
              {
              t=k;
              cou=1;
              }
           }
        }
     }
}
void *round1(void *Allen)
{

 struct arrays *pq;
/*while(pq->front>=0)
  {*/
  update(Allen);
  deQueue(&q);
	int k1=t;
	int k2=g;
	int k3=l;
	int k4=counter;
  time_t start,end;
  start=time(NULL);
  end=time(NULL);
  if(k4<numofparticles)
    {
   //update(Allen);
  if(((struct arrays *)Allen)->exectime[t]==((struct arrays *)Allen)->execution[t])
   {
     //update(Allen);
    printf ("the start time of process %d is ",r);
    printf("%s", ctime(&start)); 
    k4++;
	counter=k4;
    r++;
    //printf(
   }
}  

  ((struct arrays *)Allen)->maxload[k2]=((struct arrays *)Allen)->maxload[k2]-((struct arrays *)Allen)->load[k1];
   while(end-start<=((struct arrays *)Allen)->timequantum[k2])
     {
       end=time(NULL);
    }
    
    ((struct arrays *)Allen)->maxload[k2]=((struct arrays *)Allen)->maxload[k2]+((struct arrays *)Allen)->load[k1];
 //update(Allen);
   ((struct arrays *)Allen)->execution[k1]= k3-((struct arrays *)Allen)->timequantum[k2];
    if((k3-((struct arrays *)Allen)->timequantum[k2])>0)
       {
        
        enQueue(&q,((struct arrays *)Allen)->execution[t]);
       }
     else
     {
    if(j<numofparticles)
      {
        j++;
          

        printf(" %d process complted \n",j);
  
      }}
k4++;
if(k4==nop)
{
k4=0;
}
k4=g;

 //t++; 

    
}
//end1:
//}
/*int main()
{
  int numofparti1=numofparticles*numofparticles;

  clock_t startend;
  startend=clock();
  struct arrays *Allen = (struct arrays *)malloc(sizeof(struct arrays));
Allen->load=(int*)malloc(sizeof(int)*numofparticles);
Allen->exectime=(int*)malloc(sizeof(int)*numofparticles);
Allen->execution=(int*)malloc(sizeof(int)*numofparticles);
//Allen->bestmax=(int*)malloc(sizeof(int)*nop);
Allen->maxload=(int*)malloc(sizeof(int)*nop);
  Allen->timequantum=(int*)malloc(sizeof(int)*nop);
   srand(time(0));
   create(&q);
     maxloadprocessor(Allen);
    loaddelayfunc(Allen);
     round1(Allen);
	//repeat:
}*/
