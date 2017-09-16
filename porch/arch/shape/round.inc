#macro porch_arch_shape__round(numWallPanelsWide, xPos, archWidth)
	#local cylinderRadius = archWidth / 2;
	#local cylinderY = wallHeight - headerThickness - cylinderRadius;
	#local cylinderX = xPos + cylinderRadius;
	
	#local box1_x = xPos;
	#local box1_y = -wallWidth;
	#local box1_z = -wallWidth;
	
	#local box2_x = xPos + archWidth;
	#local box2_y = cylinderY;
	#local box2_z = wallWidth * 2;

	union {
		cylinder {<cylinderX, cylinderY, -wallWidth>, <cylinderX, cylinderY, wallWidth * 2>, cylinderRadius}
		box {<box1_x, box1_y, box1_z>, <box2_x, box2_y, box2_z>}
	}
#end