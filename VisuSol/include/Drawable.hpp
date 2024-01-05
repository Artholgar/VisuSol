#pragma once
#include <iostream>

class Drawable {
public:
    virtual void draw() const { std::cout << "Base class default behaviour\n"; };

private:
};