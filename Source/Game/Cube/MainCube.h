/*+===================================================================
  File:      MAINCUBE.H

  Summary:  Child Cube header file contains declarations of
             MainCube class used for the lab samples of Game
             Graphics Programming course.

  Classes: Renderable

  � 2022 Kyung Hee University
===================================================================+*/
#pragma once

#include "Common.h"

#include "Cube/BaseCube.h"


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
      Class:    MainCube

      Summary:  MainCube class

      Methods:  Update
                  Update the cube each frame
                MainCube
                  Constructor.
                ~MainCube
                  Destructor.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/

class MainCube : public BaseCube
{
public:
    MainCube() = default;
    MainCube(const MainCube& other) = delete;
    MainCube(MainCube&& other) = delete;
    MainCube& operator=(const MainCube& other) = delete;
    MainCube& operator=(MainCube&& other) = delete;
    ~MainCube() = default;

    virtual void Update(_In_ FLOAT deltaTime) override;
};