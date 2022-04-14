/*+===================================================================
  File:      CUBE3H

  Summary:   Cube header file contains declarations of Cube class
             used for the lab samples of Game Graphics Programming
             course.

  Classes: Cube

  © 2022 Kyung Hee University
===================================================================+*/
#pragma once

#include "Common.h"

#include "Cube/BaseCube.h"

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
  Class:    EarthCube

  Summary:  A renderable 3d cube object

  Methods:  Update
              Overriden function that updates the cube every frame
            Cube
              Constructor.
            ~Cube
              Destructor.
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/
class Cube3 : public BaseCube
{
public:
    Cube3(const std::filesystem::path& textureFilePath);
    Cube3(const Cube3& other) = delete;
    Cube3(Cube3&& other) = delete;
    Cube3& operator=(const Cube3& other) = delete;
    Cube3& operator=(Cube3&& other) = delete;
    ~Cube3() = default;

    virtual void Update(_In_ FLOAT deltaTime) override;
};