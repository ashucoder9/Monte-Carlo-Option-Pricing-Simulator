# Monte Carlo Option Pricing Simulator
## Description:
A GUI Based executable app which takes input values from the end user and return CALL/PUT option prices. Currently working on scaling the app to take datasets as input and store resultant option pricing in a file.

## A Brief Introduction:
An option is a contract giving the buyer the right, but not the obligation, to buy or sell an underlying asset (a stock or index) at a specific price on or before a certain date.
Purchasing options can give you a hedge against losses, and in that sense, they can be used conservatively. 

In monte-carlo method, the main concept is to use randomness or repeated random sampling to solve problems that might be deterministic in principle, e.g., predicting options prices and hence the name Monte Carlo Options Pricing Simulator.


## How to Run: 
1. Open your computer's command prompt/terminal
2. Type 'git clone https://github.com/kkaroleski2021/Monte-Carlo-Option-Pricing-Simulator.git'
3. Navigate to the folder containing the simulated dataset ( cd /Monte-Carlo-Option-Pricing-Simulator/Simulation/ )
4. Run the main program by typing in the command 'start main.exe'
5. The program should now run! Make sure you have the proper libraries installed.

## Dataset Formatting:
The user will input six different values:
- Number of Simulated Asset Paths: The number of different possible outcomes you want to analyze.
- Underlying price: Intial price of the asset - current market price.
- Strike price: 
- Risk-free rate: 
- Implied Volatility: Constant and equal to the implied volatility provided by NSE.
- Time till Expiry: Represents the market's expectations for future price volatility.
  > Higher implied volatility implies a greater expected price fluctuation -> generally results in higher option prices.
  > Conversely, a lower implied volatility suggests lower expected price fluctuation -> generally results in lower option prices.
These values can be inputted through an excel (.csv) file
The output will go to option_pricing.csv, and will contain the same values the user inputted, in addition to the calculated call and put prices.
** NOTE: ** Data is entered left -> right, where each row represents an individual dataset, and each column one of the six input-categories.


### Why Monte Carlo Model?
_The below stated explanation will come in handy if you have a good grasp of probablity distribution and can understand the know-how of random variables._ 

The Monte Carlo simulation allows us to predict the possible outcomes of an uncertain event. Mathematicians and programs use this method to both analyze past data, and predict the range of future outcomes; in essence, the simulation is most useful when it is too difficult to use other approaches to predict variable outcomes.

Monte Carlo methods for evaluating the mathematical expectation of a random variable often involve generating many independent samples of the random variable and then taking the empirical average of the sample as a point estimate of the expectation. The accuracy of this method is proportional to σ/√n where σ2 denotes the variance of each sample, and n denotes the number of samples generated. 
The key advantage of the Monte-Carlo methods is that given the value of σ, the computational effort (roughly proportional to the number of samples) needed to achieve desired accuracy is independent of the dimension of the problem, i.e., if one thinks of the expectation as an integral, then this is independent of the dimension of the space where the integrand is defined.

However, we have PDE (Partial Differential Equation), an alternative approach to pricing options is to numerically solve the PDE satisfied by their price function. But what if the asset price dynamics is sufficiently complex, then in that case, a PDE characterizing the option price may even fail to exist.  Therefore, for complex options based on multi-dimensional underlying assets, the Monte-Carlo method provides a promising pricing approach.


