#include<iostream>
using namespace std;

/* Polymorphism
 * Overload: static(early) binding, complier period
 * virtual function: dynamic(late) binding, execute period
 *
 * base on: parent_class *ptr = &derived_object; 
 * only using pointer and refer can show poly and dynamic effect
 *
 * if there are virtual function in parent_class
 * the member function decision will put to execute period
 * and you can use parent_pointer to access derived_class virtual function. 
 */

//with virtual function class called Polymorphic class
class A
{
    public:
        virtual void show(){cout<<"AAAA"<<endl;}
        // Pure virtual function(= 0): derived_class must defined
        // virtual void haha() = 0;
};

class B : public A
{
    public:
        virtual void show(){cout<<"BBBB"<<endl;}
};

class C : public A
{
    public:
        virtual void show(){cout<<"CCCC"<<endl;}
};

int main(int argc, char **argv)
{
    A a; B b; C c;
    // static binding, not need virtual
    b.show();
    c.show();
    // dynamic binding, if no virtual show() = "AAAA"
    A *ptr = &b;
    ptr->show();
    ptr = &c;
    ptr->show();
    return 0;
}
