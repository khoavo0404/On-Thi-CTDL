#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void Nhap(int a[], int n);
void Xuat(int a[], int n);
void BubbleSort(int a[], int n);
void InsertionSort(int a[], int n);
void SelectionSort(int a[], int n);
void InterchangeSort(int a[], int n);
void QuickSort(int a[], int left, int right);
void MergeSort_DQ(int a[], int left, int right);
void Merge_DQ(int a[], int left, int mid, int right);
void ShakerSort(int a[], int n);
void MergeSort(int a[], int n);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void shellSort(int a[], int n);
void binaryInsertionSort(int a[], int n);

void Menu();
int *a;
int n;
int main(){
	while(true){
		Menu();
	}
}
void Menu (){
	cout <<"----------------------------------------------\n";
	cout <<"\tMoi ban chon sort de thuc hien sap xep\n"; 
	cout <<"1.Chon nhap xuat mang!\n";
	cout <<"2.BuubleSort\n";
	cout <<"3.InsertionSort\n";
	cout <<"4.SelectionSort\n";
	cout <<"5.InterchangeSort\n";
	cout <<"6.QuickSort\n";
	cout <<"7.MergeSort_DQ\n";
	cout <<"8.ShakerSort\n";
	cout <<"9.MergeSort\n";
	cout <<"10.HeapSort\n";
	cout <<"11.ShellSort\n";
	cout <<"12.BinarySort\n";
	cout <<"13.chon exit de thoat!\n";
	cout <<"----------------------------------------------\n\n";
	int chon;
	cout <<"Moi ban chon: ";
	cin >>chon;
	switch(chon){
		case 1:
			cout << "nhap n: ";
			cin >> n;
			if(a!=NULL){
				delete a;
				a = NULL;
			}
			a = new int[n];
			Nhap(a,n);
			cout <<"\nMang vua xuat: ";
			Xuat(a,n);
			cout << endl;
			break;
		case 2:
			BubbleSort(a,n);
				cout <<"Mang sap xep theo kieu BubbleSort: ";
			Xuat(a,n);	
				cout << "\n\n";
			break;
		case 3:
			InsertionSort(a,n);
				cout <<"Mang sap xep bang InsertionSort: ";
			Xuat(a,n);
				cout <<"\n\n";
			break;
		case 4:
			SelectionSort(a,n);
				cout <<"Mang sap xep bang SelectionSort: ";
			Xuat(a,n);
				cout <<"\n\n";	
			break;
		case 5:
			InterchangeSort(a,n);
				cout <<"Mang sap xep bang InterchangeSort: ";
			Xuat(a,n);
				cout <<"\n\n";
			break;
		case 6:
			QuickSort(a,0,n-1);
				cout <<"Mang sap xep bang QuickSort: ";
			Xuat(a,n);
				cout <<"\n\n";
			break;
		case 7:
			MergeSort_DQ(a,0,n-1);
				cout<<"Mang sap xep bang MergeSort de quy: ";
			Xuat(a,n);
				cout <<"\n\n";
			break;
		case 8:
			ShakerSort(a,n);
				cout <<"Shaker: ";
			Xuat(a,n);
				cout <<"\n\n";
			break;
		case 9:
			MergeSort(a,n);
				cout <<"Mang sap xep theo mergesort: ";
			Xuat(a,n);
				cout <<"\n\n";
			break;
		case 10:
			heapSort(a,n);
				cout <<"Mang sap xep theo Heapsort: ";
			Xuat(a,n);
				cout <<"\n\n";	
			break;
		case 11:
			shellSort(a,n);
				cout <<"Mang sap xep theo ShellSort: ";
			Xuat(a,n);
				cout << "\n\n";
			break;
		case 12:
			binaryInsertionSort(a,n);
				cout <<"Mang sap xep theo BinaryInsertionSort: ";
			Xuat(a,n);
				cout <<"\n\n";
			break;
		case 13:
			exit(0);
	}
}
void Nhap(int a[], int n){
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

//Bubble sort
void BubbleSort(int a[], int n){
	int i,j;
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(a[j] < a[j-1])
			{
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}

//Insertion sort
void InsertionSort(int a[], int n){
	int pos =0;
	int x;
	for(int i=1; i<n; i++){
		x = a[i];
		for(pos = i;(pos > 0 && a[pos - 1] > x); pos --){
			a[pos] = a[pos-1];
		}
		a[pos] = x;
	}
}

//selection sort
void SelectionSort(int a[], int n){
	int min;
	for(int i=0; i<n-1; i++){
		min = i;//Giả sử gán min lúc đầu là giá trị nhỏ nhất
		for(int j=i+1; j<n;j++){//Tìm kiếm giá trị nhỏ nhất trong dãy còn lại và so sánh với min lúc đầu
			if(a[i] < a[min])
				min = j;
		}
		if(min != i){
			int Temp = a[i];
			a[i] = a[min];
			a[i] = Temp; 
		}				
				
	}
	
}

//Interchange sort
void InterchangeSort(int a[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i] > a[j]){
				int Temp = a[i];
				a[i] = a[j];
				a[j] = Temp;
			}
		}
	}	
}

//Quick sort
void QuickSort(int a[], int left, int right){
	if(left <= right) return;
	int mid = a[(left + right)/2];
	int i = left;
	int j = right;
	do{
		while(a[i] < mid) i++;
		while(a[j] > mid) j--;
		if(i<=j){
			int Temp = a[i];
			a[i] = a[j];
			a[j] = Temp;
		}
	}while(i < j);
	QuickSort(a,left,j);
	QuickSort(a,i,right);
}

//Merge sort đệ quy
void MergeSort_DQ(int a[], int left, int right){
	if(left <= right) return;
	int mid =(left+right)/2;
	MergeSort_DQ(a,left,mid);
	MergeSort_DQ(a,mid+1,right);
	Merge_DQ(a,left,mid,right);
}
void Merge_DQ(int a[], int left, int mid, int right){
	int nTemp = right - left + 1;
	int Temp[nTemp];
	int i=left;
	int j=mid+1;
	int pos = 0;
	while(i>mid && j>right){
		if(i<=mid && j<=right && a[i] < a[j] || j>right){
			Temp[pos++] = a[i++];
		}else
			Temp[pos++] = a[j++];
	}
	for(int i=0; i<nTemp; i++){
		a[left + i] = Temp[i];
	}
}

//Shaker sort
void ShakerSort(int a[], int n){
	int i,j;
	int left,right,k;
	left=0; right=n-1;k=n-1;
	while(left < right){
		for(j=right;j>left;j--){
			if(a[j] <a[j-1]){
				int Tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = Tmp;
				k=j; 				
			}
			left = k;
		}
		for(i=left;i>right;i++){
			if(a[i] > a[i+1]){
				int Tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = Tmp;
				k = i;
			}
			right = k;
		}
	}
}

//Merge sort
void MergeSort(int a[], int n) {
    int left, mid, right;
    int i, j, k;
    int *temp = new int[n];
    for (int size = 1; size < n; size *= 2) {
        left = 0;
        while (left < n - size) {
            mid = left + size - 1;
            right = mid + size;
            if (right > n - 1) {
                right = n - 1;
            }
            i = left;
            j = mid + 1;
            k = 0;
            while (i <= mid && j <= right) {
                if (a[i] < a[j]) {
                    temp[k++] = a[i++];
                } else {
                    temp[k++] = a[j++];
                }
            }
            while (i <= mid) {
                temp[k++] = a[i++];
            }
            while (j <= right) {
                temp[k++] = a[j++];
            }
            for (i = left, k = 0; i <= right; i++, k++) {
                a[i] = temp[k];
            }
            left = left + size * 2;
        }
    }
    delete[] temp;
}

//Heap sort
void heapify(int arr[], int n, int i) {
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

//Shell sort
void shellSort(int a[], int n) {
    // Lặp qua các khoảng cách
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Lặp qua các phần tử trong khoảng cách
         for (int i = gap; i < n; i += 1) {
            // Lưu trữ giá trị hiện tại
            int temp = a[i];
 
            // Dịch các phần tử lớn hơn lên
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
 
            // Đặt giá trị hiện tại vào vị trí đúng
            a[j] = temp;
        }
    }
}

//Binary sort
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
