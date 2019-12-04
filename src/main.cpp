#include <iostream>

#include "Voter.h"

int main()
{
    c_node cn1;
    cn1.id = 1;
    cn1.ts = 1000000993293;
    cn1.x = 24.0;
    cn1.y = 42;

    c_node cn2;
    cn2.id = 2;
    cn2.ts = 999888771293;
    cn2.x = 27.0;
    cn2.y = 43;

    float x_;
    float y_;

    std::cout << "Lienar voting:" << std::endl;

    voteLinear(cn1, cn2, &x_, &y_);
    std::cout << "x: " << x_ << std::endl;
    std::cout << "y: " << y_ << std::endl;

    std::cout << "Weightrnd voting:" << std::endl;
    voteWeighted(cn1, cn2, &x_, &y_);
    std::cout << "x: " << x_ << std::endl;
    std::cout << "y: " << y_ << std::endl;
}