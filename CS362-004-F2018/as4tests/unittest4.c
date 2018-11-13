/******************************************************************************
 * Test of discardCard function for assignment 3.
 * John Williams
 * F 2018 CS 362
 *
 ******************************************************************************/

#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// Define main variables for test run. Based on template on canvas.

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int thisPlayer = 0;
    // All the different types of cards.
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    int i, j;
    int tests_passed = 0;

    printf ("TESTING discardCard():\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    int r = initializeGame(numPlayer, k, seed, &G); // initialize a new 2 player game

    // Begin tests.
    // Set up the player's hand.
    G.hand[thisPlayer][0] = steward;
		G.hand[thisPlayer][1] = copper;
		G.hand[thisPlayer][2] = duchy;
		G.hand[thisPlayer][3] = estate;
		G.hand[thisPlayer][4] = feast;

    // Player's hands are full. Now we discard them.
    // for each player.
    for (i = 0; i < 1; i++) {
      int handPos = G.handCount[i] - 1;
      int playerHandCount = 5;

      // Discard entire hand (5 cards)
      for (j = 0; j < 5; j++) {
        printf("Player %d hand count: %d.\n", i, playerHandCount);
        discardCard(handPos, i, &G, 0);
        handPos--;
        playerHandCount--;
        printf("Expected hand count: %d, Actual: %d.\n", playerHandCount, G.handCount[i]);
        if (G.handCount[i] == playerHandCount) {
          printf("TEST PASSED\n");
          tests_passed++;
        }
        else {
          printf("TEST FAILED\n");
        }
      }
    }

    printf("===================================================================\n");
    int total_tests = 5;
    printf("===================================================================\n");
    printf("Tests passed: %d/%d\n", tests_passed, total_tests);
    printf("Unit Test 3: discardCard completed!\n");
    printf("===================================================================\n");

    return 0;
  }
