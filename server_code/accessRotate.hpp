#include "./struct.hpp"
#ifndef ACCESSROTATE_HPP
#define ACCESSROTATE_HPP

/*
    File Name: accessRotate.hpp
    Author: dazhanzheng

    Description: Define the access of each block in each rotation
*/

class AccessRotate
{
public:
    static Access I[4],L[4],T[4],X[4];
};

Access AccessRotate::I[0] = {1, 1, 0, 0};
Access AccessRotate::I[1] = {0, 0, 1, 1};
Access AccessRotate::I[2] = {1, 1, 0, 0};
Access AccessRotate::I[3] = {0, 0, 1, 1};

Access AccessRotate::L[0] = {1, 0, 0, 1};
Access AccessRotate::L[1] = {0, 1, 0, 1};
Access AccessRotate::L[2] = {0, 1, 1, 0};
Access AccessRotate::L[3] = {1, 0, 1, 0};

Access AccessRotate::T[0] = {0, 1, 1, 1};
Access AccessRotate::T[1] = {1, 1, 1, 0};
Access AccessRotate::T[2] = {1, 0, 1, 1};
Access AccessRotate::T[3] = {1, 1, 0, 1};

Access AccessRotate::X[0] = {1, 1, 1, 1};
Access AccessRotate::X[1] = {1, 1, 1, 1};
Access AccessRotate::X[2] = {1, 1, 1, 1};
Access AccessRotate::X[3] = {1, 1, 1, 1};

#endif