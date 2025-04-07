#include <iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int number, int k){
    if( r >= l){
        int m = (l+r)/2;
        if ((number - arr[m]) == k){
            return m;
        }else if((number-arr[m]) < k){
            return binarySearch(arr, l, m-1, number, k);
        }else{
            return binarySearch(arr, m+1, r, number, k);
        }
    }
    else{
        return -1;
    }
}
int pairs_numbers(int arr[], int k, const int n){
    
    int pairs = 0;
    for(int i = n-1; i >= 1; i--){
        int number = arr[i];
        int m = binarySearch(arr, 0, n-1, number, k);
        if(m != -1){
            pairs +=1;
        }
    }
    
    return pairs;
}

int hoarePartition(int arr[], int l, int r){
    int p = arr[l];
    int i = l;// in this case we dont have to do (l-1) because the first element is the pivot and we haven't to change
    int j = r+1;// r+1 because in the first verification the j goes to the last element of the array
    do{
        do{
            i += 1;
        }while(not(arr[i]>= p or i>=r));
        do{
            j -= 1;
        }while(not(arr[j]<=p));
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }while(not(i >= j));
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
    int temp2 = arr[l];
    arr[l] = arr[j];
    arr[j] = temp2;
    
    return j;
}

void quickSort(int arr[], int l, int r){
    if(l < r){    
        int s; // split position
        s = hoarePartition(arr, l, r);
        quickSort(arr, l, s-1);
        quickSort(arr, s+1, r);
    }
}

int main()
{
    int n,k;
    cin >> n >> k;
    
    int list[n];
    for(int i = 0; i < n; i++){
        cin >> list[i];
    }
    
    quickSort(list, 0, n-1);
    int p = pairs_numbers(list, k, n);
    cout << p;
    
	return 0;
}
