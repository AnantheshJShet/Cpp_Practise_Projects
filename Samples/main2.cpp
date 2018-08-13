#include<functional>
#include<iostream>
using namespace std;
#include<vector>

void my_sqr(int& a)
{
   a = a * a;
}

void apply_function(std::vector<int>& my_vector, const std::function<void(int&)>& my_func)
{
   for(unsigned i=0; i < my_vector.size(); i++)
   {
      my_func(my_vector.at(i));
   }
}

int main()
{
   int my_array[] = {10, 20, 30, 40, 50, 60};
   int my_array_size = sizeof(my_array)/sizeof(my_array[0]);
   vector<int> vect(my_array, my_array+my_array_size);

   apply_function(vect, my_sqr);

   for(int v: vect)
   {
      cout << v <<endl;
   }

   return 0;
}