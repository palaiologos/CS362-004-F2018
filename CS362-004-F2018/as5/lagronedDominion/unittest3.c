/******************************************************************************
 * Test of gainCard function for assignment 3.
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

/*
Player's enumerated values..
player 1: 0
player 2: 1
player 3: 2
player 4: 3
*/

int main() {
    int seed = 1000;
    int numPlayer = 2;
    // All the different types of cards.
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("TESTING gainCard():\n");

    // Set which player we are on.
    int player = 0;
    int tests_passed = 0;

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    int r = initializeGame(numPlayer, k, seed, &G); // initialize a new 2 player game

    // Begin tests.
    int i, j, b;
    // For each player in the game.
    for (i = 0; i < numPlayer; i++) {
      if (i == 0) {
        printf("\nTesting for player 1 first\n");
      }
      else {
        printf("\nTesting for player 2 now\n");
      }

      // For each card type.
      for (j = 7; j < 17; j++) {
        // For every toFlag value (0 - 2).
        for (b = 0; b < 3; b++) {
           // initialize a new game to reset card counts.
          r = initializeGame(numPlayer, k, seed, &G);
          int deckCount = G.deckCount[i];
          int handCount = G.handCount[i];
          int discardCount = G.discardCount[i];
          int cardSupply = G.supplyCount[j];

          printf("b = %d\n", b);

          if (gainCard(j, &G, b, i) == -1) {
            printf("Card not among selected decks in this game\n");
            j++;
          }
          else {
            printf("Card %d:\n", j);
            // Check each toFlag value.
            if (b == 1) {
              printf("Expected deck count: %d, actual: %d\n", deckCount + 1, G.deckCount[i]);
              if (G.deckCount[i] == deckCount + 1) {
                printf("TEST PASSED\n");
                tests_passed++;
              }
              else {
                printf("TEST FAILED\n");
              }
            }
            else if (b == 2) {
              printf("Expected hand count: %d, actual: %d\n", handCount + 1, G.handCount[i]);
              if (G.handCount[i] == handCount + 1) {
                printf("TEST PASSED\n");
                tests_passed++;
              }
              else {
                printf("TEST FAILED\n");
              }
            }
            else {
              printf("Expected discard count: %d, actual: %d\n", discardCount + 1, G.discardCount[i]);
              if (G.discardCount[i] == discardCount + 1) {
                printf("TEST PASSED\n");
                tests_passed++;
              }
              else {
                printf("TEST FAILED\n");
              }
            }

            // Check if the card has been decremented from supply properly.
            // BUG: This is not decrementing properly in tests.
            printf("Expected supply count: %d, actual: %d\n", cardSupply - 1, G.supplyCount[i]);
            if (G.supplyCount[i] == cardSupply - 1) {
              printf("TEST PASSED\n");
              tests_passed++;
            }
            else {
              printf("TEST FAILED\n");
            }
          } // toFlag if blocks.

        } // end toFlag loop.

      } // end card type loop.

    } // end player loop.

    printf("===================================================================\n");
    int total_tests = 120;
    printf("===================================================================\n");
    printf("Tests passed: %d/%d\n", tests_passed, total_tests);
    printf("Unit Test 3: gainCard completed!\n");
    printf("===================================================================\n");

    return 0;
  }
