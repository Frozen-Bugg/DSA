#include <iostream>
#include <BITS/stdc++.h>
using namespace std;

// All Important sorting algorithms using recurrsion

// bubble sort
void bubbleSort(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    bubbleSort(arr, n - 1);
}

// selection sort
void selectionSort(int *arr, int p, int q)
{
    int n = q - p;
    if (n <= 1)
        return;
    int min = arr[p];
    int minIndex = p;
    for (int i = p + 1; i < q; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            minIndex = i;
        }
    }
    swap(arr[p], arr[minIndex]);
    selectionSort(arr, p + 1, q);
}

// insertion sort
void insertionSort(int *arr, int n)
{
    if (n <= 1)
        return;
    int last = arr[n - 1];
    insertionSort(arr, n - 1);
    for (int i = n - 1; i > 0; i--)
    {
        if (last < arr[i - 1])
            swap(arr[i], arr[i - 1]);
    }
}

// merge function
void merger(int *arr, int l, int r)
{
    int m = (l + r) / 2;
    int len1 = m - l + 1;
    int len2 = r - m;
    int left[len1 + 1];
    int right[len2 + 1];
    int start = l;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[start++];
    }
    for (int j = 0; j < len2; j++)
    {
        right[j] = arr[start++];
    }
    left[len1] = INT_MAX;
    right[len2] = INT_MAX;
    int i = 0, j = 0, k = l;
    while (k < start)
    {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
}
// merge sort
void mergeSort(int *arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merger(arr, l, r);
}

// partition
int part(int *arr, int l, int r)
{
    int last = arr[r - 1];
    int j = r - 1;
    for (int i = r - 1; i >= l; i--)
    {
        if (arr[i] > last)
            swap(arr[i], arr[--j]);
    }
    swap(arr[j], arr[r - 1]);
    return j;
}
// Quick Sort
void quickSort(int *arr, int l, int r)
{
    if (l >= r)
        return;
    int pivot = part(arr, l, r);
    // cout << pivot;
    quickSort(arr, l, pivot - 1);
    quickSort(arr, pivot + 1, r);
}

// display the array
void showData(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << "\n";
}

int main()
{
    int arr[] = {9, 8, 7, 6, 23, 45};
    quickSort(arr, 0, 6);
    showData(arr, 6);
    return 0;
}