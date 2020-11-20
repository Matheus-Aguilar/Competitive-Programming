#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

#define MAXNUM 100
#define MAXSTR 50
#define MAXRESULTS 2000

char firstHalf[MAXNUM][MAXSTR];
char secondHalf[MAXNUM][MAXSTR];
char strToTest[MAXRESULTS][MAXSTR];
long int primeToTest[MAXRESULTS];
long int result[MAXRESULTS];
int numPrimes=0;
int cont[MAXRESULTS];
int primes[MAXRESULTS][MAXRESULTS];

int isprime(long int value)
{ long int root;
  long int factor=2;
  int prime=1;
  root = sqrtl(value);
  while ((factor<=root) && (prime))
        { prime = fmod((double)value,(double) factor) > 0.0;
		  factor++;
	    }
  return prime;
}

void quicksort(long int *primes,int first,int last)
{ int i, j, pivot;
  long int temp;

  if (first<last)
     { pivot=first;
       i=first;
       j=last;
       while(i<j)
	     { while (primes[i]<=primes[pivot]&&i<last)
             i++;
           while(primes[j]>primes[pivot])
             j--;
           if (i<j)
		      { temp=primes[i];
                primes[i]=primes[j];
                primes[j]=temp;
              }
         }
       temp=primes[pivot];
       primes[pivot]=primes[j];
       primes[j]=temp;
       quicksort(primes,first,j-1);
       quicksort(primes,j+1,last);
     }
}


int main(int argc,char** argv)
{ FILE *primesFile;
  int numResults=0;
  primesFile=stdin;
  fscanf(primesFile,"%d\n",&numPrimes);
  for (int i=0;i<numPrimes;i++)
      fscanf(primesFile,"%s\n",firstHalf[i]);
  for (int i=0;i<numPrimes;i++)
      fscanf(primesFile,"%s\n",secondHalf[i]);
  fclose(primesFile);

  int nt = min(omp_get_max_threads(), numPrimes);
  
  omp_set_num_threads(nt);

  #pragma omp parallel for
  for(int t=0;t<nt;t++){
    for (int i=t;i<numPrimes;i+=nt){
      for (int j=0;j<numPrimes;j++){ 
        strcpy(strToTest[t],firstHalf[i]);
        strcat(strToTest[t],secondHalf[j]);
        primeToTest[t]=atol(strToTest[t]);
        if (isprime(primeToTest[t])) { 
          primes[t][cont[t]++]=primeToTest[t];
        }
      }
    }
  }
  
  for(int i=0;i<nt;i++)
    for(int j = 0; j < cont[i]; j++)
      result[numResults++]=primes[i][j];

  quicksort(result,0,numResults-1);
  for (int i=0;i<numResults;i++)
      printf("%ld\n",result[i]);	  
  return 0;
}