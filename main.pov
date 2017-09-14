#version 3.7;
global_settings {  assumed_gamma 1.0 }

#declare idk = 3;

#include "porch/arch/shape/square.inc"
#include "porch/arch/shape/round.inc"

#include "porch/arch/arch.inc"
#include "porch/arch/1x.inc"
#include "porch/arch/2x.inc"
#include "porch/arch/3x.inc"

#include "porch/porch.inc"
#include "porch/1x.inc"
#include "porch/2x.inc"
#include "porch/3x.inc"


camera {
	orthographic
	location <0, 0, -50>
	look_at <0, 0, 0>
	angle 80
}

light_source {
	<1500,2500,-2500>
	color rgb<1,1,1>
}

sky_sphere {
	pigment {
		color rgb<0.5,0.5,0.7>
	}
}


#declare wallWidth = 10;
#declare wallHeight = 10;
#declare wallThickness = 2;
#declare columnThickness = 2;
#declare headerThickness = 2;
object { porch(wallWidth, wallHeight, wallThickness, columnThickness) }



//#declare columnThickness = 2;
//#declare topThickness = columnThickness;
//
//#declare wallWidth = 10;
//#declare wallHeight = 10;
//#declare wallThickness = 2;

//#declare wall = box { <0, 0, 0>, <wallWidth, wallHeight, wallThickness> }
//#declare hole = box { <-(wallWidth - wallThickness), 0, 100>, <wallWidth - wallThickness, wallHeight - topThickness, -100> }
//
//#declare arch = object {
//	difference {
//		object {
//			wall
//			texture {
//				pigment {
//					rgb<0, 1, 1>
//					filter 0.5
//				}
//			}
//		}
//		object { hole }
//	}
//}
//

// object { wall }




//Pyramid	
//Define the coordinates of the vertices
//In this case the points are the vertices of a regular hexagon and an apex

#declare p1 = <1,0,0>;
#declare p2 = <1/2,sqrt(3)/2,0>;
#declare p3 = <-1/2,sqrt(3)/2,0>;
#declare p4 = <-1,0,0>;
#declare p5 = <-1/2,-sqrt(3)/2,0>;
#declare p6 = <1/2,-sqrt(3)/2,0>;
#declare p7 = <0,0,2>;

//List the faces
//In each case the first number is one plus the number of vertices on the face
//List the points IN ORDER around the face, repeating the first point at the end

#declare pyramid = union{
	polygon { 7, p1, p2, p3, p4, p5, p6, p1 } //This is the bottom
	polygon { 4, p1, p2, p7, p1 } //This is one of the triangular sides
	polygon { 4, p2, p3, p7, p2 }
	polygon { 4, p3, p4, p7, p3 }
	polygon { 4, p4, p5, p7, p4 }
	polygon { 4, p5, p6, p7, p5 }
	polygon { 4, p6, p1, p7, p6 }
}

//object {
//	pyramid
//}






