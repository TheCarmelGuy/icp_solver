#include <Eigen/Dense>
#include <vector>
#include <pcl/point_cloud.h>

#include <map>
class icp_solver
{



  private:

    

    Eigen::MatrixXd sourcePointCloud_;
    Eigen::MatrixXd targetPointCloud_;
    

    double SolveIcp(int _maxIterations, double errorThreshold);
    double ComputeError(const int& _errorType);
    
    int DetermineCorrespoindences(Eigen::MatrixXd& _sourcePointCloud,
        Eigen::MatrixXd& _targetPointCloud, std::map<int,int>& _corespList );


    Eigen::VectorXd ComputeCentroid(Eigen::MatrixXd _pointcloud);
    Eigen::MatrixXd CenterPointcloud(Eigen::MatrixXd _pointcloud, Eigen::VectorXd);

};
