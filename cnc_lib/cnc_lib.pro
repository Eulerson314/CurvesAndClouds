QT += gui core widgets network# opengl

TEMPLATE = lib
DEFINES += CNC_LIB
DEFINES += PRECISION DOUBLE
DEFINES += CNC_OPENGL
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GUI/algo/algo_gui.cpp \
    GUI/algo/compute_shader.cpp \
    GUI/algo/mutablevalue.cpp \
    GUI/algo/mutablevaluecursor.cpp \
    GUI/algo/mutablevalueticker.cpp \
    GUI/plots/2D_GEOM/diagramplotter.cpp \
    GUI/plots/2D_GEOM/euclidean_geometry.cpp \
    GUI/plots/2D_GEOM/euclidean_plane.cpp \
    GUI/plots/2D_GEOM/mesh2ddisplayer.cpp \
    GUI/plots/2D_GEOM/valued2dmeshdisplayer.cpp \
    GUI/plots/3D/GLWrapper.cpp \
    GUI/plots/3D/camera.cpp \
    GUI/plots/3D/color.cpp \
    GUI/plots/3D/geometryengine.cpp \
    GUI/plots/3D/lights/light_source.cpp \
    GUI/plots/3D/lights/uniform_light.cpp \
    GUI/plots/3D/material.cpp \
    GUI/plots/3D/mesh_displayer.cpp \
    GUI/plots/3D/object.cpp \
    GUI/plots/3D/primitives/mesh_primitive.cpp \
    GUI/plots/3D/primitives/primitive.cpp \
    GUI/plots/3D/primitives/quad.cpp \
    GUI/plots/3D/primitives/triangle_primitive.cpp \
    GUI/plots/3D/primitives/tube_primitive.cpp \
    GUI/plots/3D/scene.cpp \
    GUI/plots/3D/scene_viewer.cpp \
    GUI/plots/3D/texture.cpp \
    GUI/plots/boolean_field.cpp \
    GUI/plots/colormap.cpp \
    GUI/plots/complex_function_plot.cpp \
    GUI/plots/curves.cpp \
    GUI/plots/d2_curve.cpp \
    GUI/plots/femdisplayer.cpp \
    GUI/plots/field.cpp \
    GUI/plots/figure.cpp \
    GUI/plots/formula_tex.cpp \
    GUI/plots/functionplot.cpp \
    GUI/plots/graphplotter.cpp \
    GUI/plots/grid_layer.cpp \
    GUI/plots/level_curve.cpp \
    GUI/plots/plot_frame.cpp \
    GUI/plots/plot_group.cpp \
    GUI/plots/plot_layer.cpp \
    GUI/plots/plot_stat_display.cpp \
    GUI/plots/plot_tab.cpp \
    GUI/plots/plottable.cpp \
    GUI/plots/point_cloud.cpp \
    GUI/plots/scalar_field.cpp \
    GUI/plots/stat_list_window.cpp \
    GUI/plots/stat_window.cpp \
    GUI/plots/trajectory.cpp \
    GUI/plots/vector_field.cpp \
    GUI/plotwindow.cpp \
    GUI/ColorWheel.cpp \
    core/algo/algebra/permutation.cpp \
    core/algo/algo.cpp \
    core/algo/bit_operations.cpp \
    core/algo/calculus/calculus.cpp \
    core/algo/calculus/complex_analysis.cpp \
    core/algo/calculus/differential_equations.cpp \
    core/algo/calculus/finite_differences.cpp \
    core/algo/calculus/finite_elements/vector_finite_elements.cpp \
    core/algo/calculus/fourier.cpp \
    core/algo/calculus/integration_scheme.cpp \
    core/algo/calculus/lagrange_interpolator.cpp \
    core/algo/calculus/optimization.cpp \
    core/algo/calculus/spline.cpp \
    core/algo/calculus/vector_calculus.cpp \
    core/algo/data_structures/interval_tree.cpp \
    core/algo/geometry/combinatorial_complexes.cpp \
    core/algo/geometry/convex_hull.cpp \
    core/algo/geometry/convexpolygon.cpp \
    core/algo/geometry/diagrams/diagrams.cpp \
    core/algo/geometry/geometry.cpp \
    core/algo/geometry/halfedge.cpp \
    core/algo/geometry/marching_cubes.cpp \
    core/algo/geometry/mesh.cpp \
    core/algo/geometry/mesh2.cpp \
    core/algo/geometry/meshgeneration.cpp \
    core/algo/geometry/parametrization.cpp \
    core/algo/geometry/polygon.cpp \
    core/algo/geometry/polynomial_curve.cpp \
    core/algo/geometry/quadtree.cpp \
    core/algo/geometry/quadtreemesher.cpp \
    core/algo/geometry/rotations.cpp \
    core/algo/geometry/sdf.cpp \
    core/algo/geometry/simpleglmesh.cpp \
    core/algo/geometry/smooth_interpolator.cpp \
    core/algo/geometry/triangle.cpp \
    core/algo/geometry/vertex.cpp \
    core/algo/graph/graph.cpp \
    core/algo/inout.cpp \
    core/algo/linear_algebra/iterative_solvers.cpp \
    core/algo/linear_algebra/lin_alg.cpp \
    core/algo/linear_algebra/preconditionners.cpp \
    core/algo/linear_algebra/sparse_matrix_builder.cpp \
    core/algo/matrix_functions.cpp \
    core/algo/statistics/random_var.cpp \
    core/algo/statistics/statistics.cpp \
    core/algo/symbolic/constant.cpp \
    core/algo/symbolic/expression.cpp \
    core/algo/symbolic/functions.cpp \
    core/algo/symbolic/operators.cpp \
    core/algo/symbolic/simplify.cpp \
    core/algo/symbolic/symbolic_lin_alg.cpp \
    core/algo/symbolic/term.cpp \
    core/algo/symbolic/variable.cpp \
    core/algo/time_handling.cpp \
    core/dual_numbers.cpp \
    core/quaternion.cpp \
    core/algo/calculus/finite_elements/finite_elements.cpp \
    core/sparse_matrix.cpp \
    examples/mesh_bank.cpp

HEADERS += \
    GUI/algo/algo_gui.h \
    GUI/algo/compute_shader.h \
    GUI/algo/mutablevalue.h \
    GUI/algo/mutablevaluecursor.h \
    GUI/algo/mutablevalueticker.h \
    GUI/display_info.h \
    GUI/plot_frame.h \
    GUI/plot_layer.h \
    GUI/plot_policy.h \
    GUI/plot_tab.h \
    GUI/plots/2D_GEOM/diagramplotter.h \
    GUI/plots/2D_GEOM/euclidean_geometry.h \
    GUI/plots/2D_GEOM/euclidean_plane.h \
    GUI/plots/2D_GEOM/mesh2ddisplayer.h \
    GUI/plots/2D_GEOM/valued2dmeshdisplayer.h \
    GUI/plots/3D/GLWrapper.h \
    GUI/plots/3D/camera.h \
    GUI/plots/3D/color.h \
    GUI/plots/3D/geometryengine.h \
    GUI/plots/3D/graphics.h \
    GUI/plots/3D/lights/light_source.h \
    GUI/plots/3D/lights/uniform_light.h \
    GUI/plots/3D/material.h \
    GUI/plots/3D/mesh_displayer.h \
    GUI/plots/3D/object.h \
    GUI/plots/3D/primitives/mesh_primitive.h \
    GUI/plots/3D/primitives/primitive.h \
    GUI/plots/3D/primitives/quad.h \
    GUI/plots/3D/primitives/triangle_primitive.h \
    GUI/plots/3D/primitives/tube_primitive.h \
    GUI/plots/3D/scene.h \
    GUI/plots/3D/scene_viewer.h \
    GUI/plots/3D/shaders/fshader.glsl \
    GUI/plots/3D/shaders/fshaderGL3.glsl \
    GUI/plots/3D/shaders/vshader.glsl \
    GUI/plots/3D/shaders/vshaderGL3.glsl \
    GUI/plots/3D/texture.h \
    GUI/plots/boolean_field.h \
    GUI/plots/colormap.h \
    GUI/plots/complex_function_plot.h \
    GUI/plots/curves.h \
    GUI/plots/d2_curve.h \
    GUI/plots/femdisplayer.h \
    GUI/plots/field.h \
    GUI/plots/figure.h \
    GUI/plots/formula_tex.h \
    GUI/plots/functionplot.h \
    GUI/plots/graphplotter.h \
    GUI/plots/grid_layer.h \
    GUI/plots/level_curve.h \
    GUI/plots/plot_frame.h \
    GUI/plots/plot_group.h \
    GUI/plots/plot_layer.h \
    GUI/plots/plot_policy.h \
    GUI/plots/plot_tab.h \
    GUI/plots/plottable.h \
    GUI/plots/plotwindow.h \
    GUI/plots/point_cloud.h \
    GUI/plots/scalar_field.h \
    GUI/plots/stat_list_window.h \
    GUI/plots/stat_window.h \
    GUI/plots/trajectory.h \
    GUI/plots/vector_field.h \
    GUI/plotwindow.h \
    GUI/ColorWheel.h \
    cnc_error.h \
    cnc_types.h \
    core/algo/algebra/permutation.h \
    core/algo/algo.h \
    core/algo/bit_operations.h \
    core/algo/calculus/calculus.h \
    core/algo/calculus/complex_analysis.h \
    core/algo/calculus/differential_equations.h \
    core/algo/calculus/finite_differences.h \
    core/algo/calculus/finite_elements/finite_elements.h \
    core/algo/calculus/finite_elements/vector_finite_elements.h \
    core/algo/calculus/fourier.h \
    core/algo/calculus/integration_scheme.h \
    core/algo/calculus/lagrange_interpolator.h \
    core/algo/calculus/optimization.h \
    core/algo/calculus/spline.h \
    core/algo/calculus/vector_calculus.h \
    core/algo/data_structures/interval_tree.h \
    core/algo/geometry/combinatorial_complexes.h \
    core/algo/geometry/convex_hull.h \
    core/algo/geometry/convexpolygon.h \
    core/algo/geometry/diagrams/diagrams.h \
    core/algo/geometry/geometry.h \
    core/algo/geometry/halfedge.h \
    core/algo/geometry/marching_cubes.h \
    core/algo/geometry/marching_table.h \
    core/algo/geometry/mesh.h \
    core/algo/geometry/mesh2.h \
    core/algo/geometry/meshgeneration.h \
    core/algo/geometry/parametrization.h \
    core/algo/geometry/polygon.h \
    core/algo/geometry/polynomial_curve.h \
    core/algo/geometry/quadtree.h \
    core/algo/geometry/quadtreemesher.h \
    core/algo/geometry/rotations.h \
    core/algo/geometry/sdf.h \
    core/algo/geometry/simpleglmesh.h \
    core/algo/geometry/smooth_interpolator.h \
    core/algo/geometry/triangle.h \
    core/algo/geometry/vertex.h \
    core/algo/graph/graph.h \
    core/algo/inout.h \
    core/algo/linear_algebra/iterative_solvers.h \
    core/algo/linear_algebra/lin_alg.h \
    core/algo/linear_algebra/preconditionners.h \
    core/algo/linear_algebra/sparse_matrix_builder.h \
    core/algo/matrix_functions.h \
    core/algo/statistics/random_var.h \
    core/algo/statistics/statistics.h \
    core/algo/symbolic/constant.h \
    core/algo/symbolic/expression.h \
    core/algo/symbolic/functions.h \
    core/algo/symbolic/operators.h \
    core/algo/symbolic/simplify.h \
    core/algo/symbolic/symbol.h \
    core/algo/symbolic/symbolic_lin_alg.h \
    core/algo/symbolic/term.h \
    core/algo/symbolic/variable.h \
    core/dual_numbers.h \
    core/matrix_algo.h \
    core/quaternion.h \
    core/sparse_matrix.h \
    core/time_handling.h \
    curvesandcloudCore.h \
    core/matrix.h \
    core/matrix_errors.h \
    curvesandcloud.h
    examples/mesh_bank.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
