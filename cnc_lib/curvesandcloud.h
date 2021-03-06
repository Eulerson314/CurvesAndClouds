/**
  * @file curvesandcloud.h main file to include all the modules, requires Qt
  */
#ifndef CURVESANDCLOUD_H
#define CURVESANDCLOUD_H

#if defined(CNC_LIB)
#  define CNC_LIB_EXPORT Q_DECL_EXPORT
#else
#  define CNC_LIB_EXPORT Q_DECL_IMPORT
#endif

#include "curvesandcloudCore.h"
#include <QApplication>
#include "GUI/plotwindow.h"
#include "GUI/plots/formula_tex.h"
#include "GUI/algo/algo_gui.h"
#include "GUI/algo/mutablevalue.h"
#include "GUI/algo/mutablevaluecursor.h"
#include "GUI/plots/3D/scene_viewer.h"
#include "GUI/plots/3D/object.h"
#include "GUI/plots/3D/primitives/mesh_primitive.h"
#include "GUI/plots/3D/primitives/tube_primitive.h"
#include "GUI/plots/3D/camera.h"
#include "GUI/plots/3D/material.h"
#include "GUI/algo/compute_shader.h"
#include "GUI/plots/2D_GEOM/mesh2ddisplayer.h"

#endif // CURVESANDCLOUD_H
