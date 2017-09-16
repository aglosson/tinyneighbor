#macro porch__1x(archType)
	#local archXPos = columnThickness;
	#local archWidth = wallWidth - (columnThickness * 2);
	
	#debug concat("R: ", str(r, 0, 2), "\n")
	#debug concat("G: ", str(g, 0, 2), "\n")
	#debug concat("B: ", str(b, 0, 2), "\n")
	
	#local arch = difference {
					box { <0, 0, 0>, <wallWidth, wallHeight, wallThickness> }
					porch_arch(archType, 1, archXPos, archWidth)
				}

	object {	
		union {
			// left
			object {
				arch
				rotate <0, -90, 0>
				translate <columnThickness, 0, 0>
			}
			
			// front
			arch
			
			// right
			object {
				arch
				rotate <0, -90, 0>
				translate <wallWidth, 0, 0>
			}
		}
		texture {
			pigment {
				wallColor
			}
		}
	}
#end