#ifndef PR3D_RENDER_H
#define PR3D_RENDER_H

#include <cglm/cglm.h>

/**
 * Defines the geometry of a 3D object. Only one Mesh is needed to draw many
 * of the same object.
 * Any IDs which are optional should be set to 0 if unused.
 */
struct PR3DMesh
{
    int num_vertices;

    // Vertex Buffer Object stores raw vertex data.
    unsigned int vbo;

    // Vertex Array Object stores vertex data state for how to render objects.
    unsigned int vao;

    // Optional - Element Buffer Object to draw vertices with indices.
    unsigned int ebo;

    // Optional - Stores the texture image if the mesh is textured.
    unsigned int texture;
};

/**
 * A 3D Mesh object which can be placed in the world and manipulated.
 */
struct PR3DMeshInstance
{
    struct PR3DMesh *mesh;
    mat4 transform;
};

/**
 * Clears the screen using the given color. Values are from 0-1.
 *
 * @param r
 * @param g
 * @param b
 * @param a
 */
void pr3d_clear_screen(float r, float g, float b, float a);

/**
 * Changes the color used to render objects.
 * This is designed to work with the default shader type specified in
 * PR3DShader. If you have changed the shader using pr3d_use_shader() using this
 * function may cause undefined behavior or segfault.
 *
 * @param r
 * @param g
 * @param b
 * @param a
 */
void pr3d_set_render_color(float r, float g, float b, float a);

/**
 * Creates a triangle mesh with the given vertex positions.
 *
 * @param[in] vertices
 */
struct PR3DMesh *pr3d_create_triangle(mat3 vertices);

/**
 * Creates a triangle mesh with the given vertex positions and colors.
 *
 * @param[in] vertices
 * @param[in] colors
 */
struct PR3DMesh *pr3d_create_triangle_vertex_color(mat3 vertices, mat3 colors);

/**
 * Creates a rectangle mesh.
 * Make sure to attach a texture to the returned mesh struct after creating it.
 *
 * @param[in] colors
 */
struct PR3DMesh *pr3d_create_rectangle(void);

/**
 * Creates a rectangle mesh with the given vertex colors.
 * Make sure to attach a texture to the returned mesh struct after creating it.
 *
 * @param[in] colors
 */
struct PR3DMesh *pr3d_create_rectangle_vertex_color(mat4 colors);

/**
 * Creates a cube mesh.
 * Make sure to attach a texture to the returned mesh struct after creating it.
 */
struct PR3DMesh *pr3d_create_cube(void);

/**
 * Renders a mesh to the screen at a position.
 *
 * @param[in] mesh
 * @param vec3 position The XYZ position to render the mesh at.
 * @param vec3 rotation_axis The XYZ axis of the rotation.
 * @param float degrees The angle of rotation in degrees.
 * @param vec3 scale The XYZ scale to apply to the mesh.
 */
void pr3d_render_mesh(
    struct PR3DMesh *mesh, vec3 position, vec3 rotation_axis, float degrees,
    vec3 scale
);

/**
 * Cleans up the GL objects associated with the mesh and then frees it.
 */
void pr3d_delete_mesh(struct PR3DMesh *mesh);

#endif
