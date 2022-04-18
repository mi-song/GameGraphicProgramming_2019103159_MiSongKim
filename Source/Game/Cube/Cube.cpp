#include "Cube/Cube.h"

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   Cube::Cube

  Summary:  Constructor

  Args:     const std::filesystem::path& textureFilePath
              Path to the texture to use
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
/*--------------------------------------------------------------------
  TODO: Cube::Cube definition (remove the comment)
--------------------------------------------------------------------*/

Cube::Cube(const std::filesystem::path& textureFilePath)
    : BaseCube::BaseCube(textureFilePath)
{ }

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   Cube::Update

  Summary:  Updates the cube every frame

  Args:     FLOAT deltaTime
              Elapsed time

  Modifies: [m_world].
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void Cube::Update(_In_ FLOAT deltaTime)
{
    XMMATRIX mScale = XMMatrixScaling(0.4f, 0.4f, 0.4f);
    XMMATRIX mTranslate = XMMatrixTranslation(-2.0f, 0.0f, 0.0f);
    XMMATRIX mOrbit = XMMatrixRotationY(-deltaTime * 4.0f);

    m_world = mScale * mTranslate * mOrbit;
}