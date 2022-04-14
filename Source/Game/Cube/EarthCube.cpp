#include "Cube/EarthCube.h"

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   Cube::Cube

  Summary:  Constructor

  Args:     const std::filesystem::path& textureFilePath
              Path to the texture to use
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
/*--------------------------------------------------------------------
  TODO: Cube::Cube definition (remove the comment)
--------------------------------------------------------------------*/

EarthCube::EarthCube(const std::filesystem::path& textureFilePath)
    : BaseCube::BaseCube(textureFilePath)
{ }

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   EarthCube::Update

  Summary:  Updates the cube every frame

  Args:     FLOAT deltaTime
              Elapsed time

  Modifies: [m_world].
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void EarthCube::Update(_In_ FLOAT deltaTime)
{
    XMMATRIX mScale = XMMatrixScaling(0.5f, 0.5f, 0.5f);
    XMMATRIX mTranslate = XMMatrixTranslation(-4.0f, 0.0f, 0.0f);
    XMMATRIX mOrbit = XMMatrixRotationY(-deltaTime * 2.0f);

    m_world = mScale * mTranslate * mOrbit;
}