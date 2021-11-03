//a) Create a struct StudentS (with attribute name (string), age(int) with below functions: contructor, copy constructor, copy assignment, destructor)
//b) Create a class StudentC (with attribute name,age) with below functions: contructor, copy constructor, copy assignment, destructor, getter/setter for name and age
//c) Create a vector <StudentC*> put to that n vector at least 3 members, make sure dont't have memory leak when exit program
//d) Create an array of StudentC using dynamic allocation (size = 3), after finishing, I want you change the name of the second member to "Bryon"
//e) Assume I want to have 3 group of student A, B, C each group have at least one member, please use pointer and multidimensional array to implement it

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

// a)
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
    virtual std::string call() //polymorphism
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

// b)
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

// for vector self-created
template <typename T> class _StudentC
{
    T* arr;
    int capacity;
    int size;
public:
    _StudentC()
    {
        arr= new T[1];
        capacity = 1;
        size = 0;
    }
    ~_StudentC()
    {
        delete []arr;
    }  
    _StudentC(const _StudentC& rhs)
    {
        delete[] arr;
        size =rhs.size;
        capacity = rhs.capacity;
        arr = new T[capacity];
        for (int i = 0; i < size; i++)
            arr[i] = rhs.arr[i];
    } 
     _StudentC & operator=(const _StudentC& rhs)
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
};

void show_group(StudentS * s)
{
    std::cout<<"Group "<<s->call()<<std::endl;
}

//vector 2D in-out
void input_vector(std::vector<std::vector<std::string>> &v, int rows, int columns=2)
{
    for (int i=0; i < rows; i++)
    {
        for (int j=0; j< columns; j++)
        {
            std::cout << "Input vector[" << i << "][" << j << "] = ";
            std::cin >> v.at(i).at(j);
        }
    }
}

void output_vector(std::vector<std::vector<std::string>> v)
{
    int rows = v.size();
    int columns = v.at(0).size();
    for (int i=0; i < rows; i++)
    {
        for (int j=0; j< columns; j++)
        {
            std::cout << std::setw(4) << v.at(i).at(j);
        }
        std::cout << std::endl;
    }
}

int main()
{
    // d)
    StudentC *array = new StudentC[3]
    {
        StudentC("a",20),
        StudentC("b",21),
        StudentC("c",22)
    };
    std::cout<<"---Before change second member---\n";
    for(int i=0; i<3; i++) std::cout<<(array[i]).getName()<<"\t"<<(array[i]).getAge()<<std::endl;
    (array+1)->setName("Bryon");
    std::cout<<"---After change second member---\n";
    for(int i=0; i<3; i++) std::cout<<(array[i]).getName()<<"\t"<<(array[i]).getAge()<<std::endl;
    delete[] array;
    array = nullptr;

    //polymorphism
    std::cout<<"---Group of Students---\n";
    StudentS A[2]=
    {
        StudentS("z",2),
        StudentS("x",3)
    };
    for (int i=0;i<2;i++) show_group(&A[i]);

    groupB B[1]=
    {
        groupB("v",5)
    };
    for (int i=0;i<1;i++) show_group(&B[i]);

    groupC C[3]=
    {
        groupC("c",1),
        groupC("b",8),
        groupC("n",9)
    };
    for (int i=0;i<3;i++) show_group(&C[i]);

    // c)
    std::cout<<"\n---------------Vector---------------\n";
    std::vector<std::vector<std::string>> v;
    v.resize(3);
    for (int i=0;i<3;i++) v.at(i).resize(2);
    input_vector(v,3);
    output_vector(v);

    std::vector<StudentC*> myVec;
    StudentC *s1 = new StudentC("nguyen van a",21);
    StudentC *s2 = new StudentC("nguyen van b",22);
    StudentC *s3 = new StudentC("nguyen van c",23);
    myVec.push_back(s1);
    myVec.push_back(s2);
    myVec.push_back(s3);
    for(auto i:myVec) std::cout<<i->getName()<<"\t"<<i->getAge()<<std::endl;
    delete s1;
    delete s2;
    delete s3;

    // e)
    std::cout<<"---------------Pointer and multidimensional array---------------\n";
    StudentC *aa1 = new StudentC("aa1",24);
    StudentC *aa2 = new StudentC("aa2",25);
    StudentC *aa3 = new StudentC("aa3",26);
    StudentC *AA = new StudentC[3] {*aa1,*aa2,*aa3};
    for (int i=0;i<3;i++) std::cout<<(AA[i]).getName()<<"\t"<<(AA[i]).getAge()<<std::endl;
    delete aa1;
    delete aa2;
    delete aa3;
    delete[] AA;

    std::cout<<"-----------------------------\n";
    StudentC *bb1 = new StudentC("bb1",27);
    StudentC *bb2 = new StudentC("bb2",28);
    StudentC *BB = new StudentC[2] {*bb1,*bb2};
    for (int i=0;i<2;i++) std::cout<<(BB[i]).getName()<<"\t"<<(BB[i]).getAge()<<std::endl;
    delete bb1;
    delete bb2;
    delete[] BB;

    std::cout<<"-----------------------------\n";
    StudentC *cc1 = new StudentC("cc1",29);
    StudentC *cc2 = new StudentC("cc2",30);
    StudentC *CC = new StudentC[2] {*cc1,*cc2};
    for (int i=0;i<2;i++) std::cout<<(CC[i]).getName()<<"\t"<<(CC[i]).getAge()<<std::endl;
    delete cc1;
    delete cc2;
    delete[] CC;

//Pointer and multidimensional array with 3 group - input keyboard
    std::string **p_A;
    p_A= new std::string*[2];

    for(int i=0;i<2;i++)
    {
        p_A[i] = new std::string[2];
    }
    std::cout<<"\nInput Students Group A (2 member): \n";
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            std::cin>>p_A[i][j];
        }
    }  
    std::cout<<"-----------------------------------------"<<std::endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            std::cout<<p_A[i][j]<<" ";
        }
        std::cout<<std::endl;
    }  
    for(int i=0;i<2;i++)
    {
        delete[] p_A[i];
    }
    delete[] p_A;
    p_A=nullptr;

    std::string **p_B;
    p_B= new std::string*[1];
    p_B[0] = new std::string[2];
    std::cout<<"\nInput Students Group B (1 member): \n";

    for(int j=0;j<2;j++)
    {
        std::cin>>p_B[0][j];
    } 
    std::cout<<"-----------------------------------------"<<std::endl;
    
    for(int j=0;j<2;j++)
    {
        std::cout<<p_B[0][j]<<" ";
    }
    std::cout<<std::endl;
    
    delete[] p_B[0];
    delete[] p_B;
    p_B=nullptr;

    std::string **p_C;
    p_C= new std::string*[3];

    for(int i=0;i<3;i++)
    {
        p_C[i] = new std::string[2];
    }
    std::cout<<"\nInput Students Group C (3 member): \n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            std::cin>>p_C[i][j];
        }
    }  
    std::cout<<"-----------------------------------------"<<std::endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            std::cout<<p_C[i][j]<<" ";
        }
        std::cout<<std::endl;
    }  
    for(int i=0;i<3;i++)
    {
        delete[] p_C[i];
    }
    delete[] p_C;
    p_C=nullptr;


    return 0;
}