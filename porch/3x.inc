#macro porch__3x(archType)	
	#local numOfColumns = 4;
	#local numOfPanels = 3;
	#local totalWallWidth = numOfPanels * wallWidth;
	#local archWidth = (totalWallWidth - (numOfColumns * columnThickness)) / numOfPanels;
	
	#local arch1XPos = columnThickness;
	#local arch2XPos = arch1XPos + archWidth + columnThickness;
	#local arch3XPos = arch2XPos + archWidth + columnThickness;

	union {
		difference {
			box { <0, 0, 0>, <totalWallWidth, wallHeight, wallThickness> }	
			porch_arch(archType, 1, arch1XPos, archWidth)
			porch_arch(archType, 1, arch2XPos, archWidth)
			porch_arch(archType, 1, arch3XPos, archWidth)
		}
		texture {
			pigment {
				wallColor
			}
		}
	}
#end