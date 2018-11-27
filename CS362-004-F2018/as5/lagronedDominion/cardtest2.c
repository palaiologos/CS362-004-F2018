/******************************************************************************
 * Test of card adventurer for assignment 3.
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
  int tests_passed = 0;
  // All the different types of cards.
  int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
  struct gameState G;

  printf("===================================================================\n");
  printf ("TESTING adventurer Card:\n");

  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  int r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

    // Begin tests.

  // Show whose turn it is.
  printf("Current player: %d\n", whoseTurn(&G) );
  // That player then plays the adventurer card.
  adventurerFunction(thisPlayer, &G);

  // Make sure the player only took two treasure cards.
  int i;
  int coppers = 0;
  int silvers = 0;
  int golds = 0;
  //reset coin count
  int gameCoins = updateCoins(thisPlayer, &G, 0);
  G.coins = 0;
  //add coins for each Treasure card in player's hand
  for (i = 0; i < G.handCount[thisPlayer]; i++)
  {
      if (G.hand[thisPlayer][i] == copper)
  	{
  	  G.coins += 1;
      coppers++;
  	}
        else if (G.hand[thisPlayer][i] == silver)
  	{
  	  G.coins += 2;
      silvers++;
  	}
        else if (G.hand[thisPlayer][i] == gold)
  	{
  	  G.coins += 3;
      golds++;
  	}
  }
  printf("Player should have %d coins. Actual: gold: %d, silver: %d, copper: %d\n", G.coins, golds, silvers, coppers );
  if (G.coins == 6) {
    printf("TEST PASSED\n");
    tests_passed++;
  }
  else {
    printf("TEST FAILED\n");
  }
  printf("Player drew %d cards\n", G.handCount[thisPlayer] - 2 ); // minus the 2 treasures.

  //----------------------------------------------------------------------------

  printf("\n Next player\'s turn\n");
  endTurn(&G);
  // Show whose turn it is.
  thisPlayer = whoseTurn(&G);
  printf("Current player: %d\n", whoseTurn(&G) );

  // That player then plays the adventurer card.
  adventurerFunction(thisPlayer, &G);

  //reset coin count
  gameCoins = updateCoins(thisPlayer, &G, 0);
  G.coins = 0;
  coppers = 0;
  silvers = 0;
  golds = 0;
  //add coins for each Treasure card in player's hand
  for (i = 0; i < G.handCount[thisPlayer]; i++)
  {
      if (G.hand[thisPlayer][i] == copper)
  	{
  	  G.coins += 1;
  	}
        else if (G.hand[thisPlayer][i] == silver)
  	{
  	  G.coins += 2;
  	}
        else if (G.hand[thisPlayer][i] == gold)
  	{
  	  G.coins += 3;
  	}
  }

  printf("Player should have %d coins. Actual: gold: %d, silver: %d, copper: %d\n", G.coins, golds, silvers, coppers );
  if (G.coins == 6) {
    printf("TEST PASSED\n");
    tests_passed++;
  }
  else {
    printf("TEST FAILED\n");
  }
  printf("Player drew %d cards\n", G.handCount[thisPlayer] - 2 ); // minus the 2 treasures.

  printf("===================================================================\n");
  int total_tests = 2;
  printf("===================================================================\n");
  printf("Tests passed: %d/%d\n", tests_passed, total_tests);
  printf("Card Test 2: adventurer completed!\n");
  printf("===================================================================\n");

  return 0;
}
