#include "common.hh"

bool cmp(double l1, double l2)
{
    return (fabs(l1 - l2) < eps) ? true : false;
}