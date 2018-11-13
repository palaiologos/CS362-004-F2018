CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: randomtestresults.out

randomtestresults.out: randomtestadventurer.c randomtestcard1.c dominion.c rngs.c

	echo "Result for running dominion RANDOM tests:" > randomtestresults.out

	echo "randomtestadventurer.c:" >> randomtestresults.out
	gcc -o randomtestadventurer dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer >> randomtestresults.out
	gcov randomtestadventurer.c >> randomtestresults.out

	echo "randomtestcard1.c:" >> randomtestresults.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> randomtestresults.out
	gcov randomtestcard1.c >> randomtestresults.out

	echo "randomtestcard2.c:" >> randomtestresults.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> randomtestresults.out
	gcov randomtestcard2.c >> randomtestresults.out

clean:
	rm randomtestresults.out

cleanall:
	rm randomtestresults.out randomtestadventurer randomtestcard1 randomtestcard2 *.gcda *.gcno *.gcov
