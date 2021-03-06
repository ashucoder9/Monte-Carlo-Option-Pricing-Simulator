# Monte Carlo Option Pricing Simulator
A GUI Based executable app which takes input values from the end user and return CALL/PUT option prices. Currently working on scaling the app to take datasets as input and store resultant option pricing in a file.

A Brief Introduction
An option is a contract giving the buyer the right, but not the obligation, to buy or sell an underlying asset (a stock or index) at a specific price on or before a certain date.
Purchasing options can give you a hedge against losses, and in that sense, they can be used conservatively. 

In monte-carlo method, the main concept is to use randomness or repeated random sampling to solve problems that might be deterministic in principle, e.g., predicting options prices and hence the name Monte Carlo Options Pricing Simulator.

# Why Monte Carlo Model ?
_The below stated explanation will come in handy if you have a good grasp of probablity distribution and can understand the know-how of random variables._ 

Monte Carlo methods for evaluating the mathematical expectation of a random variable often involve generating many independent samples of the random variable and then taking the empirical average of the sample as a point estimate of the expectation. The accuracy of this method is proportional to σ/√n where σ2 denotes the variance of each sample, and n denotes the number of samples generated. 
The key advantage of the Monte-Carlo methods is that given the value of σ, the computational effort (roughly proportional to the number of samples) needed to achieve desired accuracy is independent of the dimension of the problem, i.e., if one thinks of the expectation as an integral, then this is independent of the dimension of the space where the integrand is defined.

However, we have PDE (Partial Differential Equation), an alternative approach to pricing options is to numerically solve the PDE satisfied by their price function. But what if the asset price dynamics is sufficiently complex, then in that case, a PDE characterizing the option price may even fail to exist.  Therefore, for complex options based on multi-dimensional underlying assets, the Monte-Carlo method provides a promising pricing approach.

The features of the options pricing dataset taken are mentioned in the data.csv file.


