/*+===================================================================
  File:      SUNCUBE.H

  Summary:  Child Cube header file contains declarations of
             MiniCube class used for the lab samples of Game
             Graphics Programming course.

  Classes: Renderable

  � 2022 Kyung Hee University
===================================================================+*/
#pragma once

#include "Common.h"

#include "Cube/BaseCube.h"


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
      Class:    SunCube

      Summary:  SunCube class

      Methods:  Update
                  Update the cube each frame
                SunCube
                  Constructor.
                ~SunCube
                  Destructor.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/

class SunCube : public BaseCube
{
public:
    SunCube(const std::filesystem::path& textureFilePath);
    SunCube(const SunCube& other) = delete;
    SunCube(SunCube&& other) = delete;
    SunCube& operator=(const SunCube& other) = delete;
    SunCube& operator=(SunCube&& other) = delete;
    ~SunCube() = default;

    virtual void Update(_In_ FLOAT deltaTime) override;
};