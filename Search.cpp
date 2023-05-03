#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void NhapMang(int a[], int n){
	srand(time(NULL));
	for(int i=0; i<n; i++){
		a[i] = rand()% 100 + 1;
	}
}
void Xuat(int a[], int n){
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
}
//Tìm kiếm tuyến tính

int LinearSearch(int a[], int n, int x){
	int i;
	for(int i=0; i<n; i++){
		if(a[i] == x)
			return i;
	}
    return -1;
}

//Tìm kiếm nhị phân

void binaryInsertionSort(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int x = a[i];
        int left = 0, right = i - 1;
        int j = i - 1;

        // Binary search to find the insertion position of x
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] > x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        // Move all elements greater than x one position to the right
        while (j >= left) {
            a[j + 1] = a[j];
            j--;
        }

        // Insert x into its correct position
        a[left] = x;
    }
}
int main(){
	int n;
	cout <<"Nhap n: ";
	cin >> n;
	int a[n];
	NhapMang(a,n);
	Xuat(a,n);
	cout << endl;
	int x;
	cout <<"Nhap so muon tim trong mang";
	cin >> x;
	int kq = LinearSearch(a,n,x);
	if(kq == -1)
		cout <<"Ko tim thay " << x << " trong mang";
	else 
		cout <<"tim thay " << x << " trong mang tai vi tri " << kq;		
	
}