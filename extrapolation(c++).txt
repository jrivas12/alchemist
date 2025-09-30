#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the linear regression parameters (slope and y-intercept)
void calculateLinearRegression(const vector<int>& sales, double& slope, double& yIntercept) {
  int n = sales.size();
  double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

  // Calculate the sums needed for linear regression
  for (int i = 0; i < n; i++) {
    sumX += i;      // x-values (month)
    sumY += sales[i]; // y-values (sales)
    sumXY += i * sales[i]; // x * y
    sumX2 += i * i; // x^2
  }

  // Calculate the slope (m) and y-intercept (b) of the linear regression line (y = mx + b)
  slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
  yIntercept = (sumY - slope * sumX) / n;
}

int main() {
  // Create a vector to store the sales data.
  vector<int> sales;
  sales.push_back(10);
  sales.push_back(12);
  sales.push_back(14);

  // Fit a straight line (linear regression) to the data points.
  double slope, yIntercept;
  calculateLinearRegression(sales, slope, yIntercept);

  // Predict the number of sales next month (assuming the next month is month 3).
  int nextMonth = 3;
  int predictedSales = slope * nextMonth + yIntercept;

  // Print the linear regression parameters and the predicted sales.
  cout << "Linear Regression Parameters:" << endl;
  cout << "Slope (m): " << slope << endl;
  cout << "Y-Intercept (b): " << yIntercept << endl;
  cout << "Predicted sales for month " << nextMonth << ": " << predictedSales << endl;

  return 0;
}
