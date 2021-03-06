#include <curvesandcloud.h>

using namespace cnc;
using namespace cnc::algo::geometry;


int main(int argc, char *argv[])
{
    QApplication App(argc,argv);
    PlotWindow w; w.resize(500,500);

    PlotTab* T = w.add_tab("3D plotting");
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    auto t1 = high_resolution_clock::now();

    {
        MeshDisplayer* F3D = T->add_3D_frame();
        F3D->load_mesh_from_obj("../../data/bunny.obj",0.6);
        F3D->set_color_mode(mesh_color_mode::given_color);
        auto mesh = F3D->get_mesh();

        scalar h = mesh->mean_spacing();
        scalar t = h*h*80,eps = 1e-10;
        std::cout << "time step: " << t <<  std::endl;

        auto M_tLcot = mesh->compute_weight_plus_dt_cot_matrix(-t);

        vec v(mesh->get_nb_vertices());
        v(0) = 1.f;

        vec u = M_tLcot.conjugate_gradient(v,eps,true);
        auto grad = mesh->gradient_per_triangle(u);

        std::vector<QVector3D> X(mesh->get_nb_faces());
        for (uint k = 0;k<mesh->get_nb_faces();k++)
            X[k] = -grad[k].normalized();

        auto div = mesh->integrated_divergence_per_vertex(X,false);

        auto Lcot = mesh->compute_sparse_laplace_beltrami_matrix(false);
        auto dist = Lcot.conjugate_gradient(div,0.1,true);

        mesh->set_vertex_values(dist.scale_from_0_to_1());
        mesh->set_iso_lines_color(10);
    }

    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    std::cout << "exec time " << ms_int.count() << "ms" << std::endl;

    w.show();
    return App.exec();
}
