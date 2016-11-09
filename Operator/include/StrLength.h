#ifndef __STRLENGTH_H__
#define __STRLENGTH_H__

#include "common.h"

class StrLength
{
    public:
    StrLength(unsigned int min, unsigned int max)
    {
        unsigned int tmp = min + max;
        min = min > max? max : min;
        max = tmp - min;
    }
    bool operator()(const std::string &str)
    {
        auto len = str.size();
        return (len >= min && len < max);
    }

    private:
    unsigned int min, max;
};

#endif