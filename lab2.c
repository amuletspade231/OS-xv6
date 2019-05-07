#include "types.h"
#include "user.h"
	
	int PScheduler(void);
	int checkAging(void);

int main(int argc, char *argv[])
{

  printf(1, "\n This program tests the correctness of your lab#2\n");
  
	PScheduler();
	checkAging();
	return 0;
 }
  
    
     int PScheduler(void){
		 
    // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority and 31 is the lowest priority.  

  int pid;
  int i,j,k;
  
    printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) systema call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31\n");
    printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");
    setpriority(0, 0);
    for (i = 0; i < 3; i++) {
	pid = fork();
	if (pid > 0 ) {
		continue;}
	else if ( pid == 0) {
		setpriority(30-10*i, 0);	
		for (j=0;j<50000;j++) {
			for(k=0;k<1000;k++) {
				asm("nop"); }}
		printf(1, "\n child# %d with priority %d has finished! \n",getpid(),30-10*i);		
		exit();
        }
        else {
			printf(2," \n Error: fork()\n");
			
        }
	}

	if(pid > 0) {
		for (i = 0; i < 3; i++) {
			waitS(0);

		}
                     printf(1,"\n if processes with highest priority finished first then its correct \n");
}
	exit();		
	return 0;}
	
int checkAging(void){
  uint priority;
  int j,k;

  printf(1,"********** \n");
  
  printf(1, "Test for priority aging. \n");
  printf(1, "Default priority is 10. \n");

  for (j = 0; j < 50000; j++)
    for (k = 0; k < 10000; k++ )
      asm("nop");

  setpriority(0, &priority);

  printf(1, "Priority was %d \n", priority);

  printf(1,"********** \n");
  
  printf(1, "Test to see if waitpid is raising priority properly.\n");

  setpriority(15, 0); // Use your own setpriority interface
  printf(1, "Set parent priority to 15 \n");

  int pid = fork();

  // child
  if(pid == 0) {
    setpriority(0, 0);
    for (j = 0; j < 50000; j++)
      setpriority(0, 0);
      for (k = 0; k < 10000; k++ )
        setpriority(0, 0);
        asm("nop");
    exit(0);
  }

  //parent
  else {
    waitS(0);
  }

  setpriority(0, &priority);

  printf(1, "The priority was %d \n", priority);

  return 0;
}

