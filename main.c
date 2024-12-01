#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b = temp;
}


void bubbleSort(int arr[] , int n){
    for (int i = 0; i < n-1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; ++j) {
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

int partition(int arr[] , int low , int high){

    int pivotVal = arr[high];
    int i = low;
    for (int k = low ; k<high ; k++ ){
        if(arr[k] <= pivotVal){
            swap(&arr[i],&arr[k]);
            i++;
        }
    }
    swap(&arr[high],&arr[i]);
    return i;
}

void quickSortRecursion(int arr[] , int low , int high){

    if (low < high){
        int pivotIndex = partition(arr,low,high);
        quickSortRecursion(arr, low , pivotIndex-1);
        quickSortRecursion(arr, pivotIndex+1 , high);

    }
}


void quickSort(int arr[] , int length){

    quickSortRecursion(arr, 0 , length-1);

}



void merge(int arr[] , int left ,int mid ,int right){

    int n1 = mid -left +1;
    int n2 = right -mid;
    int leftArr[n1],rightArr[n2];

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left+i];
    }
    for (int i= 0; i < n1; ++i) {
        rightArr[i] = arr[mid+1+i];
    }

    int i = 0 , j= 0;
    for(int k = left ; k <= right ;k++){
        if (i<n1 &&(j>=n2 || leftArr[i] <= rightArr[j] )){
            arr[k] = leftArr[i];
            i++;
        }else{
            arr[k] = rightArr[j];
            j++;
        }
    }
}

void mergesort(int arr[],int left ,int right){
    if(left < right){
        int mid = left +(right - left ) / 2;
        mergesort(arr , left ,mid);
        mergesort(arr , mid+1 ,right);
        merge(arr, left ,mid , right);

    }
}


void insertion(int arr[] , int n ){
    for(int i = 1 ; i<n ; i++){
       int key = arr[i];
       int j =i-1 ;

        while (j>=0 && (arr[j] > key) ){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }

}


void selection(int arr[] , int n){
    for (int i = 0; i < n-1; ++i) {
        int min = i ;
        for (int j = i+1; j < n; ++j) {
            if(arr[min] > arr[j]){
                min= j;
            }
        }

        if(min != i){
            swap(&arr[i],&arr[min]);

        }
    }
}


void display(int arr[],int n){
    for(int i=0 ; i<n ;i++){
        printf("A[%d] = %d \n",i+1,arr[i]);
    }
}


int main() {
  
}
