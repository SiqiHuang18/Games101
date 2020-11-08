cmake_minimum_required(VERSION 3.14)
project(RayTracing)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(RayTracing main.cpp Object.hpp Vector.cpp Vector.hpp Sphere.hpp global.hpp Triangle.hpp Scene.cpp
        Scene.hpp Light.hpp AreaLight.hpp BVH.cpp BVH.hpp Bounds3.hpp Ray.hpp Material.hpp Intersection.hpp
        Renderer.cpp Renderer.hpp)



find_package(OpenMP REQUIRED)
if(OPENMP_FOUND)  
	message("OPENMP FOUND")  
	target_link_libraries(RayTracing PUBLIC OpenMP::OpenMP_CXX)
endif()  
