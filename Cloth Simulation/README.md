# Cloth Simulation

<h2 align="middle">Overview</h2>

<p>
Here I implemented a simulation and rendering of a cloth sheet. The cloth is built from a set of point masses and springs that account for 
structural, shearing and bending constraints and its motion is simulated via Verlet integration. It also handles the collision detection with 
sphere, plane and uses spatial hashing for self-collision detection. Finally I added Phong shader,texture shader and mirror shader to the cloth
with shader programs in Opengl.

</p>

<h2 align="middle">Part I: Masses and springs</h2>

Wire frame with all three constraints

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/cloth_construction/all_constraints.png" height = 100%, width =100%>


<h2 align="middle">Part II: Simulation</h2>

Simulate with low density

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/cloth_parameters/density/density_1.png" height = 100%, width =100%>

Simulate with high density

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/cloth_parameters/density/density_100.png" height = 100%, width =100%>

Simulate with low ks

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/cloth_parameters/ks/ks_500.png" height = 100%, width =100%>

Simulate with high ks

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/cloth_parameters/ks/ks_50000.png" height = 100%, width =100%>

cloth wih 4 pins

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/cloth_parameters/pinned4.png" height = 100%, width =100%>

<h2 align="middle">Part III: Collision </h2>

Cloth resting on sphere

ks = 500

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/collision/sphere_ks500.png" height = 100%, width =100%>

ks = 50000

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/collision/sphere_ks50000.png" height = 100%, width =100%>

Cloth resting on plane

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/collision/plane.png" height = 100%, width=100%>

<h2 align="middle">Part IV: Self-Collision </h2>

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/self_collision/init.png" height = 100%, width=100%>

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/self_collision/med.png" height = 100%, width=100%>

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/self_collision/final.png" height = 100%, width=100%>

<h2 align="middle">Part V: Shader </h2>

Shaders are programs on GPU that parallelize some parts of graphics pipeline. Vertex shader handles the transformation of each vertex in parallel，
and it passes the geometric information of vertices to the fragment shader. Fragment shader then combines the geometric information and light information
in a way that can simulate different materials' interatction with light, and output the resulting color onto the screen. 
Fragment shader 

Blinn-Phong shader

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/shaders/phong.png" height = 100%, width=100%>

Texture shader

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/shaders/texture.png" height = 100%, width=100%>

Mirror shader

<img src = "https://github.com/SiqiHuang18/Games101/blob/main/Cloth%20Simulation/images/shaders/mirror.png" height = 100%, width=100%>
