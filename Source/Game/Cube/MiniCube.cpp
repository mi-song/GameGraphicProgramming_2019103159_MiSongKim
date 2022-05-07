#include "Cube/MiniCube.h"

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   MiniCube::Update

  Summary:  Update the cube each frame

  Args:     FLOAT deltaTime
              Time difference of a frame
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/

void MiniCube::Update(_In_ FLOAT deltaTime)
{
    XMMATRIX mSpin = XMMatrixRotationZ(-deltaTime);
    XMMATRIX mOrbit = XMMatrixRotationY(-deltaTime * 2.0f);
    XMMATRIX mTranslate = XMMatrixTranslation(-4.0f, 0.0f, 0.0f);
    XMMATRIX mScale = XMMatrixScaling(0.3f, 0.3f, 0.3f);

    m_world = mScale * mSpin * mTranslate * mOrbit;
}


