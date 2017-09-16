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


camera {
	location <-20, 20, -50>
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
        
#local randSeed = seed(now * 100000);
#declare r = (floor(128 * rand(randSeed)) + 127) / 255;
#declare g = (floor(128 * rand(randSeed)) + 127) / 255;
#declare b = (floor(128 * rand(randSeed)) + 127) / 255;

#declare wallColor = rgb<r, g, b>;
#debug concat("R: ", str(r, 0, 2), "\n")
#debug concat("G: ", str(g, 0, 2), "\n")
#debug concat("B: ", str(b, 0, 2), "\n")

#declare wallWidth = 10;
#declare wallHeight = 10;
#declare wallThickness = 2;
#declare columnThickness = 2;
#declare headerThickness = 2;
object { porch(wallWidth, wallHeight, wallThickness, columnThickness) }




