#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b = temp;
}


void bubbleSort(int arr[] ,int n){
    for(int i=0 ; i< n-1 ; i++){
        bool swapped = false;
        for( int j =0 ; j< n-1-i ;j++ ){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped = true;

            }
        }
        if(!swapped){
            break;
        }
    }
}

void insertion(int arr[],int n){
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i-1;
        while (j >=0 && (arr[j] > key) ){
            arr[j+1]=arr[j];
            j= j-1;
        }
        arr[j+1]= key;
    }
}

void display(int arr[],int n){
    for(int i=0 ; i<n ;i++){
        printf("A[%d] = %d \n",i+1,arr[i]);
    }
}
// Main function
int main() {
    int arr[5] = { 13, 9, 2, 4, 5 };
    insertion(arr,5);
    display(arr,5);

    printf("bubble sort \n");
    int arr2[6] = { 4, 19, 32, 1, 15,22 };
    bubbleSort(arr2,6);
    display(arr2,5);

    return 0;
}
