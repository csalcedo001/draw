#ifndef DRAWABLE_SHAPE_IPP_
#define DRAWABLE_SHAPE_IPP_

#include "drawable/shape.hpp"

#include <vector>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
//#include <glm/gtx/transform.hpp> // after <glm/glm.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include <common/shader.hpp>
#include <common/texture.hpp>
#include <common/controls.hpp>
#include <common/text2D.hpp>

namespace drawable {

GLuint vertexbuffer;
// GLuint MatrixID;
GLuint ModelID, ViewID, ProjectionID;
GLuint lightPosID, lightColorID, objectColorID;
GLuint programID;
GLuint VertexArrayID;

const GLfloat square_shape[] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };

// GLfloat square_shape[6 * 2 * 3 * 3] = {};
// const GLfloat square_shape[] = {
//     -1.0f,-1.0f,-1.0f,
//     -1.0f,-1.0f, 1.0f,
//     -1.0f, 1.0f, 1.0f,
//      1.0f, 1.0f,-1.0f,
//     -1.0f,-1.0f,-1.0f,
//     -1.0f, 1.0f,-1.0f,
//      1.0f,-1.0f, 1.0f,
//     -1.0f,-1.0f,-1.0f,
//      1.0f,-1.0f,-1.0f,
//      1.0f, 1.0f,-1.0f,
//      1.0f,-1.0f,-1.0f,
//     -1.0f,-1.0f,-1.0f,
//     -1.0f,-1.0f,-1.0f,
//     -1.0f, 1.0f, 1.0f,
//     -1.0f, 1.0f,-1.0f,
//      1.0f,-1.0f, 1.0f,
//     -1.0f,-1.0f, 1.0f,
//     -1.0f,-1.0f,-1.0f,
//     -1.0f, 1.0f, 1.0f,
//     -1.0f,-1.0f, 1.0f,
//      1.0f,-1.0f, 1.0f,
//      1.0f, 1.0f, 1.0f,
//      1.0f,-1.0f,-1.0f,
//      1.0f, 1.0f,-1.0f,
//      1.0f,-1.0f,-1.0f,
//      1.0f, 1.0f, 1.0f,
//      1.0f,-1.0f, 1.0f,
//      1.0f, 1.0f, 1.0f,
//      1.0f, 1.0f,-1.0f,
//     -1.0f, 1.0f,-1.0f,
//      1.0f, 1.0f, 1.0f,
//     -1.0f, 1.0f,-1.0f,
//     -1.0f, 1.0f, 1.0f,
//      1.0f, 1.0f, 1.0f,
//     -1.0f, 1.0f, 1.0f,
//      1.0f,-1.0f, 1.0f
// };

void init_render() {
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    
    programID = LoadShaders( "../resources/StandardShading.vertexshader", "../resources/StandardShading.fragmentshader" );
    
    // MatrixID = glGetUniformLocation(programID, "MVP");
    ModelID = glGetUniformLocation(programID, "model");
    ViewID = glGetUniformLocation(programID, "view");
    ProjectionID = glGetUniformLocation(programID, "projection");

    lightPosID = glGetUniformLocation(programID, "lightPos");
    lightColorID = glGetUniformLocation(programID, "lightColor");
    objectColorID = glGetUniformLocation(programID, "objectColor");
    

    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(square_shape), square_shape, GL_STATIC_DRAW);
}

void cleanup_render() {
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteVertexArrays(1, &VertexArrayID);
    glDeleteProgram(programID);
}

void render_square(double x, double y) {
    glm::mat4 translation = glm::translate(glm::mat4(), glm::vec3(x, y, 0.0f));
    glm::mat4 scaling = glm::scale(glm::vec3(1.0f, 1.0f, 1.0f));

    // Omitted rotation
    
    glm::mat4 ProjectionMatrix = getProjectionMatrix();
    glm::mat4 ViewMatrix = getViewMatrix();
    glm::mat4 ModelMatrix = translation * scaling;
    
    glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;
    
    glUseProgram(programID);
    
    // glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(ModelID, 1, GL_FALSE, &ModelMatrix[0][0]);
    glUniformMatrix4fv(ViewID, 1, GL_FALSE, &ViewMatrix[0][0]);
    glUniformMatrix4fv(ProjectionID, 1, GL_FALSE, &ProjectionMatrix[0][0]);

    glm::vec3 lightPos = glm::vec3(0.0f, -5.0f, 5.0f);
    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 objectColor = glm::vec3(0.2f, 0.5f, 0.2f);

    glUniform3fv(lightPosID, 1, &lightPos[0]);
    glUniform3fv(lightColorID, 1, &lightColor[0]);
    glUniform3fv(objectColorID, 1, &objectColor[0]);

    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    
    // 1st attribute buffer : positions
    glVertexAttribPointer(
       0,                  // attribute 0.
       3,                  // size
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       6 * sizeof(GL_FLOAT),                  // stride
       (void*)0            // array buffer offset
    );
    glEnableVertexAttribArray(0);
    // 2nd attribute buffer : normals
    glVertexAttribPointer(
       1,                  // attribute 1.
       3,                  // size
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       6 * sizeof(GL_FLOAT),                  // stride
       (void*)(3 * sizeof(GL_FLOAT))  // array buffer offset
    );
    glEnableVertexAttribArray(1);
    
    glDrawArrays(GL_TRIANGLES, 0, 6 * 2 * 3); // = 36

    glDisableVertexAttribArray(0);
}

void render_text(int e, double x, double y) {
    char text[256];
    sprintf(text,"%d", e );
    printText2D(text, x, y, 0.2);
}

void render_shape(int e, double x, double y) {
    render_square(x, y);
    render_text(e, x, y);
}

void render_shape(std::vector<int> &v, double x, double y) {
    for (float i = 0; i < v.size(); i++) {
        render_shape(v[i], i + x + (1 - v.size()) / 2.0f, y);
    }
}

} // namespace drawable

#endif // DRAWABLE_SHAPE_IPP_
