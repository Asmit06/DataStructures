/* 
DS ASSIGNMENT    
Name: Asmit Saha
SID: 21104105 
*/

#include <iostream>
using namespace std;

//BUBBLE SORT
pair<int,int> bubbleSort(int *arr, int size) {
    int b_swaps = 0;//to maintain the count of the no. of swaps 
    int b_comparisons = 0;
    for (int j = 0; j < size - 1; j++){
        for (int i = 0; i < size - 1 - j; i++){
            if (arr[i] > arr[i + 1]){
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                b_swaps++;
            }
            b_comparisons++;
        }
    }
    pair<int,int> ans;
    ans.first = b_swaps;// number of swaps.
    ans.second = b_comparisons;//Number of comparisons.
    return ans;
}

//SELECTION SORT
pair<int,int> SelectionSort(int *arr,int size){
    int min;
    int s_swaps = 0;
    int s_comparisons = 0;
    for(int i=0;i<size;i++){
        min = i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min = j;
                s_swaps++;
            }
            s_comparisons++;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    pair<int,int> ans;
    ans.first = s_swaps;
    ans.second = s_comparisons;
    return ans;
}

int main(){
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    pair<int,int> bubble = bubbleSort(arr,n);
    pair<int,int> selection = SelectionSort(arr,n);
    cout << "COMPARISON BETWEEN INSERTION AND BUBBLE SORT. " << endl;
    cout << endl;
    cout << "1. ON THE BASIS OF NUMBER OF COMPARISONS : " << " ";
    if(bubble.second > selection.second){
        cout << "MORE COMPARSIONS ARE REQUIRED FOR BUBBLE SORT." << endl;
    }
    else if(bubble.second < selection.second){
        cout << "MORE COMPARISONS ARE REQUIRED FOR SELECTION SORT." << endl;
    }
    else{
        cout << "BOTH REQUIRE EQUAL NUMBER OF COMPARISONS." << endl;
    }
    cout << endl;

    //second comparison

    cout << "2. ON THE BASIS OF NUMBE ROF SWAPS : " << " ";
    if(bubble.first > selection.first){
        cout << "MORE SWAPS ARE REQUIRED FOR BUBBLE SORT." << endl;
    }
    else if(bubble.first < selection.first){
        cout << "MORE SWAPS ARE REQUIRED FOR SELECTION SORT." << endl;
    }
    else{
        cout << "BOTH REQUIRE EQUAL NUMBER OF SWAPS." << endl;
    }
    cout << endl;

    cout << "3 . As both BubbleSort and SelectionSort are In-place algorithms, hence both of their Inplace Algorithms have been written above." << endl;

}
