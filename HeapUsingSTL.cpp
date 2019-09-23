#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v1 = {20, 30, 40, 25, 15};
    //converting vector into a heap using make_heap
    make_heap(v1.begin(),v1.end());
    //Displaying the maximum element of heap using front()
    cout<<"The Maximum element of the heap is : ";
    cout<<v1.front()<<endl;

    //using push_back() to enter element in the vector
    v1.push_back(50);

    //using push_heap() to reorder elements
    push_heap(v1.begin(),v1.end());
    // Displaying the maximum element of heap 
    // using front() 
    cout << "The maximum element of heap after push is : "; 
    cout << v1.front() << endl; 
    // using pop_heap() to delete maximum element 
    pop_heap(v1.begin(),v1.end());
    v1.pop_back();
    // Displaying the maximum element of heap 
    // using front() 
    cout << "The maximum element of heap after pop is : "; 
    cout << v1.front() << endl;
    // Displaying heap elements  
    cout << "The heap elements are : "; 
    for(int &x : v1)
        cout<<x<<" ";
    cout<<endl;
    //sorting heap_using sort_heap()
    sort_heap(v1.begin(),v1.end());
    //Displaying heap Elements
    for(int &x : v1)
        cout<<x<<" ";
    cout<<endl;
    vector<int> v2 = {40, 30, 25, 35, 15};
    // Declaring heap iterator 
    vector<int>::iterator it1; 
    // Checking if container is heap 
    // using is_heap() 
    is_heap(v2.begin(),v2.end()) ?  cout<<"The container is heap" : cout<<"The container is not heap";
    cout<<endl;
    //using is_heap_until() to check position
    //till which container is heap
    auto it = is_heap_until(v2.begin(),v2.end());
    //Displaying the heap range element
    cout<<"The heap elements in container are : ";
    for(it1 = v2.begin(); it1!=it; it1++)
        cout<<*it1<<" ";
    
    return 0;

}