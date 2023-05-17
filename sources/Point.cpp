#include "Point.hpp"
#include <iostream>
double Point::distance(const Point &other) const{
    return 0.0;
}
void Point::print(){
    std::cout<< '(' <<this->_x_coordinate << ',' << this->_y_coordinate << ')' << std::endl;
}
Point Point::moveTowards(Point &_source, Point& _dest, double _dist){
    return Point(0,0);
}
