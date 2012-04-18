#include <vtkSmartPointer.h>

#include "vtkOBJWriter.h"

int main (int argc, char *argv[])
{
  
  vtkSmartPointer<vtkOBJWriter> writer = 
      vtkSmartPointer<vtkOBJWriter>::New();

  return EXIT_SUCCESS;
}
