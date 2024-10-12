#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main() {
    int length;
    printf("Please enter the length of your password \n");
    scanf("%d", &length);
    
    char *pwd = malloc(length + 1);
    char *ptr1 = pwd;
    
    srand(time(NULL));
//takes a random ascii character from the interval [33 , 126]
    for (int i = 0; i < length; i++) {
        int s = (rand() % 94) + 33; 
        pwd[i] = s;
    }

    pwd[length] = '\0';
    for (int i = 0; i < length; i++) {
        printf("%c", ptr1[i]);
    }
    
    free(pwd);
    return 0;
}
