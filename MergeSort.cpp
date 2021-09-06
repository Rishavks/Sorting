#include<bits/stdc++.h>
using namespace std;

int invCount = 0;

void Merge(int arr[], int l, int m, int r) {
    int n1 = m + 1 - l;//first sub array is arr[l..m]
    int n2 = r - m;//second is arr[m+1..r]

    int L[n1],R[n2];//temp arrays

    //copying data to temp arrays
    for(int i=0;i<n1;i++) {
        L[i] = arr[l + i];
    }
    for(int i=0;i<n2;i++) {
        R[i] = arr[m + 1 + i];
    }
    //merging the two temp arrays back
    int i = 0, j = 0;
    int k = l;

    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
            invCount += (m + 1 - i);//to count number of inversions
        }
    }
    //leftover elements if any
    while(i<n1) {
        arr[k++] = L[i++];
    }
    while(j<n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l<r) {
        int m = l + (r-l)/2;//same as (l+r)/2

        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        Merge(arr, l, m, r);
    }
}

void Print(int arr[], int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<"\t";
    }
}

int main() {

    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++) {
        cout<<"Enter element : ";
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);
    Print(arr, n);
    cout<<"\nInversions Count : "<<invCount;
    return 0;
}
