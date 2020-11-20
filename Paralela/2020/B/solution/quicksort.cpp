/*
  Quicksort
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <openssl/md5.h>
#include <algorithm>


/*
 * Prototypes
 */
void srandnum(int seed);
double randnum(void);
int *generate_case(int N);
double drand(int xmin, int xmax);
// void swap(int *toorder, int i, int j);
// int partition(int *toorder, int lo, int hi);
// void _quicksort(int *toorder, int lo, int hi);
// void quicksort(int *toorder, int N);
int is_sorted(int *toorder, int N);

/*
 * A generic pRNG
 */
#define MY_RAND_MAX 0x7FFFFFFF

#define RANDNUM_W 521288629
#define RANDNUM_Z 362436069

unsigned int randum_w = RANDNUM_W;
unsigned int randum_z = RANDNUM_Z;

void print(int *a, int N){
    for(int i = 0; i < N; i++)
        printf("%d\n", a[i]);
    printf("\n");
}

void srandnum(int seed)
{
    unsigned int w, z;
    w = (seed * 104623) & 0xffffffff;
    randum_w = (w) ? w : RANDNUM_W;
    z = (seed * 48947) & 0xffffffff;
    randum_z = (z) ? z : RANDNUM_Z;
}

double randnum()
{
    unsigned int u;
    randum_z = 36969 * (randum_z & 65535) + (randum_z >> 16);
    randum_w = 18000 * (randum_w & 65535) + (randum_w >> 16);
    u = (randum_z << 16) + randum_w;
    return abs((int)u);
}

/*
 * Main function
 */
int main(int argc, char *argv[])
{
    int N = 0;
    int *our_list = NULL;

    //The input provides the case size
	scanf("%d", &N);
    if (N <= 0) {
	printf("Error: please, provide the case size.\n");
	return 1;
    }

    //Generate the case
    our_list = generate_case(N);
    if (our_list == NULL) {
	printf("Error: case instantiation failed.\n");
	return 1;
    }

    //print(our_list, N);

    //Do the thing
    //quicksort(our_list, N);

    std::sort(our_list, our_list + N);

    //print(our_list, N);

    if (is_sorted(our_list, N) == 1) {
	printf("Error, for some reason list is still unsorted.\n");
	return 1;
    }

    //Compute MD5 Checksum for problem identification
    MD5_CTX c;
    unsigned char out[MD5_DIGEST_LENGTH];
    MD5_Init(&c);
    MD5_Update(&c, our_list, N * sizeof(int));
    MD5_Final(out, &c);
    for (int n = 0; n < MD5_DIGEST_LENGTH; n++) {
	printf("%02x", out[n]);
    }
    printf("\n");

    //Clean up
    free(our_list);

    return 0;
}

// /*
//  * Public API
//  */
// void quicksort(int *toorder, int N)
// {
//     _quicksort(toorder, 0, N - 1);
// }

// /*
//  * Internal recursive function to quicksort
//  */
// void _quicksort(int *toorder, int lo, int hi)
// {
//     if (lo >= hi)
// 	return;
//     int b = partition(toorder, lo, hi);
//     _quicksort(toorder, lo, b - 1);
//     _quicksort(toorder, b + 1, hi);
// }

// /*
//  * Swap two values.
//  */
// void swap(int *toorder, int i, int j)
// {
//     int temp = toorder[i];
//     toorder[i] = toorder[j];
//     toorder[j] = temp;
// }

// /*
//  * Partition decision
//  */
// int partition(int *toorder, int lo, int hi)
// {
//     int b = lo;
//     int r = (int) (lo + (hi - lo) * (randnum() / MY_RAND_MAX));
//     int pivot = toorder[r];
//     swap(toorder, r, hi);
//     for (int i = lo; i < hi; i++) {
// 	if (toorder[i] < pivot) {
// 	    swap(toorder, i, b);
// 	    b++;
// 	}
//     }
//     swap(toorder, hi, b);
//     return b;
// }

/*
 * Check if elements are in non-decreasing order
 */
int is_sorted(int *toorder, int N)
{
    for (int i = 1; i < N; i++) {
	if (toorder[i] < toorder[i - 1]) {
	    return 1;
	}
    }
    return 0;
}


/*
 * Generate a case
 */
int *generate_case(int N)
{
    int i;
    int *ret = NULL;

    // Make case generation reproducible
    srandnum(0);

    // Allocate memory
    ret = (int *) malloc(N * sizeof(int));
    if (ret == NULL) {
	printf("Error: some malloc won't work.\n");
	return NULL;
    }
    // Get pseudo-random positive integer values
    for (i = 0; i < N; i++) {
	ret[i] = drand(0, INT_MAX);
    }
    return ret;
}

/*
 * A pseudo-random number between two positive integer values
 */
double drand(int xmin, int xmax)
{
    return xmin + (xmax - xmin) * randnum() / MY_RAND_MAX;
}
