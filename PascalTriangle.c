// The algorithm alternates between two one-dimensional arrays.
// We use the long long int data type to prevent overflow, as the coefficients grow quickly.
#include "stdlib.h"
#include "stdio.h"
int main(){
    int n;
    do {
        printf("Please enter the order of the triangle, the smallest order is 0. \n");
        scanf("%d", &n);
    } while (n < 0);

    long long int* pascal1 = NULL;
    long long int* pascal2 = NULL;

    for (int i = 0; i <= n; i++) {
        pascal2 = (long long int*)malloc((i+1) * sizeof(long long int)); 
        
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                pascal2[j] = 1; // first and last elements of each row are 1
            } else {
                pascal2[j] = pascal1[ j-1] + pascal1[j];
            }
            printf("%lld ", pascal2[j]);
        }
        printf("\n");
        // Free the old pascal1 and point it to pascal2 for the next iteration
        free(pascal1);
        pascal1 = pascal2;
    }
    free(pascal1);
    return 0;
}
