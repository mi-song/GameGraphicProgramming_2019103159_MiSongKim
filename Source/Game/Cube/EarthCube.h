/*+===================================================================
  File:      EARTHCUBE.H

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
class EarthCube : public BaseCube
{
public:
    EarthCube(const std::filesystem::path& textureFilePath);
    EarthCube(const EarthCube& other) = delete;
    EarthCube(EarthCube&& other) = delete;
    EarthCube& operator=(const EarthCube& other) = delete;
    EarthCube& operator=(EarthCube&& other) = delete;
    ~EarthCube() = default;

    virtual void Update(_In_ FLOAT deltaTime) override;
};