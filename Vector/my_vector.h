#include <iostream>
#include <string>

using namespace std;

template <typename T> class vectorClass
{
    T* arr;
    int capacity;
    int size;
public:
    vectorClass()
    {
        arr= new T[1];
        capacity = 1;
        size = 0;
    }
    ~vectorClass()
    {
        delete []arr;
    }  
    vectorClass(const vectorClass& rhs)
    {
        delete[] arr;
        size =rhs.size;
        capacity = rhs.capacity;
        arr = new T[capacity];
        for (int i = 0; i < size; i++)
            arr[i] = rhs.arr[i];
    } 
     vectorClass & operator=(const vectorClass& rhs)
    {
        if (this != &rhs)
        {
            delete[] arr;
            size =rhs.size;
            capacity = rhs.capacity;
            arr = new T[capacity];
            for (int i = 0; i < size; i++)
                arr[i] = rhs.arr[i];
        }
        return *this;
    } 

    bool empty()
    {
        if (!size == false)
        cout << "Vector is not empty"<< endl;
        else
        cout << "Vector is empty"<< endl;
    }
    
    int size_vector() {return size;}

    int max_size() {return 1073741820;}

    int getcapacity() {return capacity;}

    //fun to extract element at any index
    T get(int index)
    {
        if(index<size) return arr[index];
    }

    void clear()
    {
        if(!arr)
        {
            delete[] arr;
        }
        size = 0;
    }

    void insert(int index, T data)
    {
        if(size==capacity)
        {
            T* temp = new T[2 * capacity];

            //copying old array elements to new array
            for(int i=0;i<capacity;i++)
            {
                temp[i]=arr[i];
            }
        
            //deleting previous array
            delete[] arr;
            capacity *=2;
            arr= temp;
        }
        //move right
        for (int i=size;i> index; i--)
            arr[i] = arr[i -1];

        arr[index]= data;
        size++;    
    }
    void erase(int index)
    {
        for(int i=index;i<size-1;i++)
            arr[i]=arr[i+1];
        size--;
    }

    void push_back(T data)
    {
        if(size==capacity)
        {
            T* temp = new T[2* capacity];

            //copying old array elements to new array
            for(int i=0;i<capacity;i++)
            {
                temp[i]=arr[i];
            }
        
            //deleting previous array
            delete[] arr;
            capacity *=2;
            arr= temp;
        }

        arr[size]= data;
        size++;    
    }

    void pop_back() {size--;}

    void push_front(T data)
    {
        if(size==capacity)
        {
            T* temp = new T[2* capacity];

            //copying old array elements to new array
            for(int i=0;i<capacity;i++)
            {
                temp[i]=arr[i];
            }
        
            //deleting previous array
            delete[] arr;
            capacity *=2;
            arr = temp;
        }
        for(int i=size;i>0;i--)
            arr[i]=arr[i-1];

        arr[0]= data;
        size++;    
    }

    void pop_front()
    {
        //move left
        for(int i=0;i<size-1;i++)
            arr[i]=arr[i+1];

        size--;    
    }

    void print()
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


};