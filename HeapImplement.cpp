#include<iostream>

using namespace std;

class MaxHeap{
    private:
    int *arr;
    int capacity;
    int heap_size;
    public:
    MaxHeap(int);
    void insertData(int);
    void deleteData(int);
    int searchIndex(int);
    void max_heapify(int);
    int extractMax();
    void printHeap();
    void sortHeap();
    int getMax();
    int getMin();
    int parent(int);
    int lchild(int);
    int rchild(int);


};
MaxHeap :: MaxHeap(int capacity){
    this->capacity = capacity;
    arr = new int[capacity];
    heap_size = 0;
}

int MaxHeap :: parent(int i){
    return (i-1)/2;
}

int MaxHeap :: lchild(int i){
    return 2*i+1;
}

int MaxHeap :: rchild(int i){
    return 2*i+2;
}
int MaxHeap :: getMax(){
    if(heap_size == 0){
        cout<<"Heap is empty! \n\n";
        return 0;
    }
    else return arr[0];


}
int MaxHeap :: getMin(){
    if(heap_size == 0){
        cout<<"Heap is empty! \n\n";
        return 0;
    }
    else{
        //min. element in Max heap will be one of the leaf Nodes. Think!!!
        int i = parent(heap_size-1) + 1;
        int min = arr[i-1];
        while(i < heap_size){
            if(arr[i]<min) min = arr[i];
            i++;
        }
        return min;
    }
}
int MaxHeap :: searchIndex(int data){
    for(int i=0; i<heap_size; i++){
        if(arr[i] == data) return i;
    }
    return -1;
}

void MaxHeap :: insertData(int data){
    if(heap_size == capacity){
        cout<<"Heap is full. Please increase the Heap capacity to insert more element: \n\n";
        return;
    }
    else if(searchIndex(data) != -1){
        cout<<"Data is already present in the Heap. \n\n";
        return;
    }
    else{
        arr[heap_size] = data;
        heap_size++;
        int i = heap_size-1;
        while(i && arr[parent(i)] < arr[i]){
            int tmp = arr[parent(i)];
            arr[parent(i)] = arr[i];
            arr[i] = tmp;
            i = parent(i);
        }
        cout<<"Element inserted Successfully. \n\n";
    }
}

void MaxHeap :: deleteData(int data){
    if(heap_size == 0){
        cout<<"Heap is Empty. \n\n";
        return;
    }
    int index = searchIndex(data);
    if(index == -1){
        cout<<"Element is not present in the Heap: \n\n";
        return;
    }
    arr[index] = arr[heap_size-1];
    heap_size--;
    max_heapify(index);
    cout<<"Element deleted successfully. \n\n";
}

int MaxHeap :: extractMax(){
    if(heap_size == 0){
        cout<<"Heap is Empty. \n\n";
        return 0;
    }
    int max = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    max_heapify(0);
    return max;
}
void MaxHeap :: max_heapify(int i){
    int left = lchild(i);
    int right = rchild(i);
    int largest;
    if(left < heap_size && arr[left] > arr[i])
        largest = left;
    else
        largest = i;
    if(right < heap_size && arr[right] > arr[largest])
        largest = right;
    if(largest != i){
        int tmp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = tmp;
        max_heapify(largest);
    }
    
}
void MaxHeap :: printHeap(){
    if(heap_size == 0){
        cout<<"Heap is Empty \n\n";
        return;
    }
    for(int i=0; i<heap_size; i++)
        cout<<arr[i]<<" ";
    cout<<"\n\n";
}
void MaxHeap :: sortHeap(){
    int x=heap_size;
    int *brr = new int[capacity];
    for(int i=0; i<heap_size; i++){
        brr[i] = arr[i];
    }
    while(heap_size){
        int tmp = arr[0];
        arr[0] = arr[heap_size-1];
        arr[heap_size-1] = tmp;
        heap_size--;
        max_heapify(0);
    }
    for(int i=0; i<x; i++){
        cout<<arr[i]<<" ";
    }
    arr = brr;
    heap_size = x;
    delete(brr);
    brr = NULL;
    cout<<"\n\n";
}
int main(){
    int capacity,option,data,min,max;
    cout<<"Enter the capacity of heap"<<endl;
    cin>>capacity;
    MaxHeap mh(capacity);
    while(1){
        cout<<"Enter 1 to insert an Element to Heap: \n";
        cout<<"Enter 2 to Delete an Element to Heap: \n";
        cout<<"Enter 3 to get the Max. Element in the Heap: \n";
        cout<<"Enter 4 to get the min. Element in the Heap: \n";
        cout<<"Enter 5 to extract Max. Element in the Heap: \n";
        //cout<<"Enter 5 to extract Min. Element in the heap: \n";
        cout<<"Enter 6 print all elements of Heap\n";
        cout<<"Enter 7 to sort the Heap \n";
        cout<<"Enter 8 to exit: \n";
        cin>>option;
        switch(option){
            case 1:
                cout<<"Enter the element to insert: ";
                cin>>data;
                mh.insertData(data);
                break;
            case 2:
                cout<<"Enter the element to delete: ";
                cin>>data;
                mh.deleteData(data);
                break;
            case 3:
                max = mh.getMax();
                if(max!=0)
                cout<<max<<endl;
                break;
            case 4:
                min = mh.getMin();
                if(min!=0) cout<<min<<"\n\n";
                break;
            case 5:
                max = mh.extractMax();
                if(max!=0) cout<<max<<"\n\n";
                break;
            case 6:
                mh.printHeap();
                break;
            case 7:
                mh.sortHeap();
                break;
            default :
                break;

        }
        if(option == 8)break;

    }

}