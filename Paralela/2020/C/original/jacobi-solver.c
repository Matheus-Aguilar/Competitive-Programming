#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

void matrixSolverJacobi(float * __restrict__ A,
                        float * __restrict__ b,
                        float * __restrict__ x0,
                        float * __restrict__ x1,
                        const float inErr,
                        const unsigned int m,
                        const unsigned int n){
  int nextStep = 1;
  unsigned int steps = 0;
  while (nextStep){
        steps++;
        register float maxErr = 0.0f,
                        err = 0.0f;
        for (unsigned int i = 0; i < m; i++){
          register float aux = 0.0f;
          register float acc = b[i];

          for (unsigned int j = 0; j < n; j++){

            if (i == j){
              aux = 1.0f / A[i * n + j] ;
            }else{
              acc += (A[i * n + j] * x0[j] * -1.0f);
            }

          }
          x1[i] = aux * acc;
        }


       for (unsigned int j = 0; j < n; j++){
         err = fabs(x1[j] - x0[j]) / fabs(x1[j]);
         if(maxErr < err){
           maxErr = err;
         }
       }
/*
      if ((steps % 100) == 0){
        cout << "Error: " << maxErr << endl;
        cout.flush();
      }
*/
      if (maxErr < inErr)
          nextStep = 0;
      else{
        float *ptrAux = x0;
        x0 = x1;
        x1 = ptrAux;
      }

  }
  printf("%u\n", steps);

}

int check(float *a, float *b, const unsigned int size, const float err){
    float maxErr = fabs(a[0] - b[0]);
    for (unsigned int i = 1; i < size; i++){
      float lErr = fabs(a[i] - b[i]);
      if (maxErr < lErr)
        maxErr = lErr;
    }

    return (maxErr <= err);
}

int main (int ac, char **av){
  FILE *inFile = NULL;
  float *A;
  float *b;
  float *x0;
  float *x1;
  float *xG;

  float err;
  unsigned int aux;
  unsigned int m;
  unsigned int n;

  inFile = stdin;
  assert(inFile != NULL);
  fread( &m, 1, sizeof(unsigned int),inFile);
  fread( &n, 1, sizeof(unsigned int), inFile);
  fread( &aux, 1, sizeof(unsigned int), inFile);
  err = pow (10.0f, -1.0f * (float) aux);
  A  = (float*) malloc(m * n * sizeof(float));
  b  = (float*) malloc(m * sizeof(float));
  x0 = (float*) malloc(n * sizeof(float));
  x1 = (float*) malloc(n * sizeof(float));
  xG = (float*) malloc(n * sizeof(float));

  fread(A, m * n, sizeof(float), inFile);
  fread(b, m , sizeof(float), inFile);
  fread(xG,  n, sizeof(float), inFile);

  memset(x0, 0x00, sizeof(float) * n);
  memset(x1, 0x00, sizeof(float) * n);

  matrixSolverJacobi(A, b, x0, x1, err, m, n);

  printf("%d\n", check(x1, xG, n, err));

  free(A);
  free(b);
  free(x0);
  free(x1);
  free(xG);
  fclose(inFile);
  return EXIT_SUCCESS;
}
