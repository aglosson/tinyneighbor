#macro porch(wallWidth, wallHeight, wallThickness, columnThickness)
	#local randSeed = seed(now * 100000);
	
	#local numArchTypes = 4;
	#local archTypes = array[numArchTypes] { "square", "round", "roundedSquare", "pointed" };
	#local archTypeIndex = floor(numArchTypes * rand(randSeed));
	#local archType = archTypes[archTypeIndex];
	#debug concat("Porch arch type: ", archType, "\n")

	#switch (porchSectionsSpan)
	#case (1)
		porch__1x(archType)
		#break
	#case (2)
		porch__2x(archType)
		#break
	#case (3)
		porch__3x(archType)
		#break
	#end
#end

			