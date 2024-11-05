#include <iostream>
using namespace std;

/// 1 classes and objects

class Student{  // student is a new data type
public:
    string name;
    int rollno;
    float cgpa;
    
    
};
int main() {

Student s1;  ;  // Student is class but s1 is a object 
s1.name="naveen";
s1.rollno=23;
s1.cgpa=9;

Student s2;
s2.name="naveen";
s2.rollno=23;
s2.cgpa=9;

cout<<s1.name;
}





/// 2 passing Object as a function
#include <iostream>
using namespace std;

class Student{  // student is a new data type
public:
    string name;
    int rollno;
    float cgpa;
    
    
};

class Car{
    public:
    int seat;
    int model;
    string name;
};


void print(Car c){
    cout<<c.name<<c.seat<<c.model<<" ";
}
int main() {

Car c1;
c1.name="naveen";
c1.model=19;
c1.seat=10;

Car c2;
c2.name="naveen";
c2.model=19;
c2.seat=10;


print(c1);
print(c2);
}





//// pass as an call by value
 class Student{         // student is a new data type
public:
    string name;
    int rollno;
    float cgpa;
    
    
};

class Car{
    public:
    int seat;
    int model;
    string name;
};


void print(Car c){
    cout<<c.name<<c.seat<<c.model<<" ";
}

void change(Car &c){
    c.name="AUdi";
}
int main() {

Car c1;
c1.name="naveen";
c1.model=19; 
c1.seat=10;

Car c2;
c2.name="naveen";
c2.model=19;
c2.seat=10;


print(c1);
change(c1);
print(c1);  // when we print it print same value due to pass by value
print(c2);
}



// comstrucotr
class Student{  
public:
    string name;
    int rollno;
    float cgpa;
    
    
    Student(string a,int b,float c){
        name=a;
        rollno=b;
        cgpa=c;
        
        
    }
    
    
};

int main(){
Student s1("Naveen",10,10);
cout<<s1.name<<s1.rollno;

}

// construcor partii
#include <iostream>
using namespace std;



class Student{  // student is a new data type
public:
    string name;
    int rollno;
    float cgpa;
    
    
    Student(){
        // Default cosntructor
    }
    
    
    Student(string a,int b,float c){
        name=a;
        rollno=b; // Paramterized constructor
        cgpa=c;
        
        
    }
    Student(int a,float b){
        rollno=a;
        cgpa=b;
    }
    
    
};

int main(){
// agar hmne ek br constructor bna dio to aur hm dusre object ko simply print krnaa chahte hai to bydefault constructor bnana imp hain
Student s1("Naveen",10,10);
Student s2(100,200.0);
s2.name="naveen";
s2.rollno=18;
Student s3=s1;  // deep copy
Student s4(s2);   // shallow copy
// if we want to change the name name does not change


cout<<s3.name<<s1.rollno;

}



// this keywords
class Cricket{
    public:
    string name;
    int runs;
    
    
    Cricket(string name,int runs){
        this->name=name;
        this->runs=runs;
    }
    
    // when we provide the same name as class names so it provides garbage values
    // this keywords help to overcome the problems
};

int main(){
    Cricket c1("virat",20000);
    Cricket c2("rohit",25000);
    
    cout<<c1.name<<c1.runs<<endl;
    cout<<c2.name<<c2.runs<<endl;
}


/// function inside classs


 class Cricket{
    public:
    string name;
    int runs;
    
    Cricket(string name,int runs){
        this->name=name;
        this->runs=runs;
    }
    
    void print(){
        cout<<this->name<<this->runs<<endl;
    }
    
    int matches(){
        return this->runs/55.2;
    }
};

int main(){
    Cricket c1("virat",20000);
    Cricket c2("rohit",25000);
    c1.print();
    c2.print();
    
    cout<<c1.matches();
}


/// object pointer
/// object pointer


 class Cricket{
    public:
    string name;
    int runs;
    
    Cricket(string name,int runs){
        this->name=name;
        this->runs=runs;
    }
};

void change(Cricket* c){
    c->runs=68000;  // (*c).avg=77.2;  // c must be pointer
}

int main(){
    Cricket c1("virat",20000);
    Cricket c2("rohit",25000);
  
  
     Cricket*p1=&c1;
     cout<<(*p1).runs;
     change(&c1);
     cout<<(*p1).runs;
}



/// dynamic allocation
int main(){
    Cricket c1("virat",20000);
    Cricket c2("rohit",25000);
    Cricket*c3=new Cricket("dhoni",20);
  
  
     Cricket*p1=&c1;
     cout<<(*p1).runs;
     change(&c1);
     cout<<(*p1).runs;
     
     int *ptr=new int(525);
     // we do not make a named variable but we store the address of that
     // run time m memory allocate hoti hain
     // store in heap memeory
     
     cout<<c3->name<<" ";
     
}



/// user defined data structure
// in vector when size==capacity we double the capacity of vector



class Vector{
    public:
    int size;
    int capacity;
    int *arr;
    
    Vector(){
        size=0;
        capacity=1;
        arr=new int[1];
    }
    
    
    void add(int data){
        if(size==capacity){
            capacity*=2;
            int *arr2=new int[capacity];
            for(int i=0;i<size;i++){
                arr2[i]=arr[i];
            }
            arr=arr2;
        }
        arr[size]=data;
        size++;
    }
    
    void pop(){
        if(size==0){
            return;
        }
        size--;
    }
    
    int getelement(int index){
        if(index>=size){
            cout<<"enter invalid";
        }
        return arr[index];
    }
    
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    
    
    
    
    
};

int main(){
    Vector v;
    v.add(5);
    cout<<"curr size of array is"<<v.size<<endl;
    cout<<"curr capacity of array is"<<v.capacity<<endl;
    v.print();
    
}


/// acccess modifiers
// getter and setter


class Student{
    public:
    int roll;
    string name;

    
    Student(int rno,string name,float marks){
        this->roll=rno;
        this->name=name;
        this->marks=marks;
    }
    
    int getmarks(){  // getter
        return marks;
    }
    
    void setmarks(float m){
        marks=m;
    }
    private:  // inko class k andar to hm use kr skte hain
     float marks;
};

int main(){
    Student s1(12,"naveen",65.12);
    cout<<s1.getmarks();
    s1.setmarks(98);
}

/// inheritance
//single level
class scooty{  // parent class
    public:
    int topspeed;
    float mileage;
    
    private:
    int bootspace;
};

class bike: public scooty{   // child class
    public:
    int gear;
};


int main(){
    bike b;
    b.topspeed=200;
    cout<<b.topspeed;
    
}


/// polymorphism- different form  
// mtlb hm kisi k bhai h papa hai 


// Function overloading- compile tim polymorphism
// overloading means different parameter ho aur ya phoro data type different ho
// ek nam ho differen kam ho
class Loading{
    public:
    void sum(int a,int b){
        cout<<a+b;
    }
    
    void sum(int a,int b,int c){
        cout<<a+b+c;
    }
};

int main(){
    Loading a;
    a.sum(5,8);
    a.sum(2,3,4);
}


#include <iostream>
using namespace std;

// operator overloading-complie time
// ''+ is an operator which pe5ftms differneltyy based on operands

#include <iostream>
using namespace std;

// Operator overloading for the '+' operator to add fractions
class Fraction {
    public:
    int num;
    int den;

    // Constructor to initialize numerator and denominator
    Fraction(int num, int den) {
        this->num = num;
        this->den = den;
    }

    // Function to display the fraction in a numerator/denominator format
    void display() {
        cout << num << "/" << den << endl;
    }

    // Overloaded '+' operator for adding two fractions
    Fraction operator+(Fraction f) { // we are on fraction 1 and we pass fraction 2
        int newnum = this->num * f.den + f.num * this->den;
        int newden = this->den * f.den;
        Fraction ans(newnum, newden);
        return ans;
    }
};

int main() {
    Fraction f1(1, 2); // 1/2
    Fraction f2(1, 3); // 1/3

    f1.display(); // Display fraction f1
    f2.display(); // Display fraction f2

    Fraction f3 = f1 + f2; // Add fractions f1 and f2
    f3.display(); // Display the result of the addition

    return 0;
}

// function overriding- run time p work krta hain
// uses vrtaual keyword it override the class


 



