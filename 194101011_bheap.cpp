#include<iostream>
#include<vector>
using namespace std;

class MaxHeap{
    public:
    int *arr;
    int capacity;
    int heap_size;
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
        //cout<<"Heap is full. Please increase the Heap capacity to insert more element: \n\n";
        return;
    }
    else if(searchIndex(data) != -1){
        //cout<<"Data is already present in the Heap. \n\n";
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
        //cout<<"Element inserted Successfully. \n\n";
    }
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



class MinHeap{
    public:
    int capacity;
    int heap_size;
    int *arr;
    MinHeap(int);
    void insertData(int);
    int searchIndex(int);
    int parent(int);
    int lchild(int);
    int rchild(int);
    int getMin();


};

MinHeap :: MinHeap(int capacity){
    this->capacity = capacity;
    arr = new int[capacity];
    heap_size = 0;
}
int MinHeap :: parent(int i){
    return (i-1)/2;
}
int MinHeap :: lchild(int i){
    return 2*i+1;
}

int MinHeap :: rchild(int i){
    return 2*i+2;
}
int MinHeap :: getMin(){
    if(heap_size == 0){
        return 0;
    }
    else arr[0];
}
int MinHeap :: searchIndex(int data){
    for(int i=0; i<heap_size; i++){
        if(arr[i] == data) return i;
    }
    return -1;
}
void MinHeap :: insertData(int data){
    if(heap_size == capacity){
       // cout<<"Heap is full. Please increase the Heap capacity to insert more element: \n\n";
        return;
    }
    else if(searchIndex(data) != -1){
        //cout<<"Data is already present in the Heap. \n\n";
        return;
    }
    else{
        arr[heap_size] = data;
        heap_size++;
        int i = heap_size-1;
        while(i && arr[parent(i)] > arr[i]){
            int tmp = arr[parent(i)];
            arr[parent(i)] = arr[i];
            arr[i] = tmp;
            i = parent(i);
        }
        //cout<<"Element inserted Successfully. \n\n";
    }
}
void preOrderMaxHeap(int x, MaxHeap *maxh){
    if(x >= maxh->heap_size) return;
    cout<<maxh->arr[x]<<" ";
    preOrderMaxHeap(maxh->lchild(x),maxh);
    preOrderMaxHeap(maxh->rchild(x),maxh);
}
void postOrderMinHeap(int x, MinHeap *minh){
    if(x >= minh->heap_size) return;
    postOrderMinHeap(minh->lchild(x),minh);
    postOrderMinHeap(minh->rchild(x),minh);
    cout<<minh->arr[x]<<" ";
}

int main(){
    int data;
    vector<int> v;
    while(cin>>data){
        v.push_back(data);
    }

    MaxHeap maxh(v.size());
    MinHeap minh(v.size());
    for(int i=0; i<v.size(); i++){
        if(maxh.heap_size == minh.heap_size){
            maxh.insertData(v[i]);
        }
        else{
            int x=maxh.getMax();
            if(x<v[i]){
                minh.insertData(v[i]);
            }
            else{
                int y = maxh.extractMax();
                maxh.insertData(v[i]);
                minh.insertData(y);
            }
        }
    }
    preOrderMaxHeap(0,&maxh);
    cout<<endl;
    postOrderMinHeap(0,&minh);
    cout<<endl;
    return 0;

}