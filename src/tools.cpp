#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
    VectorXd rmse(4);
    rmse << 0,0,0,0;

    // Check the validity of the following inputs:
    //  * the estimation vector size should not be zero
    //  * the estimation vector size should equal ground truth vector size

    if (estimations.size() == 0 || ground_truth.size() == 0
        || estimations.size() != ground_truth.size())
    {
        cout << "Error";
        return rmse;
    }

    // Accumulate squared residuals
    for (int i=0; i < estimations.size(); ++i)
    {
        VectorXd residual = estimations[i] - ground_truth[i];

        // Coefficient-wise multiplication
        residual = residual.array()*residual.array();
        rmse += residual;
    }

    // Calculate the mean
    rmse = rmse / estimations.size();

    // Calculate the squared root
    rmse = rmse.array().sqrt();

    return rmse;
}