/* John Williams
 * CS 362 F 2018
 * Random test for smithy card.
 */

// Headers.
#include "dominion.h"
#include "dominion_helpers.h"

// Libs.
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"


int main() {
  srand(time(NULL));

  int i, currentPlayer, numPlayers;
  // Seed random.
  int seed = (rand() % 1000) + 1000;

  struct gameState G;
  struct gameState testGameState;
  // Set kingdom deck.
  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};

  printf("===================================================================\n");
  printf ("RANDOMLY TESTING Smithy Card:\n");

  // Test 1,000 times with random players and card actions.
  for (i = 0; i <= 1000; i++) {
    // Keep track of passed tests.
    int tests_passed = 0;

    // Randomly set num of players.
    numPlayers = (rand() % 3) + 2;
    if (numPlayers < 1) {
      printf("Error in generating number of players\n");
    }

    // Randomly set which player will do an action.
    currentPlayer = (rand() % numPlayers);

    if (currentPlayer < 0) {
      printf("Error in selecting current player\n");
    }

    // Make the game state.
    int stateCheck = initializeGame(numPlayers, k, seed, &G);
    // Check it for accuracy.
    if (stateCheck != 0) {
      printf("Error in game state check\n");
    }

    // Set up the game state for the turn to take place.
    G.whoseTurn = currentPlayer;
    // Randomly set num of buys and actions and stuff to use.
    G.numActions = rand() % 5;
    G.numBuys = rand() % 5;
    G.coins = rand() % 5;
    // Set player's first card to be smithy.
    G.hand[currentPlayer][0] = smithy;
    // Randomly set these to something up to MAX_DECK and MAX_HAND in dominion.h
    G.deckCount[currentPlayer] = rand() % 500;
    G.discardCount[currentPlayer] = rand() % 500;

    // Copy gamestate over to test gamestate for comparisons later.
    memcpy(&testGameState, &G, sizeof(struct gameState) );

    // Then, play their card and measure the effects.
    // prototype:
    // int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
    cardEffect(smithy, 0, 0, 0, &G, 0, 0);

    // Then, check actions, discard and those related stats.
    // Gained two actions.
    if (G.numActions == testGameState.numActions + 2) {
      printf("Action count test passed\n");
      tests_passed++;
    }
    else {
      printf("Action count test failed\n");
    }

    // Discard a card.
    if (G.discardCount[currentPlayer] == testGameState.discardCount[currentPlayer] + 1) {
      printf("Discard count test passed\n");
      tests_passed++;
    }
    else {
      printf("Discard count test failed\n");
    }

    // Minus one deck.
    if (G.deckCount[currentPlayer] == testGameState.deckCount[currentPlayer] - 1) {
      printf("Deck count test passed\n");
      tests_passed++;
    }
    else {
      printf("Deck count test failed\n");
    }

    printf("Random test %d done. %d tests passed out of 3\n", i, tests_passed);

  }

  // End of main.
  return 0;
}
