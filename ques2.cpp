#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i=l, j=m+1, k=0;
    int temp[100];

    while(i<=m && j<=r)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i<=m)
        temp[k++] = arr[i++];

    while(j<=r)
        temp[k++] = arr[j++];

    for(int x=0; x<k; x++)
        arr[l+x] = temp[x];
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {12,11,13,5,6,7};
    int arr2[] = {38,27,43,3,9,82,10};

    int n1 = sizeof(arr)/sizeof(arr[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    mergeSort(arr,0,n1-1);
    mergeSort(arr2,0,n2-1);

    cout<<"Sorted Array 1: ";
    for(int i=0;i<n1;i++)
        cout<<arr[i]<<" ";

    cout<<"\nSorted Array 2: ";
    for(int i=0;i<n2;i++)
        cout<<arr2[i]<<" ";

    return 0;
}
