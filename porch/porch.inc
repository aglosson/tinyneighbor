//#include "1x.inc"
//#include "2x.inc"
//#include "3x.inc"

#declare wallWidth = 10;
#declare wallHeight = 10;
#declare wallThickness = 2;

#declare columnThickness = 2;

// create porch negative shape for roof and cutting off front of house

#macro porch()
	#local numPorchTypes = 3;
	#local randSeed = seed(now * 100000);
	#local porchType = numPorchTypes * ceil(rand(randSeed));

	#debug concat("Porch type: ", str(porchType, 0, 2), "\n")

	#switch (porchType)
	#case (1)
		porch_1x()
		#break
	#case (2)
		porch_2x()
		#break
	#case (3)
		porch_3x()
		#break
	#end
#end

			