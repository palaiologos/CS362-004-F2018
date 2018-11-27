/******************************************************************************
 * Test of card Smithy for assignment 3.
 * John Williams
 * F 2018 CS 362
 *
 ******************************************************************************/

 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <assert.h>
 #include "rngs.h"
 #include <stdlib.h>

// Define main variables for test run. Based on template on canvas.

int main() {
  int currentPlayer = 0;
  int newCards = 0;
  int discarded = 1;
  int shuffledCards = 0;
  int seed = 1000;
  int numPlayer = 2;
  int handPos = 0;
  int thisPlayer = 0;
  int tests_passed = 0;
  // All the different types of cards.
  int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
  struct gameState G;
    printf("===================================================================\n");
  printf ("TESTING Smithy Card:\n");

  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  int r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

  smithyFunction(handPos, currentPlayer, &G);

  // Check counts
  printf("hand count = %d, expected = %d\n", G.handCount[thisPlayer], G.handCount[thisPlayer] + newCards);
  if (G.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards) {
    printf("TEST PASSED\n");
    tests_passed++;
  }
  else {
    printf("TEST FAILED\n");
  }

	printf("deck count = %d, expected = %d\n", G.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
  if (G.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards) {
    printf("TEST PASSED\n");
    tests_passed++;
  }
  else {
    printf("TEST FAILED\n");
  }

  // Then play the card for the other player after ending turn.
  endTurn(&G);
  thisPlayer++;
  smithyFunction(handPos, currentPlayer, &G);

  // Check counts again.
  printf("hand count = %d, expected = %d\n", G.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
  if (G.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) {
    printf("TEST PASSED\n");
    tests_passed++;
  }
  else {
    printf("TEST FAILED\n");
  }
	printf("deck count = %d, expected = %d\n", G.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
  if (G.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards) {
    printf("TEST PASSED\n");
    tests_passed++;
  }
  else {
    printf("TEST FAILED\n");
  }


  printf("===================================================================\n");
  int total_tests = 4;
  printf("===================================================================\n");
  printf("Tests passed: %d/%d\n", tests_passed, total_tests);
  printf("Card Test 1: Smithy completed!\n");
  printf("===================================================================\n");

  return 0;
}


/*
int smithy_card(struct gameState *state, int handPos)
{
  int currentPlayer = whoseTurn(state);
  //+3 Cards
  int i;
  for (i = 0; i < 3; i++)
  {
    drawCard(handPos, currentPlayer, state, 0); // BUG 2: discard instead of draw.
  }

  //discard card from hand
  drawCard(currentPlayer, state); // BUG 2: draw instead of discard.
  return 0;
}

// Great hall card.
int great_hall_card(struct gameState *state, int handPos)
{
  int currentPlayer = whoseTurn(state) + 1; // BUG 3: Gives the other player a card.
  //+1 Card
  drawCard(currentPlayer, state);

  //+1 Actions
  state->numActions++;

  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}
*/
