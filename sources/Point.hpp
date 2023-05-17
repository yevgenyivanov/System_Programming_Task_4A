#pragma once
class Point{
    private:
        double _x_coordinate;
        double _y_coordinate;
    public:
        Point(double _recv_x=0, double _recv_y=0): _x_coordinate(_recv_x), _y_coordinate(_recv_y){};
        double distance(const Point &) const;
        void print();
        static Point moveTowards(Point &, Point &, double);
        
};

namespace ariel{};