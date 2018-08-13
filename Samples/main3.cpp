#include<iostream>
#include<string>
using namespace std;

template <typename T>

class Foo{
   T tVar;
   public:
      Foo() {};
      Foo(T t) : tVar(t) {}
};

class FooDerived : public Foo<std::string> {};

int main(){
   FooDerived d;
   return 0;
}

*****************************************OR***********************************************


#include<iostream>
#include<string>
using namespace std;

template <typename T>
class Foo{
    T tVar;
    public:
        Foo(T t) : tVar(t) {};
        T getVar() {return tVar;};
};

template <typename T>
class FooDerived : public Foo<T> {
    public:
       FooDerived(T t) : Foo<T>(t) {};
};

int main(){;
    FooDerived<int> i(20);
    FooDerived<string> s("Hello");
    cout<<i.getVar()<<endl<<s.getVar();
    return 0;
}

/* ANS: Either define an emty constructor or make the derived class a template and then use it for different datatypes */