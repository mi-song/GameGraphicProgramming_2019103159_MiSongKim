#include "Cube/SunCube.h"

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   SunCube::SunCube

  Summary:  Constructor

  Args:     const std::filesystem::path& textureFilePath
              Path to the texture to use
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
/*--------------------------------------------------------------------
  TODO: Cube::Cube definition (remove the comment)
--------------------------------------------------------------------*/

SunCube::SunCube(const std::filesystem::path& textureFilePath)
    : BaseCube::BaseCube(textureFilePath)
{ }

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   SunCube::Update

  Summary:  Update the cube each frame

  Args:     FLOAT deltaTime
              Time difference of a frame
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/

void SunCube::Update(_In_ FLOAT deltaTime)
{
    XMMATRIX mOrbit = XMMatrixRotationY(deltaTime);
    XMMATRIX mScale = XMMatrixScaling(0.7f, 0.7f, 0.7f);
    m_world = mScale * mOrbit;
}


