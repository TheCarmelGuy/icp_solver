#include "icp_solver.hpp"
#include <algorithm> 
#include <numeric> 


double icp_solver::SolveIcp(int _maxIterations, double _errorThreshold)
{

  double error = 1e10;
  double d_error=0;
  int numIterations = 0;
  

  int numPoints = sourcePointCloud_.cols();

  std::map<int, int> correspList_;


  while((d_error <= 0 ) && (numIterations < _maxIterations) && (error > _errorThreshold))
  {

    // compute means of targets 
    Eigen::VectorXd u_s = ComputeCentroid(sourcePointCloud_);
    Eigen::VectorXd u_t = ComputeCentroid(targetPointCloud_);

    //Center datasets
    Eigen::VectorXd S_prime = CenterPointcloud(sourcePointCloud_, u_s);
    Eigen::VectorXd T_prime = CenterPointcloud(targetPointCloud_, u_t);

    //Find initial correspondence (using KNN for correspondence);
    for(int i = 0; i < numPoints; i++)
    {





    }


  }



}


Eigen::VectorXd icp_solver::ComputeCentroid(Eigen::MatrixXd _pointcloud)
{


  Eigen::VectorXd meanValue = _pointcloud.colwise().mean();



}
