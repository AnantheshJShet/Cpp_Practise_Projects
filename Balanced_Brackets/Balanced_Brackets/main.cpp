/* Standard header files */
#include<iostream>
#include<vector>
#include<string>
#include<stack>

/* User defined headerfiles */
#include"typedefs.h"
#include"macros.h"
#include"helper_functions.h"

using namespace std;

/* Static function prototypes */
static void isSequenceBalanced(string seq);

int main(){
   uint32 num_of_sequences = 0;
   std::vector<std::string> vSequence; /* vector of sequences */

   /* Request the user for number of sequences */
   /*cout<<"Enter the number of sequences: ";*/
   cin>>num_of_sequences;

   /* Bounds checking of number of sequences */
   if(FALSE == isWithinBounds(num_of_sequences, 1u, MAX_NUM_OF_SEQUENCES)){
      cout<<"ERROR: Number of sequences(n) out of bounds. Constraint: 1 <= n <= 10^3. Exiting!!"<<endl;
      return 0;
   }

   /* Request the user for the sequence */
   for(uint32 iStr=0; iStr<num_of_sequences; iStr++){
      std::string inpSequence;
      /*cout<<"Enter string "<<iStr+1<<": "; */
      cin>>inpSequence; /* using 'cin' assuming that the user will enter a sequence without space */

      uint32 sequence_length = strlen(inpSequence.c_str());
      /* Bounds checking of sequence length */
      if(TRUE == isWithinBounds(sequence_length, 1u, MAX_LENGTH_OF_SEQUENCE)){
         /* Check whether the sequence contains only brackets */
         if(TRUE == seqContainsOnlyBrackets(inpSequence)){
            /* Store only valid sequence */
            vSequence.push_back(inpSequence);
         }
         else
         {
            cout<<"ERROR: Sequence should contains only brackets: (, ), {, }, [, or ]. Discarding this sequence!!"<<endl;
         }
      }
      else{
         cout<<"ERROR: Length of sequence(s_len) out of bounds. Constraint: 1 <= s_len <= 10^3. Discarding this sequence!!"<<endl;
      }
   }

   /* Run through the sequences in the vector */
   for(std::vector<std::string>::iterator it = vSequence.begin(); it != vSequence.end(); ++it){
      /* Check if the sequence is balanced */
      isSequenceBalanced(*it);
   }

   return 0;
}

static void isSequenceBalanced(string seq){
   uint32 seq_len = seq.length();

   /* This function will never be called if sequence length is less than 1.
   If the sequence length is 1, then it is unbalanced. If it is 2, then the 
   sequence could be balanced or unbalanced. If it is , then it is unbalanced.
   If it is 4, then the sequence could be balanced or unbalanced. */

   /* Check if sequence length is odd or even. If it is odd, then it is definitely unbalanced */
   if(0 != (seq_len%2)){
      cout<<"NO"<<endl;
   }
   /* If it is even, the sequence could be balanced or unbalanced */
   else{
      /* extract the first and last characters of the string */
      char firstChar = seq[0];
      char lastChar = seq[seq_len-1];
      
      /* If the first and last characters of the sequence are balanced, then check if the sub-string 
      in between is also balanced. */
      if(TRUE == areBracketsBalanced(firstChar, lastChar)){
         /* If the sequence was only of two characters then it is balanced */
         if(2 == seq_len){
            cout<<"YES"<<endl;
         }
         else{
            /* If the sequence was of more than 2 characters then strip the first and last
            characters of the string and check if the sub-string is balanced */
            seq = seq.substr(1, seq.length()-2);
            isSequenceBalanced(seq);
         }
      }
      /* If the first and last characters of the sequence are not balanced, then the sequence is unbalanced */
      else{
         cout<<"NO"<<endl;
      }
   }
}