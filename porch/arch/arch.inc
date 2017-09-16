#macro porch_arch(archType, numWallPanelsWide, archXPos, archWidth)
	#switch (0)
	#case (strcmp(archType, "square"))
		porch_arch_shape__square(numWallPanelsWide, archXPos, archWidth)
		#break
	#case (strcmp(archType, "round"))
		porch_arch_shape__round(numWallPanelsWide, archXPos, archWidth)
		#break
	#case (strcmp(archType, "roundedSquare"))
		porch_arch_shape__roundedSquare(numWallPanelsWide, archXPos, archWidth)
		#break
	#case (strcmp(archType, "pointed"))
		porch_arch_shape__pointed(numWallPanelsWide, archXPos, archWidth)
		#break
	#end
#end