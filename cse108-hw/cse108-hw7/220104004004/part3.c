#include <stdio.h>

void find_min_max(int arr[], int n){


    int *p = arr + 1;
    

    while (p < arr + n) {

        if (*p < arr[0]) {
            arr[0] = *p;
        }
        

        if (*p > arr[n]) {
            arr[n] = *p;
        }
        

        p++;
    }
    

    printf("Minimum value: %d\n", arr[0]);
    printf("Maximum value: %d\n", arr[n]);
}

int main() {

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    

    find_min_max(arr, n);
    
    return 0;
}

