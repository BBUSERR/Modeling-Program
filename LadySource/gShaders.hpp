
#ifndef gShaders_HPP
#define gShaders_HPP
#include "glad/glad.h"
#include <string>
#include <fstream>

#define basicShader_Vert  "#version 460 core\n""layout (location = 0) in vec3 aPos;\n""void main()\n""{\n""   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n""}\0"
#define basicShader_Frag "#version 460 core\n""out vec4 FragColor;\n" "void main()\n""{\n" "	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n""}\0"

#define redShader_Vert "#version 460 core\n""layout (location = 0) in vec3 aPos;\n""out vec4 vertexColor;\n""void main()\n""{\n""gl_Position = vec4(aPos, 1.0);\n""vertexColor = vec4(0.5, 0.0, 0.0, 1.0);\n""}\0"
#define redShader_Frag "#version 460 core\n""out vec4 FragColor;\n""in vec4 vertexColor;\n""void main()\n""{\n""FragColor = vertexColor;\n""}\0"

const char* testShader_Vert = "#version 440 core\n""layout(location = 0) in vec3 vertexPosition;\n""void main()\n""{\n""    gl_Position = vec4(vertexPosition, 1.0);\n""}\0";
const char* testShader_Frag = "#version 440 core\n""layout(location = 0) out vec4 outputColor;\n""void main()\n""{\n""    outputColor = vec4(1.0, 1.0, 1.0, 1.0);\n""}\0";

const char* coloredShader_Vert = "#version 460 core\n""layout(location = 0) in vec3 vertexPosition;\n""layout(location = 1) in vec3 vertexColor;\n""smooth out vec3 ioVertexColor;\n""void main()\n""{\n""	gl_Position = vec4(vertexPosition, 1.0);\n""	ioVertexColor = vertexColor;\n""}\0";
const char* coloredShader_Frag = "#version 460 core\n""layout(location = 0) out vec4 outputColor;\n""smooth in vec3 ioVertexColor;\n""void main()\n""{\n""	outputColor = vec4(ioVertexColor, 1.0);\n""}\0";


const char* col3_Vert = "#version 460 core\n""layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0\n""layout (location = 1) in vec3 aColor; // the color variable has attribute position 1\n""  \n""out vec3 ourColor; // output a color to the fragment shader\n""void main()\n""{\n""    gl_Position = vec4(aPos, 1.0);\n""    ourColor = aColor; // set ourColor to the input color we got from the vertex data\n""} \0";
const char* col3_Frag = "#version 460 core\n""out vec4 FragColor;  \n""in vec3 ourColor;\n""  \n""void main()\n""{\n""    FragColor = vec4(ourColor, 1.0);\n""}\0";

const char* pain_Vert = "#version 410\n""in vec3 vertex_position;\n""void main() {\n""	gl_Position = vec4(vertex_position, 1.0);\n""}\0";
const char* pain_Frag = "#version 410\n""uniform vec4 inputColour;\n""out vec4 fragColour;\n""void main() {\n""	fragColour = inputColour;\n""}\0";

const char* hope_Vert = "#version 460 core\n""layout(location = 0) in vec3 vertex_position;\n""layout(location = 1) in vec3 vertex_colour;\n""out vec3 colour;\n""void main() {\n""  colour = vertex_colour;\n""  gl_Position = vec4(vertex_position, 1.0);\n""}\0";
const char* hope_Frag = "#version 460 core\n""in vec3 colour;\n""out vec4 frag_colour;\n""void main() {\n""  frag_colour = vec4(colour, 1.0);\n""}\0";

class Shader
{
    public:
    unsigned int ID;
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader(const char* VertexShaderLoader, const char* FragmentShaderLoader, const std::string choice)
    {
        if (choice == "FILE")
        {
            // 1. retrieve the vertex/fragment source code from filePath
            std::string vertexCode;
            std::string fragmentCode;
            std::ifstream vShaderFile;
            std::ifstream fShaderFile;
            // ensure ifstream objects can throw exceptions:
            vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            try
            {
                // open files
                vShaderFile.open(VertexShaderLoader);
                fShaderFile.open(FragmentShaderLoader);
                std::stringstream vShaderStream, fShaderStream;
                // read file's buffer contents into streams
                vShaderStream << vShaderFile.rdbuf();
                fShaderStream << fShaderFile.rdbuf();
                // close file handlers
                vShaderFile.close();
                fShaderFile.close();
                // convert stream into string
                vertexCode = vShaderStream.str();
                fragmentCode = fShaderStream.str();
            }
            catch (std::ifstream::failure& e)
            {
                std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
            }
            const char* vShaderCode = vertexCode.c_str();
            const char* fShaderCode = fragmentCode.c_str();
            // 2. compile shaders
            unsigned int vertex, fragment;
            // vertex shader
            vertex = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex, 1, &vShaderCode, NULL);
            glCompileShader(vertex);
            checkCompileErrors(vertex, "VERTEX");
            // fragment Shader
            fragment = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment, 1, &fShaderCode, NULL);
            glCompileShader(fragment);
            checkCompileErrors(fragment, "FRAGMENT");
            // shader Program
            ID = glCreateProgram();
            glAttachShader(ID, vertex);
            glAttachShader(ID, fragment);
            glLinkProgram(ID);
            checkCompileErrors(ID, "PROGRAM");
            // delete the shaders as they're linked into our program now and no longer necessary
            glDeleteShader(vertex);
            glDeleteShader(fragment);

        }

        eif(choice == "DIRECT")
        {
            const char* vShaderCode = VertexShaderLoader;
            const char* fShaderCode = FragmentShaderLoader;
            unsigned int vertex, fragment;
            // vertex shader
            vertex = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex, 1, &vShaderCode, NULL);
            glCompileShader(vertex);
            checkCompileErrors(vertex, "VERTEX");
            // fragment Shader
            fragment = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment, 1, &fShaderCode, NULL);
            glCompileShader(fragment);
            checkCompileErrors(fragment, "FRAGMENT");
            // shader Program
            ID = glCreateProgram();
            glAttachShader(ID, vertex);
            glAttachShader(ID, fragment);
            glLinkProgram(ID);
            checkCompileErrors(ID, "PROGRAM");
            // delete the shaders as they're linked into our program now and no longer necessary
            glDeleteShader(vertex);
            glDeleteShader(fragment);

        }
    }
    // activate the shader
    // ------------------------------------------------------------------------
    void use()
    {
        glUseProgram(ID);
    }
    // utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string& name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }
    // ------------------------------------------------------------------------
    void setInt(const std::string& name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }
    // ------------------------------------------------------------------------
    void setFloat(const std::string& name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }

private:
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(unsigned int shader, std::string type)
    {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
};





#endif // gShaders_HPP
