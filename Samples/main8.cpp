#include <iostream>

int main()
{
   double foo = 4.0;
   const float& bar = foo;
   foo += 2.0;
   std::cout << bar << std::endl;
   return 0;
}

/* ANS: Output would be '4.0'. Here foo is refered using a different datatype, so the compiler will create a temporary variable of the same type as the reference variable 'bar'.
The value of foo is assigned to this temporary variable. So if any change is done to foo, it will not be reflected in 'bar' because
'bar' is still refering to temporary variable */