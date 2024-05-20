#include <iostream>

using namespace std;


void merge(int arr[], int l, int m, int r, const int n){
    int temp[n];
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

void mergeSort(int arr[], int l, int r, const int n){
        //l = index of the first
        //r = index from the last
        //m = index from the middle
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
    cout << "Digite a quantidade de elementos dessa array : " << endl;
	cin >> n;
    int array[n];
    cout << endl;
    
    cout << "digite os elementos: " << endl;
    for(int i {0}; i <= (n-1) ; i++)
        {
        int temp;
        cin >> temp;
        array[i] = temp;
        }
    
    mergeSort(array, 0, n-1, n);
    
    cout <<"Os elementos na ordem são \n"<< endl;
    for(auto s : array)
        {
        cout << s << " "; 
            }
    
	return 0;
}
