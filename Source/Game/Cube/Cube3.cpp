#include "Cube/Cube3.h"

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   SunCube::SunCube

  Summary:  Constructor

  Args:     const std::filesystem::path& textureFilePath
              Path to the texture to use
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
/*--------------------------------------------------------------------
  TODO: Cube::Cube definition (remove the comment)
--------------------------------------------------------------------*/

Cube3::Cube3(const std::filesystem::path& textureFilePath)
    : BaseCube::BaseCube(textureFilePath)
{ }

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   SunCube::Update

  Summary:  Update the cube each frame

  Args:     FLOAT deltaTime
              Time difference of a frame
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/

void Cube3::Update(_In_ FLOAT deltaTime)
{
    XMMATRIX mTranslate = XMMatrixTranslation(4.0f, XMScalarSin(deltaTime*10.0f), 0.0f);
    XMMATRIX mOrbit = XMMatrixRotationY(deltaTime*2.0f);
    XMMATRIX mScale = XMMatrixScaling(0.6f, 0.6f, 0.6f);
    m_world = mTranslate * mOrbit * mScale;
}


