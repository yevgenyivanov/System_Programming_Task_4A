#include "doctest.h"
#include "sources/Team.hpp"
#include <iostream>
#include <cmath>
#include <limits>
using namespace ariel;
TEST_CASE("Point tests")
{
    // create two points on same axis and analyse distance between them
    Point _point1(15, 0), _point2(-5, 0);
    CHECK(_point1.distance(_point2) == 20);
    // create additional point on different axis and analyse distance
    Point _point3(0, 15);
    // double dist = sqrt(2*(15*15));
    // std::cout << dist << std::endl;
    // dist calculation works as desired
    CHECK(_point1.distance(_point3) == 21.2132);

    CHECK_FALSE(_point3.distance(_point2) == 10);
    _point3 = Point::moveTowards(_point1, _point2, 5);
    CHECK(_point1.distance(_point3) == 5);

    // move distance that excels initial distance between two points
    _point3 = Point::moveTowards(_point1, _point2, 25);
    CHECK(_point2.distance(_point3) == 5);
    double max_double = std::numeric_limits<double>::max();
    double min_double = std::numeric_limits<double>::min();
    CHECK_NOTHROW(Point(max_double, max_double));
    CHECK_NOTHROW(Point(min_double, min_double));
    CHECK_NOTHROW(Point(max_double, min_double));
}
TEST_CASE("Standing on maximum/minimum point coordinates ")
{
    // standing on maximum possible value of point
    double max_double = std::numeric_limits<double>::max();
    double min_double = std::numeric_limits<double>::min();
    YoungNinja _testNinja("Point Holder", Point(max_double, 0.0));
    YoungNinja _testNinja2("Move Tester", Point(max_double - 1, 0.0));
    CHECK_NOTHROW(_testNinja.move(&_testNinja2)); // unit allowed to move to max_double on x axis
    YoungNinja _testNinja3("Point Holder 2", Point(min_double, 0.0));
    YoungNinja _testNinja4("Move Tester 2", Point(min_double + 1, 0.0));
    CHECK_NOTHROW(_testNinja3.move(&_testNinja4)); // unit allowed to move to min_double on x axis
    YoungNinja _testNinja5("Point Holder 3", Point(0.0, max_double));
    YoungNinja _testNinja6("Move Tester 3", Point(0.0, max_double - 1));
    CHECK_NOTHROW(_testNinja5.move(&_testNinja6)); // unit allowed to move to max_double on y axis
    YoungNinja _testNinja7("Point Holder 4", Point(0.0, min_double));
    YoungNinja _testNinja8("Move Tester 4", Point(0.0, min_double + 1));
    CHECK_NOTHROW(_testNinja7.move(&_testNinja8)); // unit allowed to move to min_double on y axis
}
TEST_CASE("Exceeding maximum/minimum point coordinates")
{
    double max_double = std::numeric_limits<double>::max();
    double min_double = std::numeric_limits<double>::min();
    //
    CHECK_THROWS(Point(max_double + 1, 0.0));
    CHECK_THROWS(Point(0.0, max_double + 1));
    CHECK_THROWS(Point(min_double - 1, 0.0));
    CHECK_THROWS(Point(0.0, min_double - 1));
}
TEST_CASE("Team and members tests")
{
    Cowboy _cowboy("Cowboy", Point(20, 0));
    YoungNinja _youngNinja("Ninja", Point(20, 20));
    // cannot shoot self
    CHECK_THROWS(_cowboy.attack(&_cowboy));
    // cannot slice self
    CHECK_THROWS(_youngNinja.attack(&_youngNinja));
    // cannot attack NULL
    CHECK_THROWS(_cowboy.attack(NULL));
    CHECK_THROWS(_youngNinja.attack(NULL));
    // cannot shoot more than 6 shots
    for (int i = 0; i < 6; i++)
    {
        _cowboy.attack(&_youngNinja);
    }
    CHECK_FALSE(_cowboy.hasBoolets());
    // empty magazine for cowboy doesn't deal damage
    int tmp_hp = _youngNinja.get_hp();
    _cowboy.attack(&_youngNinja);
    CHECK(_youngNinja.get_hp() == tmp_hp);
    // slice target from far away
    tmp_hp = _cowboy.get_hp();
    _youngNinja.attack(&_cowboy);
    CHECK(_cowboy.get_hp() == tmp_hp);
    // eliminate target
    _cowboy.reload();
    for (int i = 0; i < 4; i++) //_youngNinja has 40hp remaining
    {
        _cowboy.attack(&_youngNinja);
    }
    CHECK_FALSE(_youngNinja.isAlive());
    //
    //
    // team
    Team _team1(&_youngNinja);
    // re-adding team leader
    CHECK_THROWS(_team1.add(&_youngNinja));
    _team1.add(&_cowboy);
    // re-adding already existing member
    CHECK_THROWS(_team1.add(&_cowboy));
    SUBCASE("Full team addition")
    {
        _team1.add(new OldNinja("Old Ninja", Point(0, 0)));
        _team1.add(new OldNinja("Old Ninja", Point(0, 1)));
        _team1.add(new OldNinja("Old Ninja", Point(0, 2)));
        _team1.add(new TrainedNinja("Trained Ninja", Point(0, 3)));
        _team1.add(new TrainedNinja("Trained Ninja", Point(0, 4)));
        _team1.add(new TrainedNinja("Trained Ninja", Point(0, 5)));
        _team1.add(new Cowboy("Cowboy", Point(0, 6)));
        CHECK_THROWS(_team1.add(new Cowboy("Cowboy", Point(0, 7)))); // adding extra team member
    }
}