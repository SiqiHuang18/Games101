#version 330

uniform vec4 u_color;
uniform vec3 u_cam_pos;
uniform vec3 u_light_pos;
uniform vec3 u_light_intensity;

in vec4 v_position;
in vec4 v_normal;
in vec2 v_uv;

out vec4 out_color;

void main() {
  // YOUR CODE HERE
  
  // (Placeholder code. You will want to replace it.)
    float r = distance(v_position.xyz, u_light_pos);
    vec3 view_dir = normalize(u_light_pos.xyz - u_cam_pos);
    vec3 light_dir = normalize(u_light_pos.xyz - v_position.xyz);
    vec3 h = normalize(view_dir + light_dir);
    out_color.xyz = 0.1 + (u_light_intensity/dot(r,r))*max(0,dot(v_normal.xyz,light_dir)) + (u_light_intensity/dot(r,r))*pow(max(0,dot(v_normal.xyz,h)),4);
    out_color.a = 1;
}

