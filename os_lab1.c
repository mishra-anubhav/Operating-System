#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{           int n1, n2,S,R,A,B; 
	printf("\nEnter two no: ");
              scanf("%d %d", &A, &B);
                n1 = fork(); 
	n2 = fork(); 

	// if n1 is greater than zero and n2 is greater than zero then 1st process executes 
	if (n1 > 0 && n2 > 0) { 
    S=A+B;
    printf("\nI am child number 1st with child Id %d  and with parent Id %d, the sum is %d \n", getpid(),getppid(), S);
    //pid1 code...
    exit(EXIT_SUCCESS);
	} 
              // else if n1 is zero  and n2 is greater than zero  then 2nd child process executes 
	else if (n1 == 0 && n2 > 0) { 
                 S=A-B;
    printf("\nI am child number 2nd with child Id %d  and with parent Id %d, the diffrence is %d \n",getpid(),getppid(), S);
    //pid1 code...
    exit(EXIT_SUCCESS);
	} 
// else if n1 is greater than zero  and n2 is zero then 3rd child process executes 
	
else if (n1 > 0 && n2 == 0) { 
     S=A*B;
    printf("\nI am child number 3rd with child Id %d  and with parent Id %d, the multiply is %d \n", getpid(),getppid(), S);
    //pid1 code...
    exit(EXIT_SUCCESS);
	} 
             // else if n1 is zero  and n2 is zero then 4th child process executes 
	else if (n1 == 0 && n2 == 0) { 

		S=A/B;
		R=A%B;
    printf("\nI am child number 4th with child Id %d  and with parent Id %d, the quotient is %d \n and remainder %d", getpid(),getppid(), S,R); 
exit(EXIT_SUCCESS);
	} 
       return 0; 
}
