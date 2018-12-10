#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <stdlib.h>
#include <time.h>
int main (int argc, char *argv[])
{
  const gsl_rng_type * T;
  gsl_rng * r;
  gsl_rng_env_setup();
  int i2;
  int numoftrials;
  float count = 0;
  T = gsl_rng_default;
  r = gsl_rng_alloc (T);
  gsl_rng_set(r,time(NULL));
  numoftrials = atoi(argv[2]);
  
  for(i2 = 0; i2 < numoftrials; i2++)
  {
    int u = gsl_rng_get (r);
    int h = abs(u%100);
    int i = atoi(argv[1]);
    
    //printf ("Number of random num = %d\n", h);
  
    if (h <= i)
    {
      //printf("success\n");
      count++;
    }
    else
    {
      //printf("failure\n");
    }
    
  }
  gsl_rng_free (r);
  float s = (count/numoftrials) * 100;
  float f = 100 - s;
  int success = (int)(s+.5);
  int failure = (int) (f + .5);
  
  printf("Created %d processes.\n", numoftrials);
  printf("Success - %d%\n", success);
  printf("Failure - %d%\n", failure);
  
  return 0;
}