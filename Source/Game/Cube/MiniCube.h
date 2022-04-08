/*+===================================================================
  File:      MINICUBE.H

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
      Class:    MiniCube

      Summary:  MainCube class

      Methods:  Update
                  Update the cube each frame
                MiniCube
                  Constructor.
                ~MiniCube
                  Destructor.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/

class MiniCube : public BaseCube
{
public:
    MiniCube() = default;
    MiniCube(const MiniCube& other) = delete;
    MiniCube(MiniCube&& other) = delete;
    MiniCube& operator=(const MiniCube& other) = delete;
    MiniCube& operator=(MiniCube&& other) = delete;
    ~MiniCube() = default;

    virtual void Update(_In_ FLOAT deltaTime) override;
};