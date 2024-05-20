#include <iostream>

using namespace std;

void merge(long long int arr[], int l, int m, int r, const int n){
    long long int temp[n];
    for(int i = l; i <= r; i++){
        temp[i] = arr[i];
    }
    m = (l+r)/2;
    int i1 = l;
    int i2 = m+1;
    for(int curr = l; curr <= r; curr++){
        if (i1 == m+1){
            arr[curr] = temp[i2++];
        }
        else if(i2 > r){
            arr[curr] = temp[i1++];
        }
        else if(temp[i1]<=temp[i2]){
            arr[curr] = temp[i1++];
        }
        else{
            arr[curr] = temp[i2++];
        }
    }
}

void mergeSort(long long int arr[], int l, int r, const int n){
    if (l < r){
        int m = (l + r)/2;
        mergeSort(arr, l, m, n);
        mergeSort(arr, m+1, r, n);
        merge(arr, l, m, r, n);
    }
}

int main()
{
	int n;
    cin >> n;
    long long int chocolates_prices[n];
    long long int sum = 0;
 
    for(int i = 0; i < n; i++){
        cin >> chocolates_prices[i];
        sum += chocolates_prices[i];
    }
    
    int m;
    cin >> m;
    long long int coupons_list[m];
    
    for(int i = 0; i < m; i++){
            cin >> coupons_list[i];
    }
    
    mergeSort(chocolates_prices, 0, n-1, n);
    for(int i = 0; i < m; i++){
            int coupons_bars;
            coupons_bars = coupons_list[i];
            long long int j = chocolates_prices[n-coupons_bars];
            cout << sum - j <<endl;
            
    }
	return 0;
}
