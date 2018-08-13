#include<iostream>
using namespace std;

class String{
   public:
      explicit String(char ch, int n = 1){} /* Explicit constructor: Copy initialization will not work but direct initialization will work */
      String(const char *p){} /* Normal constructor */
   private :
      void operator=(const char*){} /* works without this line too */
};

int main(){
   String x = "aaa"; /* This works because the default constructor is present */
   return 0;
}

/* ANS: The code compiles fine. The explicit constructor needs a 'char' and an 'int' but the other constructor takes in array of characters in other words string. The line 'String x = "aaa"' works because the normal constructor is called.