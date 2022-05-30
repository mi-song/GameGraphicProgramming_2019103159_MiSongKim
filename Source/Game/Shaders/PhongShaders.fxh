//--------------------------------------------------------------------------------------
// File: PhongShaders.fx
//
// Copyright (c) Kyung Hee University.
//--------------------------------------------------------------------------------------

#define NUM_LIGHTS (2)

//--------------------------------------------------------------------------------------
// Global Variables
//--------------------------------------------------------------------------------------
/*--------------------------------------------------------------------
  TODO: Declare a diffuse texture and a sampler state (remove the comment)
--------------------------------------------------------------------*/

Texture2D aTextures[2] : register(t0);
SamplerState aSamplers[2] : register(s0);

//--------------------------------------------------------------------------------------
// Constant Buffer Variables
//--------------------------------------------------------------------------------------
/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Cbuffer:  cbChangeOnCameraMovement

  Summary:  Constant buffer used for view transformation and shading
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
    bool HasNormalMap;
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

//--------------------------------------------------------------------------------------
/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Struct:   VS_PHONG_INPUT

  Summary:  Used as the input to the vertex shader
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
/*--------------------------------------------------------------------
  TODO: VS_PHONG_INPUT definition (remove the comment)
--------------------------------------------------------------------*/

struct VS_PHONG_INPUT
{
    float4 Position : POSITION;
    float2 TexCoord : TEXCOORD0;
    float3 Normal : NORMAL;
    float3 Tangent : TANGENT;
    float3 Bitangent : BITANGENT;
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
    float3 Tangent : TANGENT;
    float3 Bitangent : BITANGENT;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
/*--------------------------------------------------------------------
  TODO: Vertex Shader function VSPhong definition (remove the comment)
--------------------------------------------------------------------*/

PS_PHONG_INPUT VSPhong(VS_PHONG_INPUT input)
{
    PS_PHONG_INPUT output = (PS_PHONG_INPUT)0;
    
    // Space transformation
    output.Position = mul(input.Position, World);
    output.Position = mul(output.Position, View);
    output.Position = mul(output.Position, Projection);

    output.WorldPosition = mul(input.Position, World);

    // Compute the world normal 
    output.Normal = normalize(mul(float4(input.Normal, 0), World).xyz);
   
    output.TexCoord = input.TexCoord;

    if(HasNormalMap)
    {
        output.Tangent = normalize( mul ( float4 ( input.Tangent, 0.0f ), World ).xyz);
        output.Bitangent = normalize( mul ( float4 ( input.Bitangent, 0.0f ), World).xyz);
    }

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
    float3 normal = normalize(input.Normal);
    
    if(HasNormalMap)
    {
        // Sample the pixel in the normal map
        float4 bumpMap = aTextures[1].Sample(aSamplers[1], input.TexCoord);
        
        // Expand the range of the normal value from (0, +1) to (-1, +1)
        bumpMap = (bumpMap * 2.0f) - 1.0f;

        // Calculate the normal from the data in the normal map
        float3 bumpNormal = (bumpMap.x * input.Tangent) + (bumpMap.y * input.Bitangent) + (bumpMap.z * normal);

        // Normalize the resulting bump normal and replace existing normal
        normal = normalize(bumpNormal);
    }  

    float3 diffuse = 0;
    float3 specular = 0;

    float3 viewDirection = normalize(input.WorldPosition.xyz - CameraPosition.xyz);
    
    for (uint i = 0; i < NUM_LIGHTS; i++)
    {
        // calculate diffuse 
        float3 lightDirection = normalize( input.WorldPosition - LightPositions[i].xyz );
        diffuse += saturate( dot( normal, -lightDirection ) * LightColors[i].xyz);

        // calculate specular 
        float3 reflectDirection = reflect(lightDirection, normal);
        if (diffuse.x > 0)
        {
            specular += pow(saturate(dot(reflectDirection, -viewDirection)), 32.0f) * LightColors[i].xyz;
        }
    }

    // calculate ambient
    float3 ambient = float3(0.2f, 0.2f, 0.2f);

    // return float4((normal + 1.0f) / 2.0f,  1.0f);
    return float4( diffuse + specular + ambient, 1.0f) * aTextures[0].Sample(aSamplers[0], input.TexCoord);
}
