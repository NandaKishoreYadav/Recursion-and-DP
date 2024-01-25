// Merge Sort

#include<bits/stdc++.h>
using namespace std;
void merge(int *arr,int low,int mid,int high){
    int temp[high+1];
    int i=low,j=mid+1,k=low;
    while(i<=mid and j<=high){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i];
            i++;
        }
        else{
            temp[k++]=arr[j];
            j++;
        }
    }
    while(i<=mid){
        temp[k++]=arr[i];
        i++;
    }
    while(j<=high){
        temp[k++]=arr[j];
        j++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i];
    }
}
void mergesort(int *arr,int low,int high){
    if(low>=high)return;
    int mid=low+(high-low)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
