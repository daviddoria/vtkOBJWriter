// .NAME vtkOBJWriter - write a Wavefront OBJ file.
// .SECTION Description

#ifndef __vtkOBJWriter_h
#define __vtkOBJWriter_h

#include "vtkPolyDataAlgorithm.h" //superclass

class vtkOBJWriter : public vtkPolyDataAlgorithm
{
public:
  static vtkOBJWriter *New();
  vtkTypeRevisionMacro(vtkOBJWriter,vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Specify the name of the file to write out.
  vtkSetStringMacro(FileName);
  vtkGetStringMacro(FileName);
  
  int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);

protected:
  vtkOBJWriter();
  ~vtkOBJWriter();

private:
  vtkOBJWriter(const vtkOBJWriter&);  // Not implemented.
  void operator=(const vtkOBJWriter&);  // Not implemented.
  
  char *FileName;

};

#endif

