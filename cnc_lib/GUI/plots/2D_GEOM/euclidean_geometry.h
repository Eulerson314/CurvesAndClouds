#ifndef EUCLIDEAN_GEOMETRY_H
#define EUCLIDEAN_GEOMETRY_H

#include "cnc_types.h"
#include "cnc_error.h"
#include "../plottable.h"
#include "core/algo/linear_algebra/lin_alg.h"

namespace cnc {

namespace euclid {

using placer = std::function<vec()>;
using attribut = std::function<scalar()>;

class EuclideanPrimitive {
public:
    EuclideanPrimitive(){
    }
    virtual void draw(frame_draw_object& p,range x,range y) = 0;
    virtual void draw(frame_draw_object& p){
        draw(p,get_x_range(),get_y_range());
    };
    virtual void update_values() = 0;
    virtual ~EuclideanPrimitive(){}

    friend class EuclieanPlane;

    virtual range get_x_range() const = 0;
    virtual range get_y_range() const = 0;

    virtual bool is_dynamic() const{
        return true;
    }

    inline QColor getColor() const {
        return color;
    }

    inline virtual void set_color(const QColor& C) {
        color = C;
    }

protected:
    bool dynamic = true;
    static constexpr float range_eps = 0.001;
    QColor color;
};

class Point : public EuclideanPrimitive {
public:
    Point(const vec& p,int rad = 2) : radius(rad),color(QColorConstants::Blue){
        pos_updater = [p] () {return p;};
    }
    Point(const placer& p,int rad = 2) : pos_updater(p),radius(rad),color(QColorConstants::Blue){
    }

    range get_x_range() const override{
        return {pos(0)-range_eps,pos(0)+range_eps};
    }
    range get_y_range() const override{
        return {pos(1)-range_eps,pos(1)+range_eps};
    }

    inline vec get_pos() const {
        return pos;
    }

    virtual void draw(frame_draw_object& p,range rx,range ry) override;
    virtual void update_values() override;

private:

    vec pos = vec(2);
    placer pos_updater;
    int radius;
    QColor color = QColorConstants::Red;

};

class Segment : public EuclideanPrimitive {
public:
    Segment(Point* p1,Point* p2,int w = 2) :
        point1(p1),
        point2(p2),
        width(w){
        dynamic = p1->is_dynamic() || p2->is_dynamic();
        pos1 = vec(2);
        pos2 = vec(2);
    }
    virtual void draw(frame_draw_object& p,range rx,range ry) override;
    virtual void update_values() override;
    range get_x_range() const override{
        range rx = point1->get_x_range();
        algo::extend_range(rx,point2->get_x_range());
        return rx;
    }
    range get_y_range() const override{
        range ry = point1->get_y_range();
        algo::extend_range(ry,point2->get_y_range());
        return ry;
    }
private:
    vec pos1 = vec(2);
    vec pos2 = vec(2);
    Point* point1;
    Point* point2;
    int width;

};
class Circle : public EuclideanPrimitive {
public:

    Circle(const vec& p,scalar rad = 2) : radius(rad),color(QColorConstants::Blue){
        pos_updater = [p] () {return p;};
        rad_updater = [rad]() {return rad;};
    }
    Circle(const cscalar& p,scalar rad = 2) : radius(rad),color(QColorConstants::Blue){
        pos_updater = [p] () {return linear_utils::vec2(p.real(),p.imag());};
        rad_updater = [rad]() {return rad;};
    }
    Circle(const placer& p,const attribut& rad) : pos_updater(p),rad_updater(rad),color(QColorConstants::Blue){
    }

    range get_x_range() const override{
        return {pos(0)-radius-range_eps,pos(0)+radius+range_eps};
    }
    range get_y_range() const override{
        return {pos(1)-radius-range_eps,pos(1)+radius+range_eps};
    }

    inline vec get_pos() const {
        return pos;
    }

    virtual void draw(frame_draw_object& p,range rx,range ry) override;
    virtual void update_values() override;

private:

    vec pos = vec(2);
    placer pos_updater;
    attribut rad_updater;
    scalar radius;
    QColor color = QColorConstants::Red;
};

class CircleArc : public EuclideanPrimitive {
public:
    CircleArc(const vec& c,scalar radius,scalar start_angle,scalar angle_span){
        pos_updater = [c] (){
            return c;
        };
        start_angle_updater = [start_angle] (){
            return start_angle;
        };
        angle_span_updater = [angle_span] (){
            return angle_span;
        };
        rad_updater = [radius] (){
            return radius;
        };

    }

    range get_x_range() const override{
        return {pos(0)-radius-range_eps,pos(0)+radius+range_eps};
    }
    range get_y_range() const override{
        return {pos(1)-radius-range_eps,pos(1)+radius+range_eps};
    }


    virtual void update_values() override;
    virtual void draw(frame_draw_object& p,range rx,range ry) override;
private:
    vec pos;
    placer pos_updater;

    scalar radius;
    attribut rad_updater;

    scalar start_angle;
    attribut start_angle_updater;

    scalar angle_span;
    attribut angle_span_updater;

    QColor color = QColorConstants::Red;
};


}

}
#endif // EUCLIDEAN_GEOMETRY_H
