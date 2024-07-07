#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void heapify(int arr[], int n, int i) {
 int largest = i;
 int left = 2 * i + 1;
 int right = 2 * i + 2;
 if (left < n && arr[left] > arr[largest])
 largest = left;
 if (right < n && arr[right] > arr[largest])
 largest = right;
 if (largest != i) {
 int temp = arr[i];
 arr[i] = arr[largest];
 arr[largest] = temp;
 heapify(arr, n, largest);
 }
}
void heapSort(int arr[], int n) {
 for (int i = n / 2 - 1; i >= 0; i--)
 heapify(arr, n, i);
 for (int i = n - 1; i > 0; i--) {
 int temp = arr[0];
 arr[0] = arr[i];
 arr[i] = temp;
 heapify(arr, i, 0);
 }
}
void main() {
 int n;
 printf("Enter the number of elements: ");
 scanf("%d", &n);
 int arr[n];
 srand(time(NULL));
 for (int i = 0; i < n; i++)
 arr[i] = rand() % 1000;
 clock_t start_time = clock();
 heapSort(arr, n);
 clock_t end_time = clock();
 double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
 printf("Time taken: %f seconds\n", time_taken);
}
