dealer: dealer.c
		cc dealer.c -o dealer
hand: hand.c
		cc -I$$HOME/local/gsl-2.5/include hand.c -o hand -lgsl -lgslcblas -L$$HOME/local/gsl-2.5/lib