#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#include <bits/stdc++.h>
using namespace std;

double randomizer() {
  double x = 0.0;
  double y = 0.0;
  double e = 0.0;

  do {
    x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
    y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
    e = x * x + y * y;
  } while (e >= 1.0);

  return x * sqrt(-2 * log(e) / e);
}

// Pricing a European vanilla call option with Monte Carlo
double monte_carlo_call_price(const int& cycle, const double& S, const double& K, const double& r, const double& v, const double& T) {
  double S_adjust = S * exp(T * (r - 0.5 * v * v));
  double S_cur = 0.0;
  double sum = 0.0;

  for (int i = 0; i < cycle; i++) {
    double gauss_bm = randomizer();
    S_cur = S_adjust * exp(sqrt(v * v * T) * gauss_bm);
    sum += std::max(S_cur - K, 0.0);
  }

  return (sum / static_cast<double>(cycle)) * exp(-r * T);
}

// Pricing a European vanilla put option with Monte Carlo
double monte_carlo_put_price(const int& cycle, const double& S, const double& K, const double& r, const double& v, const double& T) {
  double S_adjust = S * exp(T * (r - 0.5 * v * v));
  double S_cur = 0.0;
  double sum = 0.0;

  for (int i = 0; i < cycle; i++) {
    double gauss_bm = randomizer();
    S_cur = S_adjust * exp(sqrt(v * v * T) * gauss_bm);
    sum += std::max(K - S_cur, 0.0);
  }

  return (sum / static_cast<double>(cycle)) * exp(-r * T);
}

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

    int cycle = stoi(row[0]);       // Number of Simulated Asset Paths
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
