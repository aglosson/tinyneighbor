#macro porch_arch_shape__pointed(numWallPanelsWide, xPos, archWidth)
	#local cylinderRadius = archWidth;
	#local cylinderY = wallHeight - headerThickness - (sin(45) * archWidth);
	
	#local cylinder1_x = xPos;
	#local cylinder2_x = xPos + archWidth;

	#local box_x1 = xPos;
	#local box_y1 = -wallWidth;
	#local box_z1 = -wallWidth;
	
	#local box_x2 = xPos + archWidth;
	#local box_y2 = cylinderY;
	#local box_z2 = wallWidth * 2;

	union {
		box {<box_x1, box_y1, box_z1>, <box_x2, box_y2, box_z2>}
		intersection {
			cylinder {<cylinder1_x, cylinderY, -wallWidth>, <cylinder1_x, cylinderY, wallWidth * 2>, cylinderRadius}
			cylinder {<cylinder2_x, cylinderY, -wallWidth>, <cylinder2_x, cylinderY, wallWidth * 2>, cylinderRadius}
		}
	}

#end