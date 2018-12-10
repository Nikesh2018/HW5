#include <stdio.h>  /* printf */
#include <getopt.h> /* getopt */
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
int main(int argc, char *argv[])
{

  int opt;
  char *var1;
  int i;
  int i2;
  int sig;
  char *arg[] = {"./hand", argv[2], argv[3], NULL};
  while ((opt = getopt(argc, argv, "-:p:v:")) != -1) 
  {
     switch (opt) 
     { 
      case 'p':
        //var1 = optarg;
        //i2 = atoi(var1);
        //int i1 = atoi(var1);
        //printf("Option p has arg: %s\n", optarg);
        if(fork()==0)
        {
          execv("./hand", arg);
          exit(0);
        }
        //for(i=0;i<i2;i++) // loop will run n times (n=5) 
        wait(NULL); 
        break;
      case 'v':
        var1= optarg;
        i2 = atoi(var1);
        for(i=0;i<i2;i++) // loop will run n times (n=5) 
        { 
          if(fork() == 0) 
          { 
              printf("PID %d returned \n",getpid()); 
              exit(1); 
          } 
        } 
        for(i=0;i<i2;i++) // loop will run n times (n=5) 
        wait(NULL); 
        //execv("./hand", arg);
        break;
      case 1:
        var1= optarg;
         printf("NonOption p has arg: %s\n", optarg);
        i2 = atoi(var1);
        for(i=0;i<i2;i++) // loop will run n times (n=5) 
        { 
          if(fork() == 0) 
          { 
              //printf("PID %d returned \n",getpid()); 
              
              exit(2); 
          } 
        } 
        for(i=0;i<i2;i++) // loop will run n times (n=5) 
        wait(NULL); 
        break;
        //printf("Created %s\n processes.", var1);

        
     }
  }
  
  
  return 0;
}
