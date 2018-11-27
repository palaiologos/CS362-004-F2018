/******************************************************************************
 * Test of card great_hall for assignment 3.
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
  int newCards = 0;
  int discarded = 1;
  int xtraCoins = 0;
  int shuffledCards = 0;
  int tests_passed = 0;

  int seed = 1000;
  int numPlayer = 2;
  int thisPlayer = 0;
  int handPos = 0;
  // All the different types of cards.
  int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
  struct gameState G;

  printf("===================================================================\n");
  printf ("TESTING great_hall Card:\n");

  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  int r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

  // Begin tests.
  // Player draws a card and gets another action.
  // Then they discard a card from their hand.
  printf("\n Player 1:\n");
  printf("hand count = %d, expected = %d\n", G.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
  if (G.handCount[thisPlayer] ==G.handCount[thisPlayer] + newCards - discarded) {
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

  // Call card function.
  great_hall_card(&G, handPos);

  // Should have another card and action.
  printf("hand count = %d, expected = %d\n", G.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
  if (G.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded) {
    printf("TEST PASSED\n");
    tests_passed++;
  }
  else {
    printf("TEST FAILED\n");
  }
  printf("deck count = %d, expected = %d\n", G.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
  if (G.deckCount[thisPlayer] ==G.deckCount[thisPlayer] - newCards + shuffledCards) {
    printf("TEST PASSED\n");
    tests_passed++;
  }
  else {
    printf("TEST FAILED\n");
  }

  // End turn and go to next player.
  endTurn(&G);
  thisPlayer = whoseTurn(&G);

  // Tests for player 2.
  printf("\n Player 2:\n");
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

  great_hall_card(&G, handPos);

  // Should have another card and action.
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
  int total_tests = 8;
  printf("===================================================================\n");
  printf("Tests passed: %d/%d\n", tests_passed, total_tests);
  printf("Card Test 4: great_hall completed!\n");
  printf("===================================================================\n");

  return 0;
}
