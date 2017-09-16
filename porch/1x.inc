#macro porch__1x(archType)
	#local archXPos = columnThickness;
	#local archWidth = wallWidth - (columnThickness * 2);
	
	#debug concat("R: ", str(r, 0, 2), "\n")
	#debug concat("G: ", str(g, 0, 2), "\n")
	#debug concat("B: ", str(b, 0, 2), "\n")

	object {	
		difference {
			box { <0, 0, 0>, <wallWidth, wallHeight, wallThickness> }
			porch_arch(archType, 1, archXPos, archWidth)
		}
		texture {
			pigment {
				wallColor
			}
		}
	}
#end