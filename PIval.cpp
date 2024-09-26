#include <iostream>     // For standard input-output stream
#include <random>       // For generating random numbers
#include <vector>       // For using the vector container
#include <chrono>       // For timing execution
#include <cmath>        // For mathematical functions like cos and sin

int main()
{
  // Start the timer for the entire script using chrono library for precise time measurement
  auto start = std::chrono::high_resolution_clock::now();

  // Define the limits for the square domain
  double xmin = -1.0; // Lower limit of x
  double xmax = 1.0;  // Upper limit of x
  double ymin = -1.0; // Lower limit of y
  double ymax = 1.0;  // Upper limit of y

  // Define the number of random sample points
  int N = 100; // You can change the number of points here

  // Output the value of N
  std::cout << "Number of sample points: " << N << std::endl;

  // Set up random number generation using Mersenne Twister 19937 generator
  std::random_device rd;  // Obtain a random number from hardware
  std::mt19937 gen(rd()); // Seed generator to ensure random values are produced
  std::uniform_real_distribution<> disx(xmin, xmax); // Uniform distribution for x
  std::uniform_real_distribution<> disy(ymin, ymax); // Uniform distribution for y

  // Vectors to store random points
  std::vector<double> x(N), y(N); // Initialize vectors to store x and y coordinates
  for(int i = 0; i < N; ++i)
    { // Loop N times to generate N random points
      x[i] = disx(gen); // Generate and store random x coordinate
      y[i] = disy(gen); // Generate and store random y coordinate
    }

  // Calculate the number of points inside the circle
  double Rad = 1.0; // Radius of the circle
  int Ncircle = 0;  // Counter for points inside the circle
  for(int i = 0; i < N; ++i)
    { // Loop through all points
      if(x[i]*x[i] + y[i]*y[i] <= Rad*Rad)
	{ // Check if the point is inside the circle
	  Ncircle++; // Increment counter if inside
	}
    }

  // Evaluate the value of PI using the ratio of points inside the circle to total points
  double PIval = 4.0 * Ncircle / N; // Formula derived from area ratio
  std::cout << "Estimated value of pi: " << PIval << std::endl; // Print the estimated value of PI

  // End the timer for calculating the value of PI and display the elapsed time
  auto end = std::chrono::high_resolution_clock::now(); // Mark end time
  std::chrono::duration<double> elapsed = end - start; // Compute elapsed time
  std::cout << "Total elapsed time: " << elapsed.count() << " seconds" << std::endl; // Print elapsed time

  return 0; // End of the program
}
