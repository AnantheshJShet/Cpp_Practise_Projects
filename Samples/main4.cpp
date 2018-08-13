#include<iostream>

void f() throw (float){throw 10.0f;}

int main(){       
   try
   {               
      std::cout<<'A';                
      f();              
      std::cout<<'B';        
   } 
   catch(...)
   {                
      std::cout<<'C';
   }

   return 0;
}

/* ANS: 'AC' will be printed on the console. First 'A' will be printed. Then function 'f()' will be called which throws an exception of the type 'float'. The catch statement(here can catch any exception) will catch the floating exception and then print 'C'.