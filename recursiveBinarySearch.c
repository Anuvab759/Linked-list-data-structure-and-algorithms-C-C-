#include<stdio.h>

int search(int arr[],int element,int low,int high){
int start,end,mid;
start = low;
end = high;
if(end < start){
 return -1;
}
mid = (int)((start + end)/2);
if(element == arr[mid]){
  return mid;
} else if(element > arr[mid]){
 return search(arr,element,mid + 1,end);
} else if(element < arr[mid]){
 return search(arr,element,start,mid - 1);
}
}

void main(){
int arr[] = {10,18,24,29,38,47,51,59,72,88};
int element, position, start, end;
start = 0;
end = 10;
printf("Which one would you like to find?\n");
scanf("%d",&element);

position = search(arr,element,start,end);

if(position != -1){
printf("Position of the element is: %d\n",position+1);
} else {
printf("Number not found!\n");
}
}
