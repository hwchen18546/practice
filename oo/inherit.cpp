#include<iostream>
using namespace std;

class A
{
    public:
        void setA(int n){a = n;}
        int getA(){return a;}
        void overwrite(){cout << "AAAA" << endl;}
    private:
        int a;
};

class B : public A
{
    public:
        void setB(int n){b = n;}
        int getB(){return b;}
        void overwrite(){cout << "BBBB" << endl;}
    private:
        int b;
};

class C : private A
{
    public:
        void setC(int n){c = n;}
        int getC(){return c;}
        void setA2(int n){setA(n);}
        int getA2(){return getA();}
        // overwrite, besides from private to public
        void overwrite(){cout << "CCCC" << endl;}
    private:
        int c;
};

class D : public C
{
    public:
        /* setA(),getA became private in class C
         * void setA3(int n){setA(n);}
         * int getA3(){return getA();}
         *
         * If use "class C : protected A", you can access setA(),getA()
         */
};

int main(int argc, char** argv)
{
    B b;
    b.setA(55);
    b.setB(66);
    b.overwrite();
    cout << b.getA() << b.getB() << endl;
    C c;
    // c.setA(55); can't access, because setA(),getA() become private.
    c.setA2(11);
    c.setC(22);
    c.overwrite();
    cout << c.getA2() << c.getC() << endl;
    return 0;
}
