#macro porchSteps(stepsWidth)

	#if (numPorchSteps > 1)
		#local stepss =
			union {
				#for (i, 0, numPorchSteps - 1, 1)
					object {
						box { <0, 0, 0> <stepsWidth, -porchStepRise * (numPorchSteps - i), -porchStepRun> }
						translate <0, -porchStepRise * i, -porchStepRun * i>
					}
				#end
			};
	#end
	
	#if (numPorchSteps = 1)
		#local stepss =
			object {
				box { <0, 0, 0> <stepsWidth, -porchStepRise, -porchStepRun> }
			};
	#end
	
	#if (numPorchSteps > 0)
		#switch(0)
			#case(strcmp(porchEntranceDirection, "front"))
				object {
					stepss
				}
			#break
			
			#case(strcmp(porchEntranceDirection, "left"))
				object {
					stepss
					rotate <0, 90, 0>
					translate <0, 0, bodySectionWidth>
				}
			#break
			
			#case(strcmp(porchEntranceDirection, "right"))
				object {
					stepss
					rotate <0, -90, 0>
					translate <porchSectionsSpan * bodySectionWidth, 0, 0>
				}
			#break
		#end
	#end
#end