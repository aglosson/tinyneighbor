#version 3.7;
global_settings {  assumed_gamma 1.0 }

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
#include "porch/steps.inc"

#include"math.inc"
#include "transforms.inc"
#include "analytical_g.inc"


camera {
//	orthographic
	location <18, 10, -50>
	look_at <15, 0, 0>
//	angle 80
}

  light_source {
    <0, 50, -50>
    color rgb<1,1,1>
    area_light <50, 0, 0>, <0, 0, 50>, 5, 5
    adaptive 1
    jitter
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

#declare r3 = (floor(128 * rand(randSeed)) + 127) / 255;
#declare g3 = (floor(128 * rand(randSeed)) + 127) / 255;
#declare b3 = (floor(128 * rand(randSeed)) + 127) / 255;

#declare r4 = (floor(128 * rand(randSeed)) + 127) / 255;
#declare g4 = (floor(128 * rand(randSeed)) + 127) / 255;
#declare b4 = (floor(128 * rand(randSeed)) + 127) / 255;

#declare wallThickness = 2;
#declare columnThickness = 2;
#declare headerThickness = 2;

#declare overhang = 3;
#declare pitch = (20 * rand(randSeed)) + 15;
#declare tileType = "solid";

/////
#declare bodySectionWidth = 12;
#declare numDoorPositions = 3;
#declare bodyWidth = bodySectionWidth * numDoorPositions;
#declare bodyHeight = 10;

// decide what section the door goes in
#local numPositions = floor(bodyWidth / bodySectionWidth);
#declare doorPosition = ceil(numDoorPositions * rand(randSeed));
#debug concat("Door position: ", str(doorPosition, 0, 2), "\n")


// decide how many sections wide the porch is
#declare porchSectionsSpan = ceil(numDoorPositions * rand(randSeed));
#debug concat("Porch sections span: ", str(porchSectionsSpan, 0, 2), "\n")


// decide where the porch goes
#switch(porchSectionsSpan)
	// porch of width 1 always goes where the door is
	#case(1)
		#declare porchPosition = doorPosition;
		#break
	// porch of width 2 has multiple possible positions
	#case(2)
		#switch(doorPosition)
			// if the door is at the first position, so is the porch
			#case(1)
				#declare porchPosition = 1;	
				#break
			// if the door is in the middle, the porch can be either at
			// the left of the house or the right
			#case(2)
				#local rand_pos = rand(randSeed);
				#if (rand_pos < 0.5)
					#declare porchPosition = 1;
				#end
				#if(rand_pos >= 0.5)
					#declare porchPosition = 2;
				#end
				
				#break
			// if the door is at the end of the house, the porch
			// should also be at the end of the house
			#case(3)
				#declare porchPosition = 2;
				#break
		#end
		#break
	// porch of width 3 always starts at the first position
	#case(3)
		#declare porchPosition = 1;
		#break
#end
#debug concat("Porch position: ", str(porchPosition, 0, 2), "\n")


// decide what direction the porch entrance is in
// porchEntranceDirections are "left", "front", "right";

// default entrance direction to front
#declare porchEntranceDirection = "front";

// entrance direction can change in some cases
#switch(porchSectionsSpan)
	#case(1)
		#if(porchPosition = 1)
			#local rand_dir = rand(randSeed) * 2;
			#if (rand_dir <= 1)
				#declare porchEntranceDirection = "front";
			#end
			#if (rand_dir > 1 & rand_dir <= 2)
				#declare porchEntranceDirection = "right";
			#end
		#end
		
		#if(porchPosition = 2)
			#local rand_dir = rand(randSeed) * 3;
			#if (rand_dir <= 1)
				#declare porchEntranceDirection = "left";
			#end
			#if (rand_dir > 1 & rand_dir <= 2)
				#declare porchEntranceDirection = "front";
			#end
			#if (rand_dir <= 3)
				#declare porchEntranceDirection = "right";
			#end
		#end
		
		#if(porchPosition = 3)
			#local rand_dir = rand(randSeed) * 2;
			#if (rand_dir <= 1)
				#declare porchEntranceDirection = "left";
			#end
			#if (rand_dir > 1 & rand_dir <= 2)
				#declare porchEntranceDirection = "front";
			#end
		#end

		#break
	#case(2)
		#if(porchPosition = 1)
			#local rand_dir = rand(randSeed) * 2;
			#if (rand_dir <= 1)
				#declare porchEntranceDirection = "front";
			#end
			#if (rand_dir > 1 & rand_dir <= 2)
				#declare porchEntranceDirection = "right";
			#end
		#end
		
		#if(porchPosition = 2)
			#local rand_dir = rand(randSeed) * 2;
			#if (rand_dir <= 1)
				#declare porchEntranceDirection = "left";
			#end
			#if (rand_dir > 1 & rand_dir <= 2)
				#declare porchEntranceDirection = "front";
			#end
		#end

		#break
#end
#debug concat("Porch entrance direction: ", porchEntranceDirection, "\n")

// decide if the porch is inset into the house or not
#local rand_inset = rand(randSeed);
#if (rand_inset < 0.5)
	#declare isPorchInset = 0;
#end
#if(rand_inset >= 0.5)
	#declare isPorchInset = 1;
#end
#debug concat("Porch inset: ", str(isPorchInset, 0, 2), "\n")


//#declare porchColumnThickness;
//#declare porchHeaderThickness;
//#declare porchWallPanelWidth;
//#declare porchWallThickness;
//
//#declare roofOverhang;
//#declare roofPitch;
//#declare roofTileType; // curved, wood shingle, solid
//
#declare bodyColor1 = color <r, g, b>;
//#declare bodyColor2;
#declare roofColor = color <r2, g2, b2>;
#declare accentColor1 = color <r3, g3, b3>;
#declare accentColor2 = color <r4, g4, b4>;

// house body
object {
	difference {
		box {
			<0, 0, bodySectionWidth> <bodyWidth, bodyHeight, bodySectionWidth + bodyWidth>
		}
		
		box {
			<wallThickness, -1, wallThickness + bodySectionWidth> <bodyWidth - wallThickness, bodyHeight + 1, bodyWidth - wallThickness>
		}
		
		box {
			<columnThickness + 1, -1, bodySectionWidth - 1> <bodySectionWidth - columnThickness - 1, bodyHeight - headerThickness - 1, bodySectionWidth + wallThickness + 1>
			translate <bodySectionWidth * (doorPosition - 1), 0, 0>
		}
	}
	
	texture {
		pigment {
			bodyColor1
		}
	}
}

// house roof
object {
	roof(bodyWidth, bodyWidth, pitch, overhang, tileType)
	translate <0, bodyHeight, bodySectionWidth>
	texture {
		pigment {
			roofColor
		}
	}
}

// indoor light
light_source {
    <bodyWidth / 2, bodyHeight / 2, (bodyWidth / 2) + bodySectionWidth>
    color rgb<1,1,1>
    area_light <1, 0, 0>, <0, 0, 1>, 1, 1
    adaptive 1
    jitter
}

// temp ground
//object {
//	box {
//		<-1, 0, -1> <bodyWidth + 1, -1, bodyWidth + 1>
//	}
//	
//	texture {
//		pigment {
//			color <(floor(128 * rand(randSeed)) + 127) / 255, (floor(128 * rand(randSeed)) + 127) / 255, (floor(128 * rand(randSeed)) + 127) / 255>
//		}
//	}
//}

// porch steps
#declare numPorchSteps = floor(4 * rand(randSeed)); // 0 - 3
#debug concat("Porch steps: ", str(numPorchSteps, 0, 2), "\n")
#declare porchStepRise = 1;
#declare porchStepRun = 3;
#declare porchStepsHeight = porchStepRise * numPorchSteps;

// porch
object {
	roof(porchSectionsSpan * bodySectionWidth, bodyWidth + bodySectionWidth, pitch, overhang, tileType)
	translate <bodySectionWidth * (porchPosition - 1), bodyHeight, 0>
}

object {
	porch(bodySectionWidth, bodyHeight, wallThickness, columnThickness)
	translate <bodySectionWidth * (porchPosition - 1), 0, 0>
}


// house foundation
object {
	box { <0, 0, 0> <bodyWidth, -(porchStepRise * numPorchSteps), bodyWidth> }
	translate <0, 0, bodySectionWidth>
	texture {
		pigment {
			accentColor1
		}
	}
}








