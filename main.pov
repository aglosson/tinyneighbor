#version 3.7;
global_settings {  assumed_gamma 1.0 }

#declare idk = 3;

#include "porch/arch/shape/square.inc"
#include "porch/arch/shape/round.inc"
#include "porch/arch/shape/roundedSquare.inc"
#include "porch/arch/shape/pointed.inc"

#include "porch/arch/arch.inc"
#include "porch/arch/1x.inc"
#include "porch/arch/2x.inc"
#include "porch/arch/3x.inc"

#include "porch/porch.inc"
#include "porch/1x.inc"
#include "porch/2x.inc"
#include "porch/3x.inc"

#include "roof/roof.inc"

#include"math.inc"
#include "transforms.inc"
#include "analytical_g.inc"


camera {
//	orthographic
	location <-15, 30, -100>
	look_at <15, 0, 0>
//	angle 80
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
        
#local randSeed = seed(now * 100000);
#declare r = (floor(128 * rand(randSeed)) + 127) / 255;
#declare g = (floor(128 * rand(randSeed)) + 127) / 255;
#declare b = (floor(128 * rand(randSeed)) + 127) / 255;

#declare r2 = (floor(128 * rand(randSeed)) + 127) / 255;
#declare g2 = (floor(128 * rand(randSeed)) + 127) / 255;
#declare b2 = (floor(128 * rand(randSeed)) + 127) / 255;

#declare wallColor = rgb<r, g, b>;
#debug concat("R: ", str(r, 0, 2), "\n")
#debug concat("G: ", str(g, 0, 2), "\n")
#debug concat("B: ", str(b, 0, 2), "\n")

#local numDoorPositions = 3;
#declare doorPosition = ceil(numDoorPositions * rand(randSeed));
#debug concat("Porch position: ", str(doorPosition, 0, 2), "\n")

#declare wallWidth = 20;
#declare wallHeight = 20;
#declare wallThickness = 3;
#declare columnThickness = 3;
#declare headerThickness = 3;

#declare overhang = 5;
#declare pitch = (20 * rand(randSeed)) + 15;
#declare tileType = "solid";

box {
	<0, 0, wallWidth> <wallWidth * 3, wallWidth, wallWidth * 4>
	texture {
		pigment {
			rgb<r2, g2, b2>
		}
	}
}

union {
object {
	roof(60, 60, pitch, overhang, tileType)
	translate <0, wallWidth, wallWidth>
	texture {
		pigment {
			rgb<r2, g2, b2>
		}
	}
}

object { porch(wallWidth, wallHeight, wallThickness, columnThickness) }
}








