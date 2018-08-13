#include<iostream>
using namespace std;

int main(){
   int x = 4, *y; /* x has value 4, y is a pointer to type int */
   y = &x; (*y)++; /* y points to x, value pointed to by y is incremented, which means x is incremented */
   printf("%d", *y); /* y which is still pointing to x is printed */
   return 0;
}

/* ANS: Output is '5'. Explanation in comments */