/******************************************************************************
 * Test of card council_room for assignment 3.
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
  int seed = 1000;
  int numPlayer = 2;
  int thisPlayer = 0;
  int handPos = 0;
  int tests_passed = 0;
  // All the different types of cards.
  int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
  struct gameState G;

  printf("===================================================================\n");
  printf ("TESTING council_room Card:\n");

  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  int r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

  // Begin tests.
  // Get first player.
  thisPlayer = whoseTurn(&G);

  // Get the player's hand card count and number of buys before playing card.
  int playerBuys = G.numBuys;
  int playerHandCount = G.handCount[thisPlayer];
  // They should have the same number of cards.
  int otherPlayerHandCount = 0;

  // call council_room card.
  council_roomFunction(handPos, thisPlayer, &G);

  printf("Player %d:\n", thisPlayer);
  printf("Expected num of buys: %d, actual: %d\n", playerBuys + 1, G.numBuys);
  if (G.numBuys == playerBuys + 1) {
    printf("TEST PASSED\n");
    tests_passed++;
  }
  else {
    printf("TEST FAILED\n");
  }
  printf("Expected num of cards in hand: %d, actual: %d\n", playerHandCount + 4, G.handCount[thisPlayer]);
  if (G.handCount[thisPlayer] == playerHandCount + 4) {
    printf("TEST PASSED\n");
    tests_passed++;
  }
  else {
    printf("TEST FAILED\n");
  }

  // Check if other player drew a card as well.
  thisPlayer = 1;
  printf("Player %d:\n", thisPlayer);
  printf("Expected num of cards in hand: %d, actual: %d\n", otherPlayerHandCount + 1, G.handCount[thisPlayer]);
  if (G.handCount[thisPlayer] == otherPlayerHandCount + 1) {
    printf("TEST PASSED\n");
    tests_passed++;
  }
  else {
    printf("TEST FAILED\n");
  }

  printf("===================================================================\n");
  int total_tests = 3;
  printf("===================================================================\n");
  printf("Tests passed: %d/%d\n", tests_passed, total_tests);
  printf("Card Test 3: council_room completed!\n");
  printf("===================================================================\n");

  return 0;
}
