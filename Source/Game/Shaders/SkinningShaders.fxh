//--------------------------------------------------------------------------------------
// File: SkinningShaders.fx
//
// Copyright (c) Microsoft Corporation.
//--------------------------------------------------------------------------------------
#define NUM_LIGHTS (2)

//--------------------------------------------------------------------------------------
// Global Variables
//--------------------------------------------------------------------------------------
static const unsigned int MAX_NUM_BONES = 256u;
/*--------------------------------------------------------------------
  TODO: Declare a diffuse texture and a sampler state (remove the comment)
--------------------------------------------------------------------*/

Texture2D txDiffuse : register(t0);
SamplerState samLinear : register(s0);

//--------------------------------------------------------------------------------------
// Constant Buffer Variables
//--------------------------------------------------------------------------------------
/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Cbuffer:  cbChangeOnCameraMovement

  Summary:  Constant buffer used for view transformation
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
/*--------------------------------------------------------------------
  TODO: cbChangeOnCameraMovement definition (remove the comment)
--------------------------------------------------------------------*/

cbuffer cbChangeOnCameraMovement : register(b0)
{
    matrix View;
    float4 CameraPosition;
}

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Cbuffer:  cbChangeOnResize

  Summary:  Constant buffer used for projection transformation
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
/*--------------------------------------------------------------------
  TODO: cbChangeOnResize definition (remove the comment)
--------------------------------------------------------------------*/

cbuffer cbChangeOnResize : register(b1)
{
    matrix Projection;
}


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Cbuffer:  cbChangesEveryFrame

  Summary:  Constant buffer used for world transformation
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
/*--------------------------------------------------------------------
  TODO: cbChangesEveryFrame definition (remove the comment)
--------------------------------------------------------------------*/

cbuffer cbChangesEveryFrame : register(b2)
{
    matrix World;
    float4 OutputColor;
}

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Cbuffer:  cbLights

  Summary:  Constant buffer used for shading
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
/*--------------------------------------------------------------------
  TODO: cbLights definition (remove the comment)
--------------------------------------------------------------------*/

cbuffer cbLights : register(b3)
{
    float4 LightPositions[NUM_LIGHTS];
    float4 LightColors[NUM_LIGHTS];
}

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Cbuffer:  cbSkinning

  Summary:  Constant buffer used for skinning
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
/*--------------------------------------------------------------------
  TODO: cbSkinning definition (remove the comment)
--------------------------------------------------------------------*/

cbuffer cbSkinning : register(b4)
{
    matrix BoneTransforms[MAX_NUM_BONES];
};

//--------------------------------------------------------------------------------------
/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Struct:   VS_INPUT

  Summary:  Used as the input to the vertex shader
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
/*--------------------------------------------------------------------
  TODO: VS_INPUT definition (remove the comment)
--------------------------------------------------------------------*/

struct VS_INPUT
{
    float4 Position : POSITION;
    float2 TexCoord : TEXCOORD0;
    float3 Normal : NORMAL;
    uint4 BoneIndices : BONEINDICES;
    float4 BoneWeights : BONEWEIGHTS; 
};

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Struct:   PS_PHONG_INPUT

  Summary:  Used as the input to the pixel shader, output of the 
            vertex shader
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
/*--------------------------------------------------------------------
  TODO: PS_PHONG_INPUT definition (remove the comment)
--------------------------------------------------------------------*/

struct PS_PHONG_INPUT
{
    float4 Position : SV_POSITION;
    float2 TexCoord : TEXCOORD0;
    float3 Normal : NORMAL;
    float3 WorldPosition : WORLDPOS;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
/*--------------------------------------------------------------------
  TODO: Vertex Shader function VSPhong definition (remove the comment)
--------------------------------------------------------------------*/

PS_PHONG_INPUT VSPhong(VS_INPUT input)
{
    PS_PHONG_INPUT output = (PS_PHONG_INPUT)0;
    
    matrix skinTransform = (matrix)0;
    skinTransform += BoneTransforms[input.BoneIndices.x] * input.BoneWeights.x;
    skinTransform += BoneTransforms[input.BoneIndices.y] * input.BoneWeights.y;
    skinTransform += BoneTransforms[input.BoneIndices.z] * input.BoneWeights.z;
    skinTransform += BoneTransforms[input.BoneIndices.w] * input.BoneWeights.w;

    // Space transformation
    output.Position = mul( input.Position, skinTransform);
    output.Position = mul( output.Position, World );
    output.Position = mul( output.Position, View );
    output.Position = mul( output.Position, Projection );

    // Compute the world normal 
    output.Normal = normalize( mul ( float4 ( input.Normal, 0 ), World ).xyz);
    output.Normal = normalize( mul ( float4 ( output.Normal, 0 ), skinTransform ).xyz );
    
    // World Position
    output.WorldPosition = mul( input.Position, World ).xyz;

    output.TexCoord = input.TexCoord;

    return output;
}

//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
/*--------------------------------------------------------------------
  TODO: Pixel Shader function PSPhong definition (remove the comment)
--------------------------------------------------------------------*/

float4 PSPhong(PS_PHONG_INPUT input) : SV_Target
{
    float3 diffuse = 0;
    float3 specular = 0;

    float3 viewDirection = normalize(input.WorldPosition.xyz - CameraPosition.xyz);
    
    for (uint i = 0; i < NUM_LIGHTS; i++)
    {
        // calculate diffuse 
        float3 lightDirection = normalize( input.WorldPosition - LightPositions[i].xyz );
        diffuse += saturate( dot( input.Normal, -lightDirection ) * LightColors[i].xyz);

        // calculate specular 
        float3 reflectDirection = reflect(lightDirection, input.Normal);
        if (diffuse.x > 0)
        {
            specular += pow(saturate(dot(reflectDirection, -viewDirection)), 32.0f) * LightColors[i].xyz;
        }
    }

    // calculate ambient
    float3 ambient = float3(0.2f, 0.2f, 0.2f);

    return float4( diffuse + specular + ambient, 1.0f) * txDiffuse.Sample(samLinear, input.TexCoord);
}