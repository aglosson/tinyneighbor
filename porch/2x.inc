#macro porch__2x(archType)	

	#local numOfColumns = 3;
	#local numOfPanels = 2;
	#local totalWallWidth = numOfPanels * wallWidth;
	#local archWidth = (totalWallWidth - (numOfColumns * columnThickness)) / numOfPanels;
	
	#local arch1XPos = columnThickness;
	#local arch2XPos = columnThickness / 2;

	#local arch1 = difference {
		box { <0, 0, 0>, <wallWidth, wallHeight, wallThickness> }
		porch_arch(archType, 1, arch1XPos, archWidth)
	}
	
	#local arch2 = difference {
		box { <0, 0, 0>, <wallWidth, wallHeight, wallThickness> }
		porch_arch(archType, 1, arch2XPos, archWidth )
	}
	
	union {
		object { arch1 }
		object {
			arch2
			translate <wallWidth, 0, 0>
		}
	}
#end