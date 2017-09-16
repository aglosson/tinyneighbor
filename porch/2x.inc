#macro porch__2x(archType)	

	#local numOfColumns = 3;
	#local numOfPanels = 2;
	#local totalWallWidth = numOfPanels * wallWidth;
	#local archWidth = (totalWallWidth - (numOfColumns * columnThickness)) / numOfPanels;
	
	#local arch1_xPos = columnThickness;
	#local arch2_xPos = columnThickness / 2;
	
	// for left and right porch walls
	#local arch1x_xPos = columnThickness;
	#local arch1x_width = wallWidth - (columnThickness * 2);
	#local arch1x = difference {
		box { <0, 0, 0>, <wallWidth, wallHeight, wallThickness> }
		porch_arch(archType, 1, arch1x_xPos, arch1x_width)
	}

	#local arch1 = difference {
		box { <0, 0, 0>, <wallWidth, wallHeight, wallThickness> }
		porch_arch(archType, 1, arch1_xPos, archWidth)
	}
	
	#local arch2 = difference {
		box { <0, 0, 0>, <wallWidth, wallHeight, wallThickness> }
		porch_arch(archType, 1, arch2_xPos, archWidth )
	}
	
	object {
		union {
			// left
			object {
				arch1x
				rotate <0, -90, 0>
				translate <columnThickness, 0, 0>
			}	
			
			// front
			object { arch1 }
			object {
				arch2
				translate <wallWidth, 0, 0>
			}
			
			// right
			object {
				arch1x
				rotate <0, -90, 0>
				translate <wallWidth * numOfPanels, 0, 0>
			}	
		}
		texture {
			pigment {
				wallColor
			}
		}
	}
#end