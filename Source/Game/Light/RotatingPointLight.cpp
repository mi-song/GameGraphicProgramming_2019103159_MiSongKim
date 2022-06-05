#include "Light/RotatingPointLight.h"

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   RotatingPointLight::RotatingPointLight

  Summary:  Constructor

  Args:     const XMFLOAT4& position
              Position of the light
            const XMFLOAT4& color
              Position of the color
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
/*--------------------------------------------------------------------
  TODO: RotatingPointLight::RotatingPointLight definition (remove the comment)
--------------------------------------------------------------------*/

RotatingPointLight::RotatingPointLight(_In_ const XMFLOAT4& position, _In_ const XMFLOAT4& color)
    : PointLight(position, color)
{ }

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   RotatingPointLight::Update

  Summary:  Update every frame

  Args:     FLOAT deltaTime

  Modifies: [m_position, m_eye, m_eye, m_at,
            m_view].
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
void RotatingPointLight::Update(_In_ FLOAT deltaTime)
{
    XMVECTOR position = XMLoadFloat4(&m_position);

    XMMATRIX mOrbit = XMMatrixRotationY(-2.0f * deltaTime);
    position = XMVector3Transform(position, mOrbit);
    XMStoreFloat4(&m_position, position);

    m_eye = position;
    m_at = XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
    m_up = DEFAULT_UP;
    m_view = XMMatrixLookAtLH(m_eye, m_at, m_up);
}
