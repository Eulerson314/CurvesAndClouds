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

#include <windows.h>
#include "curvesandcloudCore.h"
#include <QApplication>
#include "GUI/plotwindow.h"
#include "GUI/plots/formula_tex.h"
#include "GUI/algo/algo_gui.h"
#include "GUI/algo/mutablevalue.h"

#endif // CURVESANDCLOUD_H
