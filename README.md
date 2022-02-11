## Student Name: Zachary Force

# Assignment 3

Write an MPI program named **intro_mpi.c** that performs the following tasks. Assume that the MPI program is 
going to be run with 4 processes (`-np 4`). 

### Task 1: 

Have process 0 creates a 32-element array of integer named `arrayZero` and randomly initializes each element in 
this array. Using `MPI_Send` and `MPI_Recv`, have process 0 sends the second element in this array to process 2. 
Output the second element of `arrayZero` in process 0 and a variable contained the newly sent data in process 2 
to verify the communication. 

### Task 2: 

Using `MPI_Broadcast`, broadcast the content of the variable of process 2 from **Task 1** to all other processes, 
to be saved in a new variable called `fromTwo`. Output this variable from all four processes to verify the 
communication. 

### Task 3:

Using `MPI_Scatter`, scatter the 32-element array from process 0 into 8-element arrays named `fromArray` at all other 
processes. Output the content of `fromArray` for each process for verification purposes. 

### Task 4:

Using `MPI_Reduce`, identify the maximum entry from the `fromArray` variables (**Task 3**) of all the processes and 
store this value in a variable called `fromArrayMax` in process 3. Output this variable for verification purposes

### Task 5:

Using `MPI_Gather`, gather the `fromArray` arrays into a second array in process 0 named `arrayOne`. For process 0 only, 
output `arrayZero` and `arrayOne` for verification purpose. 


## Submission

- Edit the README.md to add your name to the top of the file
- Submit the URL of your assignment git repository, as provided through GitHub Classroom to D2L. 
- The assignment git repository should have one file: **intro_mpi.c**. 
- The git repository should also contain a screenshot showing the execution of `intro_mpi`.
- The last commit to your git repository must be made prior to the deadline of the assignment. Any subsequent commit will not be considered. 
