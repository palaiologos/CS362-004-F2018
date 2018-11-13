/******************************************************************************
 * Test of supplyCount function for assignment 3.
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

// Card num values from dominion.h
/*
 curse            0
 estate,          1
 duchy,           2
 province,        3
 copper,          4
 silver,          5
 gold,            6
 adventurer,      7
 council_room,    8
 feast,           9
 gardens,        10
 mine,           11
 remodel,        12
 smithy,         13
 village,        14
 baron,          15
 great_hall,     16
 minion,         17
 steward,        18
 tribute,        19
 ambassador,     20
 cutpurse,       21
 embargo,        22
 outpost,        23
 salvager,       24
 sea_hag,        25
 treasure_map    26
 */


// Define main variables for test run. Based on template on canvas.

int main() {
    int seed = 1000;
    int numPlayer = 2;
    // All the different types of cards.
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("TESTING supplyCount():\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    int r = initializeGame(numPlayer, k, seed, &G); // initialize a new game


    // Set of tests for 2 players, then 3.
    // 2 player.
    // This is the number of cards for a 2 player game.
    /*
    G.supplyCount[curse] = 10;
    G.supplyCount[adventurer] = 10;
    G.supplyCount[council_room] = 10;
    G.supplyCount[feast] = 10;
    G.supplyCount[gardens] = 10;
    G.supplyCount[mine] = 10;
    G.supplyCount[remodel] = 10;
    G.supplyCount[smithy] = 10;
    G.supplyCount[village] = 10;
    G.supplyCount[baron] = 10;
    G.supplyCount[great_hall] = 8;
    */

    int tests_passed = 0;

    // Test each one to verify supplyCount() is correct.
    printf("Test a 2 player game with the following kingdom cards:\n");
    printf("adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall\n");

    printf("Num of curse cards expected: 10, supplyCount(curse): %d\n", supplyCount(0, &G));
    if (supplyCount(0, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of adventurer cards expected: 10, supplyCount(adventurer): %d\n", supplyCount(7, &G));
    if (supplyCount(7, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of council_room cards expected: 10, supplyCount(council_room): %d\n", supplyCount(8, &G));
    if (supplyCount(8, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of feast cards expected: 10, supplyCount(feast): %d\n", supplyCount(9, &G));
    if (supplyCount(9, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of gardens cards expected: 10, supplyCount(gardens): %d\n", supplyCount(10, &G));
    if (supplyCount(10, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of mine cards expected: 10, supplyCount(mine): %d\n", supplyCount(11, &G));
    if (supplyCount(11, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of remodel cards expected: 10, supplyCount(remodel): %d\n", supplyCount(12, &G));
    if (supplyCount(12, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of smithy cards expected: 10, supplyCount(smithy): %d\n", supplyCount(13, &G));
    if (supplyCount(13, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of village cards expected: 10, supplyCount(village): %d\n", supplyCount(14, &G));
    if (supplyCount(14, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of baron cards expected: 10, supplyCount(baron): %d\n", supplyCount(15, &G));
    if (supplyCount(15, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of great_hall cards expected: 8, supplyCount(great_hall): %d\n", supplyCount(16, &G));
    if (supplyCount(16, &G) == 8) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }


    // Now test a 3 player game.
    printf("===================================================================\n");
    printf("Now we test a 3 player game with the following kingdom cards:\n");
    printf("adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall\n");

    // 3 player.
    // This is the number of cards for a 3 player game.
    /*
    G.supplyCount[curse] = 20;
    G.supplyCount[adventurer] = 10;
    G.supplyCount[council_room] = 10;
    G.supplyCount[feast] = 10;
    G.supplyCount[gardens] = 12;
    G.supplyCount[mine] = 10;
    G.supplyCount[remodel] = 10;
    G.supplyCount[smithy] = 10;
    G.supplyCount[village] = 10;
    G.supplyCount[baron] = 10;
    G.supplyCount[great_hall] = 12;
    */

    numPlayer = 3;
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new 3 player game

    printf("Num of curse cards expected: 20, supplyCount(curse): %d\n", supplyCount(0, &G));
    if (supplyCount(0, &G) == 20) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of adventurer cards expected: 10, supplyCount(adventurer): %d\n", supplyCount(7, &G));
    if (supplyCount(7, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of council_room cards expected: 10, supplyCount(council_room): %d\n", supplyCount(8, &G));
    if (supplyCount(8, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of feast cards expected: 10, supplyCount(feast): %d\n", supplyCount(9, &G));
    if (supplyCount(9, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of gardens cards expected: 12, supplyCount(gardens): %d\n", supplyCount(10, &G));
    if (supplyCount(10, &G) == 12) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of mine cards expected: 10, supplyCount(mine): %d\n", supplyCount(11, &G));
    if (supplyCount(11, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of remodel cards expected: 10, supplyCount(remodel): %d\n", supplyCount(12, &G));
    if (supplyCount(12, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of smithy cards expected: 10, supplyCount(smithy): %d\n", supplyCount(13, &G));
    if (supplyCount(13, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of village cards expected: 10, supplyCount(village): %d\n", supplyCount(14, &G));
    if (supplyCount(14, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of baron cards expected: 10, supplyCount(baron): %d\n", supplyCount(15, &G));
    if (supplyCount(15, &G) == 10) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    printf("Num of great_hall cards expected: 12, supplyCount(great_hall): %d\n", supplyCount(16, &G));
    if (supplyCount(16, &G) == 12) {
      printf("TEST PASSED\n");
      tests_passed++;
    }
    else {
      printf("TEST FAILED\n");
    }
    int total_tests = 22;
    printf("===================================================================\n");
    printf("Tests passed: %d/%d\n", tests_passed, total_tests);
    printf("Unit Test 1: supplyCount completed!\n");
    printf("===================================================================\n");


    return 0;
  }

  /*
  int supplyCount(int card, struct gameState *state) {
    return state->supplyCount[card];
  }
  */
