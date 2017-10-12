#macro porch__1x(archType)
	#local archXPos = columnThickness;
	#local archWidth = wallWidth - (columnThickness * 2);
	
	#local arch = difference {
					box { <0, 0, 0>, <wallWidth, wallHeight, wallThickness> }
					porch_arch(archType, 1, archXPos, archWidth)
				}

	object {	
		union {
			union {
				// left
				object {
					arch
					rotate <0, -90, 0>
					translate <columnThickness, 0, 0>
				}
				
				// front
				arch
				
				// right
				object {
					arch
					rotate <0, -90, 0>
					translate <wallWidth, 0, 0>
				}
			}
			
			union {
				box { <0, 0, 0> <porchSectionsSpan * bodySectionWidth, -(porchStepRise * numPorchSteps), bodySectionWidth> }
				porchSteps(wallWidth)
			}
		}
		
		texture {
			pigment {
				accentColor1
			}
		}
	}
#end