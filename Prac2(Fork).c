#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void asc(int*, int);
void dsc(int*, int);

int main() {
    pid_t pid;
    int *a, sz, i;

    printf("Enter the size of the array:\n");
    scanf("%d", &sz);

    a = (int*)malloc(sz * sizeof(int));
    if (a == NULL) {
        perror("Memory allocation failed");
        exit(-1);
    }

    printf("Enter elements of the %d-size array:\n", sz);
    for (i = 0; i < sz; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    pid = fork();
    switch (pid) {
        case -1:
            printf("Error in fork\n");        
            free(a);  // Free memory before exit
            exit(-1);    
        case 0:
            printf("Child process\n");    
            asc(a, sz);
            free(a);  // Free memory before exit
            exit(0);    
        default:
            wait(NULL);
            printf("Parent process\n");
            dsc(a, sz);
            free(a);  // Free memory before exit
            exit(0);    
    }
    return 0;
}

void asc(int *a, int sz) {
    int i, j, temp;
    for (i = 0; i < sz; i++) {
        for (j = i + 1; j < sz; j++) {
            if (a[i] > a[j]) {            
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;        
            }    
        }
    }
    printf("Sorted array elements in ascending order are:\n");
    for (i = 0; i < sz; i++) {
        printf("%d\t", a[i]);        
    }
    printf("\n");
}

void dsc(int *a, int sz) {
    int i, j, temp;
    for (i = 0; i < sz; i++) {
        for (j = i + 1; j < sz; j++) {
            if (a[i] < a[j]) {            
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;        
            }    
        }
    }
    printf("Sorted array elements in descending order are:\n");
    for (i = 0; i < sz; i++) {
        printf("%d\t", a[i]);        
    }
    printf("\n");
}
