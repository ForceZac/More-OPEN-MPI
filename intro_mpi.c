#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
  int rank;
  int size;
  int arrayZero[32];
  int element=0;
  MPI_Status status;
  int fromTwo=0;
  int fromArray[8];
  int recvbuf[8];
  int fromArrayMax=0;
  int arrayOne[32];
//Initialize Message passing Interface
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
//Create size 32 array in process 0
  if(rank==0);
  {
    srand(0);
    for(int i=0;i<32;i++) {
	arrayZero[i]= rand() % 100;
	}
   }

  /*Task 1*/
//Passing index[1] in Process 0 to process 2
if(rank==0) {
  MPI_Send(&arrayZero[1], 1, MPI_INT,2,0,MPI_COMM_WORLD);//send from arrayZero 1 MPI_Int to process 2. the 0 and comm world are default
  printf("Sent %d to process 2\n",arrayZero[1]);
 }
//Recieving index[1] from process 0
if(rank==2) {
  MPI_Recv(&element,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
  printf("Recieved %d from Process 0\n",element);
//End of Task 1


/*Task 2*/
  fromTwo = element;
}
   printf("Before Bcast process %d has fromTwo value: %d\n",rank,fromTwo);
   MPI_Bcast(&fromTwo,1,MPI_INT,2,MPI_COMM_WORLD);
   printf("After Bcast Process %d has fromTwo value: %d\n",rank,fromTwo);
//End of Task2

/*Task 3*/
  printf("\n");
  MPI_Scatter(&arrayZero,8,MPI_INT,&fromArray,8,MPI_INT,0,MPI_COMM_WORLD);
  for(int i=0;i<8;i++)
     {
	printf("Process %d has element %d at index %d in it's fromArray\n",rank,fromArray[i],i);
     }
//End of Task 3

/*Task 4*/
    MPI_Reduce(&fromArray,&recvbuf,8,MPI_INT,MPI_MAX,3,MPI_COMM_WORLD);
   for(int i=0;i<8;i++)
     {
	if(recvbuf[i]>fromArrayMax)
	{
	   fromArrayMax=recvbuf[i];
	}
      }
   if(rank==3)
   {
     printf("The max element is: %d\n",fromArrayMax);
    }

//end of task 4

/*Task 5*/
  MPI_Gather(&fromArray,8,MPI_INT,&arrayOne,8,MPI_INT,0,MPI_COMM_WORLD);
  if(rank==0)
   {
     printf("\narrayZero:");
     for(int i=0;i<32;i++)
	{
	  printf("%d ",arrayZero[i]);
	}
      printf("\narrayOne:");
      for(int i=0;i<32;i++)
	{
	  printf("%d ",arrayOne[i]);
	}
    }
//end of task 5
   //Closing Message Passing interface
   MPI_Finalize();
   return 0;
}
