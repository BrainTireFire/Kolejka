#ifndef TRIALCPP_RECT_H
#define TRIALCPP_RECT_H


class Rect {
private:
    double a, b;
public:
    Rect();
    Rect(double bok);
    Rect(double a, double b);
    double getA();
    double getB();
    double getDiagonal();
    double getArea() const;
    bool isLargerThan(const Rect&);
    void info();
};


#endif //TRIALCPP_RECT_H
