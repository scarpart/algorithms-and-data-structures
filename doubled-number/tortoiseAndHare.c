#include <stdlib.h>
#include <stdio.h>

int find_repeated_number(int *arr);

int main() {
    int *vsize;
    printf("input the size of the array: ");
    scanf("%d", vsize);
    int *arr = (int*)malloc((*vsize)*sizeof(int));

    for (int i = 0; i < *vsize; i++) {
        printf("input number at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    int result = find_repeated_number(arr);
    printf("the repeated number is: %d\n", result);

    free(arr);
    return 0;
}

int find_repeated_number(int *arr) {
    int slow = 0, fast = 1;
    while (1) {
        slow = arr[slow];
        fast = arr[arr[fast]];
        if (slow == fast) break;
    }
    slow = 0;
    while (arr[slow] != arr[fast]) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return arr[fast];
}