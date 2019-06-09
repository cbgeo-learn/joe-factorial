#ifndef SHAPE_HEAD_H
#define SHAPE_HEAD_H


class ShapeHead
{
public:
    ShapeHead(){}
    virtual double area() const = 0;
    virtual double volume() const = 0;
};

#endif
