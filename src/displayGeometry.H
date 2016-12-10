#ifndef displayGeometry_H
#define displayGeometry_H

#include "parRun.H"
namespace Koala
{

void displayGeometry
(
  const char* fileName ,
  const char* filePath = NULL
)
{
  // Open file for read
  parRun Run;
  std::ifstream file;
  Run.openFile(file, fileName, NULL, filePath);
  
  // Read sizeofPoints
  int sizePointsOfBlocks;  
  file >> sizePointsOfBlocks;
  
  // Read Points
  double (*pointsOfBlocks)[2];
  pointsOfBlocks = new double[sizePointsOfBlocks][2];
  for (int i = 0; i < sizePointsOfBlocks; i++)
    for (int j = 0; j < 2; j++)
      file >> pointsOfBlocks[i][j];
      
  // Read size of blocks
  int sizeBlocks; 
  file >> sizeBlocks;
  
  // Read blocks
  int (*blocks)[4];
  blocks = new int[sizeBlocks][4];
  for (int i = 0; i < sizeBlocks; i++)
    for (int j = 0; j < 4; j++)
    file >> blocks[i][j];
    
  // display
  glClear(GL_COLOR_BUFFER_BIT);
  for (int blockId = 0; blockId < sizeBlocks; blockId++ )
  {
    glBegin(GL_POLYGON);
    for(int numPointInBlock = 0; numPointInBlock < 4;  numPointInBlock++)
      glVertex2f(points[cells[blockId][ numPointInBlock]][0], points[cells[blockId][ numPointInBlock]][1]);
    glEnd();
  }
  glFlush();
}

}
#endif
