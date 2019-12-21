// ***
// *** You must modify this file
// ***

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// do not modify this function
static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

#ifdef TEST_DIVIDE
// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right decks
// Each pair divides the original deck into two non-overlapping decks and
// together they form the original deck.
//
// You can think of the left deck held by the left hand taking some
// cards (at least one) from the top of the original deck.
//
// The right deck is held by the right hand taking some (at least one)
// cards from the bottom of the original deck.
void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
int possible = origDeck.size - 1;
  int i = 0;
    while (i < possible)
    {
      leftDeck[i].size = i+1;
      rightDeck[i].size = possible -i;
      memcpy(leftDeck[i].cards,origDeck.cards,leftDeck[i].size);
      memcpy(rightDeck[i].cards,origDeck.cards+leftDeck[i].size,rightDeck[i].size);
      //printDeck(leftDeck[i]);
      //printDeck(rightDeck[i]);
      i ++;
    }
    
  //  for (int i1 = 0; i1 < count; i1++)
  //  {
      
    //  printf(rightDeck[i1].cards);
    
    //}
}
#endif

#ifdef TEST_INTERLEAVE

// Interleave two decks to generate all possible results.
//
// If the leftDeck is {'A'} and the right deck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right deck is {'3', '4'}, this
// function prints 
// 3 4 A 2
// 3 A 4 2
// A 3 4 2 
// 3 A 2 4 
// A 3 2 4 
// A 2 3 4 
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left deck, the left deck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left deck or the right deck
// runs out of cards. The remaining cards are added to the result.
// 
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removed for grading other parts of the
// program.
void helper(CardDeck newDeck, int new_index, CardDeck leftDeck, CardDeck rightDeck, int left_index, int right_index, int round)
{
if (left_index < leftDeck.size)
  {
    newDeck.cards[new_index] = leftDeck.cards[left_index];
    
    helper(newDeck, new_index+1, leftDeck, rightDeck, left_index+1, right_index);
  }
if (right_index < rightDeck.size)
  {
    newDeck.cards[new_index] = rightDeck.cards[right_index];
    
    helper(newDeck, new_index+1, leftDeck, rightDeck, left_index, right_index+1);
  }
if(new_index == newDeck.size)
  {
    printDeck(newDeck);
  }
}
void interleave(CardDeck leftDeck, CardDeck rightDeck,int round)
{
  CardDeck newDeck;
  newDeck.size = leftDeck.size+rightDeck.size;
  int right_index = 0;
  int left_index = 0;
  int new_index = 0;

  helper(newDeck,new_index, leftDeck, rightDeck, left_index, right_index);
  
}

#endif

#ifdef TEST_SHUFFLE
// The shuffle function has the following steps:

// 1. calculate the number of possible left and right decks. It is
// the number of cards - 1 because the left deck may have 1, 2,...,
// #cards - 1 cards.
//
// 2. allocate memory to store these possible pairs of left and right
// decks.
//
// 3. send each pair to the interleave function
//
// 4. release allocated memory
//
void shuffle(CardDeck origDeck, int round)
{
  for (int i = 0; i<round; i++)
  {
    int possible = origDeck.size - 1;
    CardDeck *left_deck = malloc(sizeof(CardDeck) * possible);
    CardDeck *right_deck = malloc(sizeof(CardDeck) * possible);
    //*left_deck.cards = malloc(sizeof(*left_deck.cards) * possible);
    //*right_deck.cards = malloc(sizeof(*right_deck.cards) * possible);
    divide(origDeck, left_deck,right_deck);
    for (int index = 0; index < possible; index++)
    {
      interleave(left_deck[index], right_deck[index],round);
    }
    free(left_deck);
    free(right_deck);
  }
}
#endif
