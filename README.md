#HW5

To build multiple binaries, must use "make hand" and "make dealer"

Optional Exercises for bonus points

B.3:

	For this code, we must verify multiple ways how the code is obtaining the correct results. 
First, we must make sure that all arguments passed in getopts are correct, by adding print statements with the passed argument in each instance.
This is crucial since we must verify that the correct arguments from the command line are being passed. 
Second, to determine whether the process is a success or failure, we must make sure we are generating a unique random number each time and making the right comparison. 
For instance, if the random generated number is 20 and the passed number by the user is 30, then it would be a success. 
	Then, we must keep calling the hand function to see if the number is continuously producing the expected results while continuously producing a random number.  
Also, to verify the code is obtaining correct results, you must input the correct options such as -p num num or a -p num -v num. Arguments must be in the correct format. 
Also, you must consider error checking when produce the correct result. For an example, if you type./dealer -c, it should display the correct usage. 
If your number of iterations are not numeric, display an error message. 
