#include <igl/readOBJ.h>
#include <igl/loop.h>
#include <igl/opengl/glfw/Viewer.h>
#include <Eigen/Core>
#include <iostream>


int main(int argc, char* argv[])
{
    using namespace std;
    using namespace igl;
    Eigen::MatrixXi OF, F;
    Eigen::MatrixXd OV, V;
    bool show_swept_volume = false;

    igl::readOBJ("/Users/ABAH JOSIAH ABAH/source/repos/DTask/appleseed-shaderball-v5.obj", OV, OF);

    V = OV;
    F = OF;

    igl::opengl::glfw::Viewer viewer;
    viewer.data().set_mesh(V, F);
    viewer.data().set_face_based(true);

    viewer.callback_key_down =
        [&](igl::opengl::glfw::Viewer& viewer, unsigned char key, int mod)->bool
    {
        switch (key)
        {
        default:
            return false;
        //press 1 to return to original
        case '1':
        {
            V = OV;
            F = OF;
            break;
        }
        //press 2 to subdivide
        case '2':
        {
            igl::loop(Eigen::MatrixXd(V), Eigen::MatrixXi(F), V, F);
            break;
        }
        }
        viewer.data().clear();
        viewer.data().set_mesh(V, F);
        viewer.data().set_face_based(true);
        return true;
    };
    viewer.launch();
}