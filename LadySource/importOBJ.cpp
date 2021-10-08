#include <string>
#include <vector>
#include <fstream>
#include <sstream>



#include "importOBJ.hpp"
#include "mesh.hpp"
#include "glm/glm.hpp"


#include "db.hpp"
#include "ezdef.hpp"
#include "Console.hpp"



tmesh getOBJMESH(std::string OBJFileName)
{
	tmesh mobj;
	mobj.name = "";
	std::string line;
	
	std::ifstream objf(OBJFileName);
	char cmpc;

	if (objf.is_open())
	{
		ConsoleMessage("Obj Opened");
	}
	else
	{
		// Impossible name to assign a mesh.
		mobj.name = "_ _BAD MESH_ _";
		ConsoleMessage("OBJ COULD NOT BE OPENED");
		return mobj;
	}

	while (std::getline(objf, line))
	{
		cmpc = line.at(0);
		if (cmpc == 'v')
		{
			cmpc = line.at(1);

			if (cmpc == 't' or cmpc == 'n')
			{
				continue;
			}
			else
			{
				line = line.substr(1, line.size());
				glm::vec3 tempv;
				sscanf(line.c_str(), "%f %f %f\n", addrOfXYZ(tempv));
				mobj.verts.push_back(tempv);
				continue;
			}

		}
		eif(cmpc == 'o')
		{
			mobj.name = line.substr(2, line.size());
		}
		eif(cmpc == 'f')
		{
			line = line.substr(2, line.size());
			unsigned int pushedFace;
			std::stringstream faceBreaker;

			faceBreaker << line;
			while (faceBreaker >> pushedFace)
			{
				mobj.indices.push_back(pushedFace);
			}
			continue;
		}
		eif(cmpc == '#')
		{
			continue;
		}
		eif(cmpc == EOF)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	mobj.name = (mobj.name == "") ? "NO_NAME_ON_MESH" : mobj.name;
	mobj.adjustIndices();
	





	show "Mesh" spc mobj.name spc "loaded into memory" fin;
	return mobj;
}