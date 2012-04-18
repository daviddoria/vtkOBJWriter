#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkSphereSource.h>
#include <vtkXMLPolyDataReader.h>

#include "vtkOBJWriter.h"

int main (int argc, char *argv[])
{
  vtkSmartPointer<vtkPolyData> input;
  vtkstd::string outputFilename;
  
  //Verify command line arguments
  if(argc > 1) //use the command line arguments
    {
    if(argc != 3)
      {
      std::cout << "Required arguments: InputFilename.vtp OutputFilename.obj" << std::endl;
      return EXIT_FAILURE;
      }
    vtkSmartPointer<vtkXMLPolyDataReader> reader =
      vtkSmartPointer<vtkXMLPolyDataReader>::New();
    reader->SetFileName(argv[1]);
    reader->Update();

    input->ShallowCopy(reader->GetOutput());

    outputFilename = argv[2];
  
    }
  else
    {
    outputFilename = "output.obj";
    vtkSmartPointer<vtkSphereSource> sphereSource =
      vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->Update();
    input->ShallowCopy(sphereSource->GetOutput());
    }
  
  vtkSmartPointer<vtkOBJWriter> writer = 
      vtkSmartPointer<vtkOBJWriter>::New();
  writer->SetInputData(input);
  writer->SetFileName(outputFilename.c_str());
  writer->Update();
  
  return EXIT_SUCCESS;
}
