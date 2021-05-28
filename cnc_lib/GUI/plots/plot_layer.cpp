#include "plot_layer.h"
using namespace cnc;
#include <iostream>

Plot_layer::Plot_layer(QWidget* parent) : QWidget(parent)
{

}

void Plot_layer::display_layer(frame_draw_object& fdo)
{
    std::vector<uint> free_pl,dependant;
    for (uint p = 0;p<plots.size();p++){
        plots[p]->compute_values(fdo.fi);
        if (plots[p]->range_reference == nullptr)
            free_pl.push_back(p);
        else
            dependant.push_back(p);
    }
    for (uint f : free_pl)
        plots[f]->compute_value_range(fdo.fi);

    for (uint d : dependant){
        plots[d]->x_range = plots[d]->get_x_range();
        plots[d]->y_range = plots[d]->get_y_range();
    }

    for (uint p = 0;p<plots.size();p++){
        fdo.painter.setPen(QPen(plots[p]->plot_color, 2));
        plots[p]->plot(fdo);
    }
    if (plots.size())
        plots[0]->call_draw_axis(fdo);
}

Function_plot *Plot_layer::new_function_plot(const algo::calculus::scalar_function_1D &f, const range &x_range,plot_axis_policy fpp)
{
    Function_plot* FP = new Function_plot(f,x_range,fpp);
    insert_plot(FP);
    return FP;
}

Point_cloud *Plot_layer::new_point_cloud(const cloud &c, const uint radius)
{
    Point_cloud* PC = new Point_cloud(c, radius);
    insert_plot(PC);
    return (PC);
}

Point_cloud *Plot_layer::new_point_cloud(const cloud &c, const std::vector<uint> &radius)
{
    Point_cloud* PC = new Point_cloud(c, radius);
    insert_plot(PC);
    return (PC);
}

D2_curve *Plot_layer::new_2D_curve(const algo::calculus::nodes &X, const algo::calculus::nodes &Y)
{
    D2_curve* C = new D2_curve(X,Y);
    insert_plot(C);
    return (C);
}

D2_curve *Plot_layer::new_2D_curve(const std::vector<vec> &P)
{
   if (P[0].rowNum() != 2)
       throw Cnc_error("can't plot a non 2D Curve");
   algo::calculus::nodes X(P.size());
   algo::calculus::nodes Y(P.size());
   for (uint i = 0;i<P.size();i++){
       X[i] = P[i](0);
       Y[i] = P[i](1);
   }
   return new_2D_curve(X,Y);
}


Colormap *Plot_layer::new_colormap(const algo::calculus::scalar_function_2D &f, const range &x, const range &y,color_policy cp)
{
    Colormap* CM = new Colormap(f,x,y,cp);
    insert_plot(CM);
    return (CM);
}

Level_curve *Plot_layer::new_level_curve(const algo::calculus::scalar_function_2D &f, const range &x, const range &y, uint n)
{
    Level_curve* LC = new Level_curve(f,x,y,n);
    insert_plot(LC);
    return (LC);
}

Level_curve *Plot_layer::new_level_curve_unique(const algo::calculus::scalar_function_2D &f, const range &x, const range &y, float level)
{
    Level_curve* LC = new Level_curve(f,x,y,level);
    insert_plot(LC);
    return (LC);
}

Vector_field* Plot_layer::new_vector_field(const algo::calculus::vector_function_2D &f, const range &x, const range &y, uint n)
{
    Vector_field* VF = new Vector_field(f,x,y,n);
    insert_plot(VF);
    return (VF);
}

Figure *Plot_layer::new_figure_from_file(const QString &filename)
{
    Figure* F = new Figure(filename);
    insert_plot(F);
    return (F);
}

Figure *Plot_layer::new_void_figure(uint w, uint h)
{
    Figure* F = new Figure(w,h);
    insert_plot(F);
    return (F);
}

Figure *Plot_layer::new_figure_from_texturing(uint w,uint h,const algo_GUI::texture_function& tf)
{
    Figure* F = new Figure(w,h,tf);
    insert_plot(F);
    return (F);
}

formula* Plot_layer::add_text_frame(const std::string& ts,formula_disposition d)
{
    tex_stream text; text << ts << tex::endl;
    return add_text_frame_from_tex_stream(text,d);
}

formula* Plot_layer::add_text_frame_from_tex_stream(const tex_stream& ts,formula_disposition d)
{
    formula* F = new formula(ts,d);
    insert_plot(F);
    return F;
}

Plot_layer::~Plot_layer()
{
    for (Plottable* p : plots)
        delete p;
}

Plot_layer *Plot_layer::duplicate_layer(QWidget *parent) const
{
    Plot_layer* D = new Plot_layer(parent);
    D->plots.resize(plots.size());
    for (uint k = 0;k<plots.size();k++)
        D->plots[k] = plots[k];
    return D;
}


