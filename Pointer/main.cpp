//a) Create a struct StudentS (with attribute name (string), age(int) with below functions: contructor, copy constructor, copy assignment, destructor)
//b) Create a class StudentC (with attribute name,age) with below functions: contructor, copy constructor, copy assignment, destructor, getter/setter for name and age
//c) Create a vector <StudentC*> put to that n vector at least 3 members, make sure dont't have memory leak when exit program
//d) Create an array of StudentC using dynamic allocation (size = 3), after finishing, I want you change the name of the second member to "Bryon"
//e) Assume I want to have 3 group of student A, B, C each group have at least one member, please use pointer and multidimensional array to implement it

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

struct StudentS
{
    StudentS(std::string n,int a)
    {
        name = n;
        age = a;
    }
    StudentS(const StudentS &st)
    {
        name = st.name;
        age = st.age;
    }
    StudentS & operator=(const StudentS &st)
    {
        if (this != &st)
        {
            name = st.name;
            age = st.age;
        }
        return *this;
    }
    virtual std::string call()
    {
        return "AAAAAAAAAAAAAA";
    }
    ~StudentS(){}
    std::string name;
    int age;
};

struct groupB: public StudentS
{
    groupB(std::string n, int a):StudentS(n,a)
    {}
    std::string call()
    {
        return "BBBBBBBBBBBBBBBBB";
    }
}; 

struct groupC: public StudentS
{
    groupC(std::string n, int a):StudentS(n,a)
    {}
    std::string call()
    {
        return "CCCCCCCCCCCCCCCCC";
    }
}; 

class StudentC {
private:
    std::string name;
private:
    int age;

public:
    std::string getName()
    {
        return this->name;
    }

public:
    void setName(std::string name)
    {
        this->name = name;
    }

public:
    int getAge()
    {
        return this->age;
    }

public:
    void setAge(int age)
    {
        this->age = age;
    }

    StudentC(std::string n,int a)
    {
        name = n;
        age = a;
    }
    StudentC(const StudentC &st)
    {
        name = st.name;
        age = st.age;
    }
    StudentC & operator=(const StudentC &st)
    {
        if (this != &st)
        {
            name = st.name;
            age = st.age;
        }
        return *this;
    }
    ~StudentC(){}
};

int main()
{
    return 0;
}