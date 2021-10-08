#ifndef ezdef_HPP
#define ezdef_HPP

/*
	Make life easier where you can.
*/

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <chrono>


#define ifn(x) if ((x) == (NULL))
#define elif else if
#define eif else if
#define ifSubReg(x, y)  if (std::regex_search((x), std::regex((y))))
#define eifSubReg(x, y) else if (std::regex_search((x), std::regex((y))))
#define for_all(thing,things) for (auto (thing) : (things))

#define or ||
#define upp +=

#define show std::cout <<
#define fin << std::endl

#define spc << ' ' <<
#define bslsh << '\\' <<
#define slsh << '/' <<

#define nxtLN std::cout << '\n';

#define null NULL

#define addrOfXYZ(srcVec) &(srcVec).x, &(srcVec).y, &(srcVec).z

#define unloadpck3(item1, item2, item3, packitem) (item1) = (packitem).vao; (item2) = (packitem).vbo; (item3) = (packitem).ebo;

#define startSpeedTest auto begin = std::chrono::high_resolution_clock::now();
#define stopSpeedTest auto end = std::chrono::high_resolution_clock::now(); auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin); std::cout << elapsed << std::endl;

#endif // ezdef_HPP