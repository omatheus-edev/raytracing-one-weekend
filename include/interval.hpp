#pragma once

struct Interval {
public:
    static const Interval empty;

    static const Interval universe;

    double min;

    double max;

    Interval();

    Interval(double min, double max);

    double size() const;

    bool contains(double x) const;

    bool surrounds(double x) const;
};