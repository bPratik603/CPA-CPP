/* 
    MxN
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

int main(void)
{
    int M; 
    int N; 
    int* parr = NULL; 
    int i, j; 

    printf("Enter M:"); 
    scanf("%d", &M); 

    printf("Enter N:"); 
    scanf("%d", &N); 

    assert(M > 0 && N > 0); 

    parr = (int*)malloc((M * N * sizeof(int))); 
    assert(parr != NULL); 

    for(i = 0; i < M; ++i)
        for(j = 0; j < N; ++j)
            *(parr + i * N + j) = (i + j); 
    
    for(i = 0; i < M; ++i)
        for(j = 0; j < N; ++j)
            printf("M[%d][%d] = %d\n", i, j, *(parr + i * N + j)); 

    free(parr); 
    parr = 0; 

    return EXIT_SUCCESS; 
}

/* 
    parr = malloc(M * N * sizeof(int)); 
    int arr[M][N]; 

    to access cell with row i, col j: (0 <= i < M and 0 <= j < N)
    arr[i][j]; 
    == 
    *(parr + i * N + j)

*/


