#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
using namespace std;

// Std. Probability density function
double norm_pdf(const double& x) {
    return (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x);
}

double norm_cdf(const double& x) {
    double k = 1.0/(1.0 + 0.2316419*x);
    double k_sum = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937 + k*(-1.821255978 + 1.330274429*k))));

    if (x >= 0.0) {
        return (1.0 - (1.0/(pow(2*M_PI,0.5)))*exp(-0.5*x*x) * k_sum);
    } else {
        return 1.0 - norm_cdf(-x);
    }
}

double d_j(const int& j, const double& S, const double& K, const double& r, const double& v, const double& T) {
    return (log(S/K) + (r + (pow(-1,j-1))*0.5*v*v)*T)/(v*(pow(T,0.5)));
}

double call_price(const double& S, const double& K, const double& r, const double& v, const double& T) {
    return S * norm_cdf(d_j(1, S, K, r, v, T))-K*exp(-r*T) * norm_cdf(d_j(2, S, K, r, v, T));
}

double put_price(const double& S, const double& K, const double& r, const double& v, const double& T) {
    return -S*norm_cdf(-d_j(1, S, K, r, v, T))+K*exp(-r*T) * norm_cdf(-d_j(2, S, K, r, v, T));
}

int main(int argc, char **argv) {
  fast_cin();
  ifstream fin;
  fin.open("data_bsmodel.csv");
  ofstream file;

  vector<string> row;
  string line, word;

  while (!fin.eof()) {
    row.clear();
    getline(fin, line);
    stringstream s(line);

    while (getline(s, word, ','))
      row.push_back(word);

    double S = stod(row[1]);        // Underlying price
    double K = stod(row[2]);        // Strike price
    double r = stod(row[3]);        // Risk-free rate
    double v = stod(row[4]);        // Implied Volatility
    double T = stod(row[5]);        // Time till Expiry
    
    double call = call_price(S, K, r, v, T);
    double put = put_price(S, K, r, v, T);

    file.open("option_pricing_bsmodel.csv");
    
    file<< "Strike:          " <<","<< K << endl;
    file<< "Risk-Free Rate:  " <<","<< r << endl;
    file<< "Volatility:      " <<","<< v << endl;
    file<< "Maturity:        " <<","<< T << endl;
    
    file<< "Call Price:      " <<","<< call << endl;
    file<< "Put Price:       " <<","<< put << endl;

    return 0;
}
