#include "Cube/RotatingCube.h"

RotatingCube::RotatingCube(const XMFLOAT4& outputColor)
    : BaseCube(outputColor)
{
}

void RotatingCube::Update(_In_ FLOAT deltaTime)
{
    // Rotate cube around the origin
    // static FLOAT t = 0.0f;
    // t += deltaTime;

    XMMATRIX mOrbit = XMMatrixRotationY(-deltaTime * 2.0f);
    XMMATRIX mTranslate = XMMatrixTranslation(0.0f, 30.0f, -50.0f);

    m_world = mTranslate * mOrbit;
    // m_world = mScale * mSpin * mTranslate * mOrbit;
}