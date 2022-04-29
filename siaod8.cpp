#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <chrono>
#include <ctime>
using namespace std;
void randomarr(int*&arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % n;
	}
}
void arrOut(int*& arr , int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void SelectionSort(int* & arr, int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) 
				min = j;
			
		}
		swap(arr[i], arr[min]);
	}
	//arrOut(arr, n);

}
void heapify(int*& arr, int n, int i)
{
    int most = i;
   
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 


    if (left < n && arr[left] > arr[most])
        most = left;

   
    if (right < n && arr[right] > arr[most])
        most = right;

    
    if (most != i)
    {
        swap(arr[i], arr[most]);

        
        heapify(arr, n, most);
    }
}


void heapSort(int*& arr, int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    
    for (int i = n - 1; i >= 0; i--)
    {
        
        swap(arr[0], arr[i]);

        
        heapify(arr, i, 0);
    }
}
void mergesort(int*& arr, int start,int end)
{
    
    if (end - start < 2)
        return;
    if (end - start == 2)
        if (arr[start] > arr[start + 1]) {
            swap(arr[start], arr[start + 1]);
            return;
    }
    
    mergesort(arr, start, start + (end - start) / 2);
    mergesort(arr, start + (end - start) / 2, end);
    int start1 = start;
    int start2 = start + (end - start) / 2;
    int e = start2;
    vector <int> b;
    
    while (b.size()<end-start) {
        if (start1>=e||(start2<end && arr[start2] <= arr[start1])) {
            b.push_back(arr[start2]);
            start2++;
                
        }
        else {
            b.push_back(arr[start1]);
            start1++;
            
        }
    }
    
    for (int i = start; i < end; i++) {
        arr[i] = b[i - start];

   }
               
    
   
}

int main() {
	
    int n;
    cin >> n;

    int* arr = new int[n];
    setlocale(LC_ALL, "Rus");
    //for (int i=0; i < n; i++)
      //  cin >> arr[n];
    randomarr(arr, n);
    //arrOut(arr, n);
    //arrOut(arr, n);
    unsigned int start_time = clock();
	//SelectionSort(arr, n);
   
   // heapSort(arr, n);
    
    mergesort(arr, 0, n);
    //arrOut(arr,0, n);

    cout << clock() - start_time;
}