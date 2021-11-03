#include <iostream>
#include "my_vector.h"
using namespace std;

int main(int argc, char **argv)
{
    vectorClass<int> v;
    vectorClass<int> v2;
    vectorClass<char> v1;
    v.push_back(2);
    v.push_back(6);
    v.push_back(0);
    v.push_back(3);
    v.push_back(9);
    v1.push_back(71);
    v1.push_back(72);
    v1.push_back(73);
    v1.push_back(74);

    cout<<"Vector2 size: "<<v2.size_vector()<<endl;
    cout<<"Check empty: "<<v2.empty()<<endl;
    cout<<"Vector size: "<<v.size_vector()<<endl;
    cout<<"Vector max_size : "<<v2.max_size()<<endl;
    cout<<"Vector capacity "<<v2.getcapacity()<<endl;

    cout<<"Vector v elements :"; 
    v.print();
    cout<<"Vector v1 elements :"; 
    v1.print();
    v2=v;
    cout<<"v2 after copy vector:"; 
    v2.print();
    cout<<"v after copy vector:"; 
    v.print();
    v.insert(3,100);
    v1.insert(2,85);
    cout<<"\nAfter updating index"<<endl;
    cout<<"Vector elements of type int:"<<endl;
    v.print();
    cout<<"Vector elements of type char:"<<endl;
    v1.print();
    cout<<"Element at 2nd index of type int:" <<v.get(1)<<endl;
    cout<<"Element at 2nd index of type char:" <<v1.get(1)<<endl;

    v.pop_back();
    v1.pop_back();

    cout<<"\nAfter deleting last element:"<<endl;
    cout<<"Vector size of type int: "<<v.size_vector()<<endl;
    cout<<"Vector size of type char: "<<v1.size_vector()<<endl;
    cout<<"Vector capacity of type int: "<<v.getcapacity()<<endl;
    cout<<"Vector capacity of type char: "<<v1.getcapacity()<<endl;
    cout<<"Vector elements of type int:";
    v.print();
    cout<<"Vector elements of type char:";
    v1.print();

    v.erase(2);
    cout<<"Vector elements of type int after erase:";
    v.print();
    v.pop_front();
    cout<<"Vector elements of type int after pop_front:";
    v.print();
    v.push_front(5);
    cout<<"Vector elements of type int after push_front:";
    v.print();
    v.clear();
    cout<<"Vector elements of type int after clear:";
    v.print();

    return 0;
}