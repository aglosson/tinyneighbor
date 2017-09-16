//#include "1x.inc"
//#include "2x.inc"
//#include "3x.inc"



// create porch negative shape for roof and cutting off front of house

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

			