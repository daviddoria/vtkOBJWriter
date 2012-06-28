/*=========================================================================
 *
 *  Copyright David Doria 2011 daviddoria@gmail.com
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkSphereSource.h>
#include <vtkXMLPolyDataReader.h>

#include "vtkOBJWriter.h"

int main (int argc, char *argv[])
{
  vtkSmartPointer<vtkPolyData> input;
  std::string outputFilename;

  // Verify command line arguments
  if(argc > 1) // Use the command line arguments
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
