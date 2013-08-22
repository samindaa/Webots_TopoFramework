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
  graph.computeGraph();
  graph.topoSort();
  std::cout << graph << std::endl;

  graph.graphOutputAllocate();
  // Main loop:
  while (step(getBasicTimeStep()) != -1) // 32 ms
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

EPuckController& EPuckFramework::getController()
{
  // Simple and clean controller
  static EPuckController instance;
  return instance;
}

int main(int argc, char **argv)
{
  EPuckFramework::getController().run();
  return 0;
}
