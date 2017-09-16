#macro porch_arch_shape__roundedSquare(numWallPanelsWide, xPos, archWidth)
	#local cylinderRadius = 0.1;
	#local cylinderY = wallHeight - headerThickness - cylinderRadius;
	
	#local cylinder1_x = xPos + cylinderRadius;
	#local cylinder2_x = xPos + archWidth - cylinderRadius;
	
	// top box between cylinders
	#local box1_x1 = cylinder1_x;
	#local box1_y1 = cylinderY;
	#local box1_z1 = -wallWidth;
	
	#local box1_x2 = cylinder2_x;
	#local box1_y2 = wallHeight - headerThickness;
	#local box1_z2 = wallWidth * 2;
	
	// bottom box
	#local box2_x1 = xPos;
	#local box2_y1 = -wallWidth;
	#local box2_z1 = -wallWidth;
	
	#local box2_x2 = xPos + archWidth;
	#local box2_y2 = cylinderY;
	#local box2_z2 = wallWidth * 2;

	union {
		cylinder {<cylinder1_x, cylinderY, -wallWidth>, <cylinder1_x, cylinderY, wallWidth * 2>, cylinderRadius}
		cylinder {<cylinder2_x, cylinderY, -wallWidth>, <cylinder2_x, cylinderY, wallWidth * 2>, cylinderRadius}
		box {<box1_x1, box1_y1, box1_z1>, <box1_x2, box1_y2, box1_z2>}
		box {<box2_x1, box2_y1, box2_z1>, <box2_x2, box2_y2, box2_z2>}
	}
#end