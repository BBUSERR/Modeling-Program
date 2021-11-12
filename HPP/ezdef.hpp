// ez defs
#ifndef ezdef_HPP
#define ezdef_HPP

#include <iostream>
#include <vector>

using namespace std;

#define ifn(x) if ((x) == (NULL))
#define ifeq(x, y) if ((x) == (y))
#define iflt(x, y) if ((x) < (y))
#define ifgt(x, y) if ((x) > (y))

#define eifn(x)	else if ((x) == (NULL))
#define eifeq(x, y) else if ((x) == (y))
#define eiflt(x, y) else if ((x) < (y))
#define eifgt(x, y) else if ((x) > (y))


#define elif else if
#define eif else if

#define null NULL

#define show cout <<
#define __ << endl

#define spc << ' ' <<
#define spcc << ' '
#define bslsh << '\\' <<
#define slsh << '/' <<

#define addrOfXYZ(srcVec) &(srcVec).x, &(srcVec).y, &(srcVec).z

#define for_all(thing,things) for (auto (thing) : (things))
#endif // ezdef_HPP
