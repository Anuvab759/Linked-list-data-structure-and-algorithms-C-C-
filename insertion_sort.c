#include<stdio.h>

void display(int arr[], int n){
int i;
for(i=0;i<n;i++){
printf("%3d",arr[i]);
}
printf("\n");
}

void insertionSort(int arr[], int size){
int i,j;
int temp;                   /* to store the element after sorted sublist and compare */
for(i=1;i<size;i++){
temp = arr[i];              
j = i - 1;                  /* go back to the element at the end of sorted sublist */
 while(j>=0 && arr[j] > temp){    /*Comparison between the elements */
  arr[j+1] = arr[j];       /* Move element one step forward if condition satisfies */
  j--;                     /* While the condition is not satisfied, keep moving backwards */
 }
 arr[j+1] = temp;          /*After comparisons are done, replace array element with temp */
}
}

void main(){
int i,n;
int arr[20];
printf("Provide total no. of elements:\n");
scanf("%d",&n);
printf("Enter the elements:\n");
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}

printf("Elements of the array before sorting:\n");
display(arr,n);
printf("Elements of the array after sorting:\n");
insertionSort(arr,n);
display(arr,n);
}
