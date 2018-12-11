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
  int status;
  int i2;
  int sig;
  pid_t pid;
  float sc;
  float fc;
  float s, f;

   int success, failure;
  char *arg[] = {"./hand", argv[1], argv[2], argv[3], NULL};
  while ((opt = getopt(argc, argv, "-:p:v:")) != -1) 
  {
     switch (opt) 
     { 
      case 'p':
      var1 = optarg;
     // percentage = atoi(var1);
      break;
      case 'v':
      var1 = optarg;
      int i3 = atoi(var1);
      //printf("Case P Value: %s\n", &argv[1]);
      //printf("Case Num of trials Value: %d\n", i3);
      for(i=0;i<i3;i++)
      {
        if( fork() == 0)
        {
          //printf("Before calling hand");
          execv("./hand", arg);
          //exit(0);
        }
        else 
        {
        }
        if(WIFEXITED(status))
          {
            wait(&status);
            int es = WEXITSTATUS(status);
            if(es == 1)
            {
              printf("PID %d returned success \n",getpid()); 
              sc++;
            }
            else
            {
             printf("PID %d returned failure \n",getpid());
             fc++;
            }
          }
        }
         s = (sc/i3) * 100;
         f = 100 - s;
        success = (int)(s+.5);
        failure = (int) (f + .5);
        printf("Created %d processes.\n", i3);
        printf("Success - %d%\n", success);
        printf("Failure - %d%\n", failure);
        
       break;
     
      case 1:
      
      var1 = optarg;
      i3 = atoi(var1);
     
            
          
        s = (sc/i3) * 100;
         f = 100 - s;
        success = (int)(s+.5);
        failure = (int) (f + .5);
        printf("Created %d processes.\n", i3);
        printf("Success - %d%\n", success);
        printf("Failure - %d%\n", failure);
      break;

      default:
      fprintf(stderr, "Usage:  ./dealer [-p num num ] or ./dealer [-p num -v num]\n");
      return EXIT_FAILURE;  
     }
  }
  
  
  return 0;
}
