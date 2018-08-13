#include<iostream>

using namespace std;

class Someclass {
   public:
      int x;
   public:
      /* Assign xx to x */
      Someclass(int xx) : x(xx) {
         /* Do nothing */
      }
      Someclass(const Someclass& a) { 
         x = a.x ;
         x++;
      }
      void operator = (const Someclass& a1) { 
         x = a1.x ;
         x--;
      }
};

int main()
{
   Someclass a(4); /* Normal constructor is called */
   Someclass b = a; /* Copy contructor is called */
   cout << b.x << endl;
   b = a;
   cout << b.x << endl;

   return 0;
}

/* ANS: The output will be '5'. First the class 'a' is initialized in the format where the normal constructor will be called, assigning '4' to 'a.x'. 
Next the class 'b' is assigned 'a'. Here the copy constructor will be called, in which 'a.x' is assigned to 'b.x' and then 'b.x' is incremented. */ 