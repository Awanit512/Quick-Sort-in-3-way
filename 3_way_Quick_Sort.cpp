#include<iostream>
#include<vector>
#include<stdio.h> 
using namespace std;
void partition_function(int a[], int l, int r, int &i, int &j) {
   if (r- l <= 1) {
      if (a[r] < a[l])
         swap(a[r], a[l]);
      i = l;
      j = r;
      return;
}
int mid = l;
int pivot = a[r];
while (mid <= r) {
   if (a[mid]<pivot)
      swap(a[l++], a[mid++]);
      else if (a[mid]==pivot)
         mid++;
      else if (a[mid] > pivot)
         swap(a[mid], a[r--]);
   }
   i = l-1;
   j = mid;
}
void quicksort(int a[], int l, int r) {
   if (l >= r) 
      return;
   int i, j;
   partition_function(a, l, r, i, j);
   quicksort(a, l, i);
   quicksort(a, j, r);
}
void print(int a[], int n) {
   for (int i = 0; i < n; ++i)
   cout << " " << a[i];
   cout << endl;
}
int main() {
   int a[10000];
   int n;
   printf("Enter the size of an array:");
   std::cin>>n;
   for(int i=0;i<n;i++)
   {int x;
     std::cout<<"Enter the value of element:"<<i+1<<": ";
      std::cin>>x;
      a[i]=x;
   }
  
   quicksort(a, 0, n - 1);
  print(a, n);
}