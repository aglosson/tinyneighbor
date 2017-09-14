#macro porch_arch_shape__square(numWallPanelsWide, xPos, archWidth)

	#local box1_x = xPos;
	#local box1_y = 0;
	#local box1_z = -wallWidth;
	
	#local box2_x = xPos + archWidth;
	#local box2_y = wallHeight - headerThickness;
	#local box2_z = wallWidth * 2;

	box {<box1_x, box1_y, box1_z>, <box2_x, box2_y, box2_z>}
#end