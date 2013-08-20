// File:          EPuckFramework.cpp
// Date:          
// Description:   
// Author:        
// Modifications: 

#include "EPuckFramework.h"

EPuckController::EPuckController() :
    webots::DifferentialWheels(), graph(ime::Graph::getInstance())
{
}

EPuckController::~EPuckController()
{
  // Release all allocated resources
  graph.graphOutputRelease();
  ime::Graph::deleteInstance();
}

void EPuckController::run()
{
  bool firstRun = false;
  graph.computeGraph();
  graph.topoSort();
  std::cout << graph << std::endl;

  graph.graphOutputAllocateAndUpdate();
  // Main loop:
  while (step(getBasicTimeStep()) != -1)
  {
    // Timing stuff
    graph.graphOutputUpdate();
    // Timing stuff
  }
}

EPuckFramework::EPuckFramework()
{
}

EPuckFramework::~EPuckFramework()
{
}

EPuckController& EPuckFramework::getConroller()
{
  // Simple and clean controller
  static EPuckController instance;
  return instance;
}

int main(int argc, char **argv)
{
  EPuckFramework::getConroller().run();
  return 0;
}
