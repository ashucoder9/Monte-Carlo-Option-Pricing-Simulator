#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#include <bits/stdc++.h>
#include "util.h"
using namespace std;

int32_t main(int argc, char **argv)
{
  fast_cin();
  ifstream fin;
  fin.open("data.csv");
  ofstream file;

  vector<string> row;
  string line, word;

  while (!fin.eof()) {
    row.clear();
    getline(fin, line);
    stringstream s(line);

    while (getline(s, word, ','))
      row.push_back(word);

    int cycle = stoi(row[0]);	// Number of Simulated Asset Paths
    double S = stod(row[1]);        // Underlying price
    double K = stod(row[2]);        // Strike price
    double r = stod(row[3]);        // Risk-free rate
    double v = stod(row[4]);        // Implied Volatility
    double T = stod(row[5]);        // Time till Expiry

    double call = monte_carlo_call_price(cycle, S, K, r, v, T);
    double put = monte_carlo_put_price(cycle, S, K, r, v, T);

    file.open("option_pricing.csv");
    file<< "Number of Paths: " <<","<< cycle<<std::endl;
    file<< "Strike:          " <<","<< K << std::endl;
    file<< "Risk-Free Rate:  " <<","<< r << std::endl;
    file<< "Volatility:      " <<","<< v << std::endl;
    file<< "Maturity:        " <<","<< T << std::endl;
    file<< "Call Price:      " <<","<< call << std::endl;
    file<< "Put Price:       " <<","<< put << std::endl;
  }

  return 0;
}