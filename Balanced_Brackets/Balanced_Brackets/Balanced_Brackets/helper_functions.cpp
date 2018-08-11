#include "helper_functions.h"
#include "typedefs.h"
#include "macros.h"

bool isWithinBounds(const uint32 var, const uint32 min, const uint32 max){
   bool retVal = TRUE;
   if((var < min) || (var > max))
   {
      retVal = FALSE;
   }

   return retVal;
}

bool isOpeningBracket(const char ch){
   bool retVal = FALSE;

   if((ch == '(') || (ch == '{') || (ch == '['))
   {
      retVal = TRUE;
   }

   return retVal;
}

bool isClosingBracket(const char ch){
   bool retVal = FALSE;

   if((ch == ')') || (ch == '}') || (ch == ']'))
   {
      retVal = TRUE;
   }

   return retVal;
}

bool isBracket(const char ch){
   bool retVal = FALSE;

   if((TRUE == isOpeningBracket(ch)) || (TRUE == isClosingBracket(ch))){
      retVal = TRUE;
   }

   return retVal;
}

bool seqContainsOnlyBrackets(const std::string seq){
   bool retVal = TRUE;   

   for(uint32 iSeq=0; iSeq<seq.length(); ++iSeq){
      char tChar = seq[iSeq];
      if(FALSE == isBracket(tChar)){
         retVal = FALSE;
         break;
      }
      else{
         /* Do nothing */
      }
   }
   
   return retVal;
}

bool areBracketsBalanced(const char open, const char close){
   bool retVal = FALSE;

   if(('(' == open) && (')' == close)){
      retVal = TRUE;
   }
   else if(('{' == open) && ('}' == close)){
      retVal = TRUE;
   }
   else if(('[' == open) && (']' == close)){
      retVal = TRUE;
   }
   else{
      /* Do nothing */
   }

   return retVal;
}