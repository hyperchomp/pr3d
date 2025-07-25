#ifndef PR3D_CAMERA_H
#define PR3D_CAMERA_H

#include <cglm/cglm.h>

/**
 * A camera for viewing the scene.
 * The struct values should be initialized and updated with the framework's
 * provided helper functions. Doing otherwise may cause undefined behavior.
 */
struct PR3DCamera
{
    mat4 view;       ///< The position of the camera stored as a view matrix.
    mat4 projection; ///< The camera's projection matrix for fov, clipping, etc.

    vec3 position;
    vec3 front;
    vec3 right;
    vec3 up;

    float yaw;
    float pitch;
    float fov; ///< Camera fov in degrees
    float move_speed;
    float look_sensitivity;
};

/**
 * Camera movement directions to obfuscate movement from input.
 */
enum PR3DCameraMoveDirection
{
    PR3D_CAMERA_FORWARD,
    PR3D_CAMERA_BACKWARD,
    PR3D_CAMERA_RIGHT,
    PR3D_CAMERA_LEFT
};

/**
 * Initializes the view (position) and projection matrices for the camera. This
 * sets the camera's position to {0, 0, 0}.
 *
 * @param cam[in,out] An uninitialized PR3DCamera struct.
 * @param fov_degrees The vertical fov for the camera in degrees.
 * @param move_speed Speed value to use when moving the camera.
 */
void pr3d_init_camera(
    struct PR3DCamera *cam, float fov_degrees, float move_speed
);

/**
 * Sends the view and projection matrices to the shader every frame.
 *
 * @param cam[in,out]
 */
void pr3d_update_camera(struct PR3DCamera *cam);

/**
 * Smoothly moves the camera in a given direction using its speed.
 * This uses fly camera movement, meaning forward and backward are relative to
 * the camera's pitch and yaw.
 *
 * @param cam[in,out]
 * @param move_dir
 * @param delta_time
 */
void pr3d_move_camera_fly(
    struct PR3DCamera *cam, enum PR3DCameraMoveDirection move_dir,
    double delta_time
);

/**
 * Smoothly moves the camera by the given amounts in yaw and pitch.
 *
 * @param cam[in,out]
 * @param yaw The amount to move the camera in yaw.
 * @param pitch The amount to move the camera in pitch.
 */
void pr3d_move_camera_look(struct PR3DCamera *cam, float yaw, float pitch);

/**
 * Updates the camera's vertical fov.
 *
 * @param cam[in,out]
 * @param fov_degrees The vertical fov for the camera in degrees.
 */
void pr3d_set_camera_fov(struct PR3DCamera *cam, float fov_degrees);

#endif
