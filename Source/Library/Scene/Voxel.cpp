#include "Scene/Voxel.h"

#include "Texture/Material.h"

namespace library
{
    /*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
      Method:   Voxel::Voxel

      Summary:  Constructor

      Args:     const XMFLOAT4& outputColor
                  Color of the voxel
    M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
    /*--------------------------------------------------------------------
      TODO: Voxel::Voxel definition (remove the comment)
    --------------------------------------------------------------------*/

    Voxel::Voxel(_In_ const XMFLOAT4& outputColor)
        : InstancedRenderable(outputColor)
    { }

    /*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
      Method:   Voxel::Voxel

      Summary:  Constructor

      Args:     std::vector<InstanceData>&& aInstanceData
                  Instance data
                const XMFLOAT4& outputColor
                  Color of the voxel
    M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
    /*--------------------------------------------------------------------
      TODO: Voxel::Voxel definition (remove the comment)
    --------------------------------------------------------------------*/

    Voxel::Voxel(_In_ std::vector<InstanceData>&& aInstanceData, _In_ const XMFLOAT4& outputColor)
        : InstancedRenderable(std::move(aInstanceData), outputColor)
    { }

    /*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
      Method:   Voxel::Initialize

      Summary:  Initializes a voxel

      Args:     ID3D11Device* pDevice
                  The Direct3D device to create the buffers
                ID3D11DeviceContext* pImmediateContext
                  The Direct3D context to set buffers

      Returns:  HRESULT
                  Status code
    M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
    /*--------------------------------------------------------------------
      TODO: Voxel::Initialize definition (remove the comment)
    --------------------------------------------------------------------*/

    HRESULT Voxel::Initialize(_In_ ID3D11Device* pDevice, _In_ ID3D11DeviceContext* pImmediateContext)
    {
        BasicMeshEntry basicMeshEntry;
        basicMeshEntry.uNumIndices = NUM_INDICES;

        m_aMeshes.push_back(basicMeshEntry);

        HRESULT hr = initialize(pDevice, pImmediateContext);
        if (FAILED(hr))
        {
            return hr;
        }

        hr = initializeInstance(pDevice);
        if (FAILED(hr))
        {
            return hr;
        }

        if (HasTexture() > 0)
        {
            hr = SetMaterialOfMesh(0, 0);
            if (FAILED(hr))
            {
                return hr;
            }
        }

        return S_OK;
    }

    /*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
      Method:   Voxel::Update

      Summary:  Updates the voxel every frame

      Args:     FLOAT deltaTime
                  Elapsed time
    M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
    /*--------------------------------------------------------------------
      TODO: Voxel::Update definition (remove the comment)
    --------------------------------------------------------------------*/

    void Voxel::Update(_In_ FLOAT deltaTime)
    {
    }

    /*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
      Method:   Voxel::GetNumVertices

      Summary:  Returns the number of vertices in the voxel
      
      Returns:  UINT
                  Number of vertices
    M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
    /*--------------------------------------------------------------------
      TODO: Voxel::GetNumVertices definition (remove the comment)
    --------------------------------------------------------------------*/

    UINT Voxel::GetNumVertices() const
    {
        return NUM_VERTICES;
    }

    /*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
      Method:   Voxel::GetNumIndices

      Summary:  Returns the number of indices in the voxel
      
      Returns:  UINT
                  Number of indices
    M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
    /*--------------------------------------------------------------------
      TODO: Voxel::GetNumIndices definition (remove the comment)
    --------------------------------------------------------------------*/

    UINT Voxel::GetNumIndices() const
    {
        return NUM_INDICES;
    }

    /*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
      Method:   Voxel::getVertices

      Summary:  Returns the pointer to the vertices data
      
      Returns:  const library::SimpleVertex*
                  Pointer to the vertices data
    M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
    /*--------------------------------------------------------------------
      TODO: Voxel::getVertices definition (remove the comment)
    --------------------------------------------------------------------*/

    const SimpleVertex* Voxel::getVertices() const
    {
        return VERTICES;
    }

    /*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
      Method:   Voxel::getIndices

      Summary:  Returns the pointer to the indices data
      
      Returns:  const WORD*
                  Pointer to the indices data
    M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
    /*--------------------------------------------------------------------
      TODO: Voxel::getIndices definition (remove the comment)
    --------------------------------------------------------------------*/

    const WORD* Voxel::getIndices() const
    {
        return INDICES;
    }
}