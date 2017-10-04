#macro porch(wallWidth, wallHeight, wallThickness, columnThickness)
	#local randSeed = seed(now * 100000);

	#local numPorchTypes = 3;
	#local porchType = ceil(numPorchTypes * rand(randSeed));
	#debug concat("Porch type: ", str(porchType, 0, 2), "\n")
	
	#local numArchTypes = 4;
	#local archTypes = array[numArchTypes] { "square", "round", "roundedSquare", "pointed" };
	#local archTypeIndex = floor(numArchTypes * rand(randSeed));
	#local archType = archTypes[archTypeIndex];
	#debug concat("Porch arch type: ", archType, "\n")

	#switch (porchType)
	#case (1)
		object {
			porch__1x(archType)
			translate <wallWidth * (doorPosition - 1), 0, 0>
		}
		#break
	#case (2)
		porch__2x(archType)
		#break
	#case (3)
		porch__3x(archType)
		#break
	#end
#end

			