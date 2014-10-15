#include<iostream>
using namespace std;

class Demo
{
    public:
        // constructor & overload
        Demo(){cout << "contructor1" << endl;}
        Demo(int n1){cout << "contructor2" << endl;}
        // destructor : cannot be overloaded
        ~Demo(){cout << "destructor" << endl;}
        // setter
        void setA(int n){a=n;}
        void setB(int n){b=n;}
        // getter
        int getA(){return a;}
        int getB(){return b;}
    private:
        // info hiding
        int a;
        int b;
};

int main(int argc, char **argv)
{
    Demo d;
    d.setA(55);
    d.setB(66);
    cout << d.getA() << d.getB() << endl;
    Demo d2(1);
    return 0;
}
