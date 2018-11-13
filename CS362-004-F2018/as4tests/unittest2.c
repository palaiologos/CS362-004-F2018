/******************************************************************************
 * Test of whoseTurn function for assignment 3.
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

    printf ("TESTING whoseTurn():\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    int r = initializeGame(numPlayer, k, seed, &G); // initialize a new 2 player game

    int tests_passed = 0;
    // 2 players.
    printf("We test a 2 player game:\n");
    printf("Should be player 0's turn. whoseTurn(): %d\n", whoseTurn(&G) );
    if (whoseTurn(&G) == 0) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Ending player 0's turn.\n");
    endTurn(&G);
    printf("Should be player 1's turn. whoseTurn(): %d\n", whoseTurn(&G) );
    if (whoseTurn(&G) == 1) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Ending player 1's turn.\n");
    endTurn(&G);
    printf("Should be player 0's turn again. whoseTurn(): %d\n", whoseTurn(&G) );
    if (whoseTurn(&G) == 0) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("2 player game test ended\n");
    printf("===================================================================\n");

    // 3 players.
    numPlayer = 3;
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new 3 player game

    printf("We test a 3 player game:\n");
    printf("Should be player 0's turn. whoseTurn(): %d\n", whoseTurn(&G) );
    if (whoseTurn(&G) == 0) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Ending player 0's turn.\n");
    endTurn(&G);
    printf("Should be player 1's turn. whoseTurn(): %d\n", whoseTurn(&G) );
    if (whoseTurn(&G) == 1) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Ending player 1's turn.\n");
    endTurn(&G);
    printf("Should be player 2's. whoseTurn(): %d\n", whoseTurn(&G) );
    if (whoseTurn(&G) == 2) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Ending player 2's turn.\n");
    endTurn(&G);
    printf("Should be player 0's turn again. whoseTurn(): %d\n", whoseTurn(&G) );
    if (whoseTurn(&G) == 0) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("3 player game test ended\n");
    printf("===================================================================\n");

    // 4 players.
    numPlayer = 4;
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new 4 player game

    printf("We test a 4 player game:\n");
    printf("Should be player 0's turn. whoseTurn(): %d\n", whoseTurn(&G) );
    if (whoseTurn(&G) == 0) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Ending player 0's turn.\n");
    endTurn(&G);
    printf("Should be player 1's turn. whoseTurn(): %d\n", whoseTurn(&G) );
    if (whoseTurn(&G) == 1) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Ending player 1's turn.\n");
    endTurn(&G);
    printf("Should be player 2's. whoseTurn(): %d\n", whoseTurn(&G) );
    if (whoseTurn(&G) == 2) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Ending player 2's turn.\n");
    endTurn(&G);
    printf("Should be player 3's turn. whoseTurn(): %d\n", whoseTurn(&G) );
    if (whoseTurn(&G) == 3) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Ending player 3's turn.\n");
    endTurn(&G);
    printf("Should be player 0's turn again. whoseTurn(): %d\n", whoseTurn(&G) );
    if (whoseTurn(&G) == 0) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("4 player game test ended\n");
    printf("===================================================================\n");
    int total_tests = 12;
    printf("===================================================================\n");
    printf("Tests passed: %d/%d\n", tests_passed, total_tests);
    printf("Unit Test 2: whoseTurn completed!\n");
    printf("===================================================================\n");

    return 0;
  }
