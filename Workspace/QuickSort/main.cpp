#include <iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int k){
    if( r >= l){
        int m = (l+r)/2;
        if (k== arr[m]){
            return m;
        }else if(k< arr[m]){
            return binarySearch(arr, l, m-1, k);
        }else{
            return binarySearch(arr, m+1, r, k);
        }
    
    }
    else{
        return -1;
    }
}

int hoarePartition(int arr[], int l, int r){
    int p = arr[l];
    int i = l;// in this case we dont have to do (l-1) because the first element is the pivot and we haven't to change
    int j = r+1;// r+1 because in the first verification the j goes to the last element of the array
    do{
        do{
            i = i+1;
        }while(not(arr[i]>= p or i>=r));
        do{
            j = j - 1;
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
    
    quickSort(array, 0, n-1);
    
    cout <<"Os elementos na ordem são \n"<< endl;
    for(auto s : array)
        {
        cout << s << " ";
            }
    
    int k;  
    cout << "Digite um número: ";
    cin >> k;
    int m = binarySearch(array,0, n-1, k);
    if(m == -1){
        cout << k <<  "nexiste na lista"<< endl;
    }else{
        cout << k <<  " existe" << endl;
    }
    
	return 0;
}
