#macro porch__1x(archType)
	#local archXPos = columnThickness;
	#local archWidth = wallWidth - (columnThickness * 2);

	difference {
		box { <0, 0, 0>, <wallWidth, wallHeight, wallThickness> }
		porch_arch(archType, 1, archXPos, archWidth)
	}
#end