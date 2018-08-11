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
static bool isSequenceBalanced(string seq);

int main(){
   uint32 num_of_sequences = 0;
   std::vector<std::string> vSequence; /* vector of sequences */

   /* Request the user for number of sequences */
   cout<<"Enter the number of sequences: ";
   cin>>num_of_sequences;

   /* Bounds checking of number of sequences */
   if(FALSE == isWithinBounds(num_of_sequences, 1u, MAX_NUM_OF_SEQUENCES)){
      cout<<"ERROR: Number of sequences(n) out of bounds. Constraint: 1 <= n <= 10^3. Exiting!!"<<endl;
      return 0;
   }

   /* Request the user for the sequence */
   for(uint32 iStr=0; iStr<num_of_sequences; iStr++){
      std::string inpSequence;
      cout<<"Enter string "<<iStr+1<<": ";
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
      if(TRUE == isSequenceBalanced(*it)){
         cout<<"YES"<<endl;
      }
      else{
         cout<<"NO"<<endl;
      }
   }

   return 0;
}

static bool isSequenceBalanced(string seq){
   bool retVal = TRUE;
   stack<char> charStack; /* Character stack to hold characters */

   /* Run through the characters in the sequence */
   for(uint32 iSeq=0; iSeq<seq.length(); ++iSeq){
      char tChar = seq[iSeq];

      /* Check if the character is one of the opening brackets */
      if(TRUE == isOpeningBracket(tChar)){
         /* push the character to the stack */
         charStack.push(tChar);
      }
      /* Check if the character is one of the closing brackets */
      else if(TRUE == isClosingBracket(tChar)){
         /* Now check if the stack is empty. If TRUE, it means we have a closing bracket in the sequence 
         without an opening bracket and hence the sequence is unbalanced */
         if(TRUE == charStack.empty()){
            retVal = FALSE;
            break;
         }
         /* If the stack is not empty, then comapre the current closing bracket with the last inserted
         opening bracket in the stack. If they don't match then the sequence is unbalanced  */
         else if(FALSE == areBracketsBalanced(charStack.top(), tChar)){
            retVal = FALSE;
            break;
         }
         /* If the stack is not empty and if the current closing bracket and the last inserted
         opening bracket in the stack matchs, then remove the last inserted opening bracket from
         the stack */
         else{
            charStack.pop();
         }
      }
      else{
         /* Do nothing */
      }
   }

   /* Even after running through the whole sequence, if the stack is not empty, then there
   is an opening bracket without a matching closing bracket and hence the sequence is 
   unbalanced */
   if(FALSE == charStack.empty()){
      retVal = FALSE;
   }
   else{
      /* Do nothing */
   }

   return retVal;
}