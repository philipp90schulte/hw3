/**
 * Statistik / Random script for mean and var calculation
 * Author: Philipp Schulte
 * Date: 17/11/2015
 * 
 * Description:
 * In this homework you will do some statistics of pseudo-random numbers. C++ provides random numbers via the command 
 * int rand() which is from cstdlib. It will output an integral value between 0 and RAND_MAX. RAND_MAX is an integer 
 * constant coming from cstdlib and the maximum possible random number.
 * 
 * Your assignment is:
 * 
 * Write a program which creates an array of N=100 random double values between 0 and 1.
 * The array is to be created in main, but filling it with random numbers should be done in an extra function. You will 
 * need pointers for this.
 * Calculate the expected value m and the variance v of your N random numbers x_i, where
 * 		m = 1/N * SUM(x_i) from zero to N-1  (where i is the array index)
 * 		v = 1/N * SUM((x_i - m)^2) from zero to N-1  (where i is the array index)
 * 		
 * 		Write one function which calculates m and v. Your function should return both values to the main program at the 
 * 		same time. Use references for this. The resulting values should be printed in the main program.
 * 
 */


#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;
//--------------------------------------------------
// plenty of lines here
//--------------------------------------------------
/**
 * Fill Array function
 * input parameter:
 * - Pointer p on the array to save the randum values
 * - Constant integer N which represents the number of random values
 */
void fillArrayWithRandom(double* p, const int N) {
	for (int i=0; i<=N-1; i++) {
		p[i] = ((double) rand() / (RAND_MAX));	
	}	
}


/**
 * Calculation function for the mean and var value.
 * Input parameters:
 * - Pointer p on the array to save the randum values
 * - Constant integer N which represents the number of random values
 * - References mean and var to send the calculated values back.
 * 
 * Description:
 * The function calculates the mean value first by an for loop.
 * The mean value is used in a second for loop to calculate the variance.
 * 
 */

void calcMeanAndVar(double* p, const int N, double& mean, double& var) {
	mean = 0;
	for (int i = 0; i <= N-1; i++)
		mean = mean + p[i];
	mean = mean / N;
	
	var = 0;
	for (int j = 0; j <= N-1; j++)
		var = var + ((p[j] - mean) * (p[j] - mean));
	var = var / N;
	
}

int main(){
   const int N = 100;
   double p[N];
   double mean, var;

   // Some lines here....
   // Fill the Arran with this function:
   fillArrayWithRandom(p, N);
   
   // Start the calculation with this function:
   calcMeanAndVar(p, N, mean, var);
   
   cout << "Mean = " << mean << endl;
   cout << "Variance = " << var << endl;

   return 0;
}
