#include<iostream>
using namespace std;

class A{
   public:
      int data;
      virtual void find_average(){}
      virtual void find_median() {}
      virtual void find_mode() {}
};

int main()
{
   cout << sizeof(A) << endl;
   return 0;
}

/* ANS: Output would be '8'. 'data' is of type 'int',size 4 and vtable of size 4. When there is one or more virtual function in the class, compiler adds a virtaul pointer to the class. 
Virtual function is implemented as a pointer to a table of function addresses. No matter how many virtual functions we have, only one virtual pointer is 
all that is added. Virtual table would have an entry for each virtual function that occur across the class hierarchy, at run time the virtual pointer is 
moved accordingly to call the respective function.
*/