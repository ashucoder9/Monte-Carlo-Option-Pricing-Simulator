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
