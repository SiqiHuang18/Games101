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
