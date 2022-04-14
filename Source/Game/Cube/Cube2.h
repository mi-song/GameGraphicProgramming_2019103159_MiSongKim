/*+===================================================================
  File:      CUBE2.H

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
class Cube2 : public BaseCube
{
public:
    Cube2(const std::filesystem::path& textureFilePath);
    Cube2(const Cube2& other) = delete;
    Cube2(Cube2&& other) = delete;
    Cube2& operator=(const Cube2& other) = delete;
    Cube2& operator=(Cube2&& other) = delete;
    ~Cube2() = default;

    virtual void Update(_In_ FLOAT deltaTime) override;
};