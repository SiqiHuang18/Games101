#version 330


uniform vec3 u_cam_pos;

uniform samplerCube u_texture_cubemap;

in vec4 v_position;
in vec4 v_normal;
in vec4 v_tangent;

out vec4 out_color;

void main() {
  // YOUR CODE HERE
  vec3 dir = -(u_cam_pos.xyz - v_position.xyz) + 2 * v_normal.xyz;
  out_color = texture(u_texture_cubemap, dir);
  out_color.a = 1;
}
