# Unscented Kalman Filter Project Starter Code
Self-Driving Car Engineer Nanodegree Program

In this project I implemented an Unscented Kalman Filter to estimate the state of a moving object of interest with noisy lidar and radar measurements. 

My *RMSE = [.0686, .0829, .3324, .2331]* on Dataset 1 are lower that the tolerance outlined in the project rubric. 

On the beginning I use first measurements to initialize the state vector (ukf.cpp, lines: 99-131) and covariance matrix (ukf.cpp, lines: 26-30).

Upon receiving a measurement after the first, the algorithm predicts object position to the current timestep and then update the prediction using the new measurement. This process contains five steps:
- Generate Sigma Points (ukf.cpp, lines: 308-342)
- Predict Sigma Points (ukf.cpp, lines: 344-396)
- Predict Mean and Covariance (ukf.cpp, lines: 398-429)
- Predict Measurement (ukf.cpp, lines: 186-241 for Lidar; lines: 249-304 for Radar)
- Update State (ukf.cpp, lines: 431-495)

I calculated NIS for Lidar and Radar on every step after updating state vector. Based on NIS I tuned process noise parameters std_a_ and std_yawdd_. I recieved appropriate RMSE with *std_a_ = 1.5* and *std_yawdd_ = 0.6*

To increased accuracy of the algorithm, I checked dividing by zero when px and px are equal (or close) to zero. Also I normalize angles when use atan2() method to convert data from radar to polar coordinates.
