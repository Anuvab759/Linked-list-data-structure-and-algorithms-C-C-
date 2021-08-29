#include<stdio.h>

void display(int arr[], int n){
int i;
for(i=0;i<n;i++){
printf("%4d",arr[i]);
}
printf("\n");
}

void swap(int *a, int *b){
int temp;
temp = *a;
*a = *b;
*b = temp;
}

int partition(int arr[],int min,int max){
int pivot = arr[max];
int pIndex = min;
for(int i = min; i < max; i++){
if(arr[i] < pivot){
swap(&arr[i],&arr[pIndex]);
pIndex++;
}
}
swap(&arr[pIndex],&arr[max]);
return pIndex;
}

void quickSort(int arr[],int start,int end){
if(start < end){
int pIndex = partition(arr,start,end);
quickSort(arr,start,pIndex - 1);
quickSort(arr,pIndex + 1,end);
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
quickSort(arr,0,n-1);
display(arr,n);
}
