﻿#pragma once

#include "Common.h"

namespace library
{
#define NUM_LIGHTS (2)
#define MAX_NUM_BONES (256)
#define MAX_NUM_BONES_PER_VERTEX (16)

	struct SimpleVertex
	{
		XMFLOAT3 Position;
		XMFLOAT2 TexCoord;
		XMFLOAT3 Normal;
	};

	struct InstanceData
	{
		XMMATRIX Transformation;
	};

	struct AnimationData
	{
		XMUINT4 aBoneIndices;
		XMFLOAT4 aBoneWeights;
	};

	struct NormalData
	{
		XMFLOAT3 Tangent;
		XMFLOAT3 Bitangent;
	};

	struct CBChangeOnCameraMovement
	{
		XMMATRIX View;
		XMFLOAT4 CameraPosition;
	};

	struct CBChangeOnResize
	{
		XMMATRIX Projection;
	};

	struct CBChangesEveryFrame
	{
		XMMATRIX World;
		XMFLOAT4 OutputColor;
		BOOL HasNormalMap;
	};

	struct CBSkinning
	{
		XMMATRIX BoneTransforms[MAX_NUM_BONES];
	};

	struct PointLightStruct
	{
		XMFLOAT4 Position;
		XMFLOAT4 Color;
		XMFLOAT4 AttenuationDistance;
	};

	struct CBLights
	{
		PointLightStruct PointLights[NUM_LIGHTS];
	};

	struct CBShadowMatrix
	{
		XMMATRIX World;
		XMMATRIX View;
		XMMATRIX Projection;
		BOOL IsVoxel;
	};
}