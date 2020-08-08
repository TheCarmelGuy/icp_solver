#include "render/render.h"
#include  <unistd.h> 
#include <vector>

#include <pcl/io/pcd_io.h>
#include <pcl/common/common.h>

void renderFrame(pcl::visualization::PCLVisualizer::Ptr& viewer ,
const pcl::PointCloud<pcl::PointXYZ>::Ptr& inputCloud)
{
 

  
  //vector of viable colors 
  //TODO: Make enum
//    std::vector<Color> colors = {Color(0.4,0.56,0.4),Color(1,0.56,0.4),Color(1,1,0), Color(0,1,1), Color(1,0,1), Color(0.5,0,0.23), Color(0,0.5,0), Color(0.24,0.3,0.4)
 //   ,Color(0.4,0.2,0.4), Color(0.56,0.1,0.0) };

      renderPointCloud(viewer,inputCloud, "Source Cloud",Color(0.56,0.1,0.0)  );







}




//setAngle: SWITCH CAMERA ANGLE {XY, TopDown, Side, FPS}
void initCamera(CameraAngle setAngle, pcl::visualization::PCLVisualizer::Ptr& viewer)
{

    viewer->setBackgroundColor (0, 0, 0);
    
    // set camera position and angle
    viewer->initCameraParameters();
    // distance away in meters
    int distance = 16;
    
    switch(setAngle)
    {
        case XY : viewer->setCameraPosition(-distance, -distance, distance, 1, 1, 0); break;
        case TopDown : viewer->setCameraPosition(0, 0, distance, 1, 0, 1); break;
        case Side : viewer->setCameraPosition(0, -distance, 0, 0, 0, 1); break;
        case FPS : viewer->setCameraPosition(-10, 0, 0, 0, 0, 1);
    }

    if(setAngle!=FPS)
        viewer->addCoordinateSystem (0.3);
}


int main (int argc, char** argv)
{
    std::cout << "Starting PCD Environment" << std::endl;

    pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
    CameraAngle setAngle = Side;
    initCamera(setAngle, viewer);


    while (!viewer->wasStopped ())
    {
      // Clear viewer
      viewer->removeAllPointClouds();
      viewer->removeAllShapes();

      std::string sourcePcdFile = std::string("../data/bunny1.pcd");
      // Load pcd and run obstacle detection process
      pcl::PointCloud<pcl::PointXYZ>::Ptr inputCloud (new pcl::PointCloud<pcl::PointXYZ>);
      if (pcl::io::loadPCDFile<pcl::PointXYZ> (sourcePcdFile, *inputCloud) == -1) //* load the file
      {                         
          PCL_ERROR ("Couldn't read file \n");        
      }
      std::cerr << "Loaded " << inputCloud->points.size () << " data points from "+ sourcePcdFile << std::endl;

      renderFrame( viewer,inputCloud);
    
      viewer->spinOnce ();
    } 
}
