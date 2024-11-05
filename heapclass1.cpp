#include <iostream>
using namespace std;

// heap- complete binary tree 
// complete binary tree- node left to right fill hogii 

class Heap{
    public:
    public:
    int *arr;
    int capacity; // size of arr
    int size; // curr elem kitne hain
    
    Heap(int capacity){
    this->arr=new int[capacity+1];
    this->capacity=capacity;
    this->size=0;
    }
    
    void insert(int val){
        if(size==capacity){
            cout<<"full ho gya hain";
            return;
        }
        
        size++;
        int index=size;
        arr[index]=val;
        
        while(index>1){ // kuki hme root element k upr dekhna hi nhii hain
            int parentindex=index/2;
            if(arr[index]>arr[parentindex]){
                swap(arr[index],arr[parentindex]);
                index=parentindex;
            }
            else{
                break;
            }
        }
        
    }
    
    // deletion -  replace root with last elem
    // ab last elem vali pos ko uski correct pos p leke jao
    
    int deletefromheap(){
        int answer=arr[1];
        arr[1]=arr[size];
        size--;
        
        int index=1;
        while(index<size){
            int leftindex=2*index;
            int rightindex=2*index+1;
            
            int largestkaindex=index;
            if(leftindex<=size && arr[largestkaindex]<arr[leftindex]){
                largestkaindex=leftindex;
            }
            
            if(rightindex<=size && arr[largestkaindex]<arr[rightindex]){
                largestkaindex=rightindex;
            }
            if(index==largestkaindex){
                break;
            }
            else{
                swap(arr[index],arr[largestkaindex]);
                index=largestkaindex;
            }
        }
        return answer;
    }
    
    void printheap(){
         for(int i=1;i<=5;i++){
        cout<<arr[i]<<endl;
    }
    }
};







int main()
{
    Heap h(20);
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);
    h.printheap();
    int ans=h.deletefromheap();
    cout<<ans<<" ";
    h.printheap(); 
   

}


// #include <iostream>
// using namespace std;

// Heapify a subtree with the root at index 'index'
void heapify(int *arr, int n, int index) {
    int leftindex = 2 * index;
    int rightindex = 2 * index + 1;
    int largestkaindex = index;
    
    if (leftindex <= n && arr[leftindex] > arr[largestkaindex]) {
        largestkaindex = leftindex;
    }
    if (rightindex <= n && arr[rightindex] > arr[largestkaindex]) {
        largestkaindex = rightindex;
    }
    
    if (index != largestkaindex) {
        swap(arr[index], arr[largestkaindex]);
        heapify(arr, n, largestkaindex);
    }
}

// Convert an array to a max heap
void buildheap(int arr[], int n) {
    for (int index = n / 2; index > 0; index--) {
        heapify(arr, n, index); // kuki leaf node ko hm vount nhi krte 
    }
}

// Heap sort function
void heapsort(int arr[], int n) {
    buildheap(arr,n);
    while (n > 1) {
        swap(arr[1], arr[n]);
        n--;  // Reduce the size of the heap
        heapify(arr, n, 1);  // Heapify the reduced heap
    }
}

int main() {
    // Array with 1-based indexing (arr[0] is ignored)
    int arr[] = {-1, 5, 10, 15, 20, 25, 12};
    
    buildheap(arr, 6);  // Build heap for 6 elements
    cout << "Printing heap:" << endl;
    for (int i = 1; i <= 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    heapsort(arr, 6);  // Perform heap sort
    cout << "Sorted array:" << endl;
    for (int i = 1; i <= 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
