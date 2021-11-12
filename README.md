## libigl example project
used libigl example project as template for this project

## libigl

Then build libigl. made sure the project was cloned in the same folder where libigl is located.

## Dependencies

The only dependencies are STL, Eigen, [libigl](http://libigl.github.io/libigl/) and the dependencies
of the `igl::opengl::glfw::Viewer` (OpenGL, glad and GLFW).
The CMake build system will automatically download libigl and its dependencies using
[CMake FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html),
thus requiring no setup on your part.

## Compile

Compile this project using the standard cmake routine:

    mkdir build
    cd build
    cmake ..
    make

## 
tested using Visual Studio 22 RC.

##
was only able to do the subdivision part: run the app, the first view is the original, then press 2 to view 
the subdivided shaderball.
