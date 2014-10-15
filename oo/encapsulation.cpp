#include<iostream>
using namespace std;

class Demo
{
    public:
        // setter
        void setA(int n);
        void setB(int n);
        // getter
        int getA(){return a;};
        int getB(){return b;};
    private:
        // info hiding
        int a;
        int b;
};

void Demo::setA(int n)
{
    a = n;
}

void Demo::setB(int n)
{
    b = n;
}

int main(int argc, char **argv)
{
    Demo d;
    d.setA(55);
    d.setB(66);
    cout << d.getA() << d.getB() << endl;
    return 0;
}
