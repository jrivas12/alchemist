#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Create a vector to store the sales data.
  vector<int> sales;
  sales.push_back(10);
  sales.push_back(12);
  sales.push_back(14);

  // Fit a straight line to the data points.
  double slope = (sales[2] - sales[0]) / (2 - 0);
  double yIntercept = sales[0] - slope * 0;

  // Predict the number of sales next month.
  int predictedSales = slope * 3 + yIntercept;

  // Print the predicted sales.
  cout << "Predicted sales: " << predictedSales << endl;

  return 0;
} 