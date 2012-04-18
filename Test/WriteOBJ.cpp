#include <vtkCellData.h>
#include <vtkCellArray.h>
#include <vtkDoubleArray.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPointData.h>
#include <vtkSmartPointer.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkPolyDataNormals.h>
#include <vtkOBJExporter.h>

#include <iostream>
#include <string>

using namespace std;
		
//example usage:
//WriteOBJ input.vtp output.obj
int main(int argc, char *argv[])
{
	//Read VTP File
	string InputFilename = argv[1]; //first command line argument
	string OutputFilename = argv[2]; //second command line argument
	
	vtkSmartPointer<vtkXMLPolyDataReader> reader = vtkSmartPointer<vtkXMLPolyDataReader>::New();
	cout << "Reading " << InputFilename << endl;
	reader->SetFileName(InputFilename.c_str());
	reader->Update();
	vtkSmartPointer<vtkPolyData> polydata = reader->GetOutput();
	
	//Write OBJ File
	vtkOBJExporter* objExporter = vtkOBJExporter::New();
	objExporter->WriteAPolyData(polydata, OutputFilename.c_str());
	
	return 0;
}
