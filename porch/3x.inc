#macro porch__3x(archType)	
	#local numOfColumns = 4;
	#local numOfPanels = 3;
	#local totalWallWidth = numOfPanels * wallWidth;
	#local archWidth = (totalWallWidth - (numOfColumns * columnThickness)) / numOfPanels;
	
	#local arch1XPos = columnThickness;
	#local arch2XPos = arch1XPos + archWidth + columnThickness;
	#local arch3XPos = arch2XPos + archWidth + columnThickness;
	
	// for left and right porch walls
	#local arch1x_xPos = columnThickness;
	#local arch1x_width = wallWidth - (columnThickness * 2);
	#local arch1x = difference {
		box { <0, 0, 0>, <wallWidth, wallHeight, wallThickness> }
		porch_arch(archType, 1, arch1x_xPos, arch1x_width)
	}

	object {
		union {
			union {
				// left
				object {
					arch1x
					rotate <0, -90, 0>
					translate <columnThickness, 0, 0>
				}	
				
				// front
				difference {
					box { <0, 0, 0>, <totalWallWidth, wallHeight, wallThickness> }	
					porch_arch(archType, 1, arch1XPos, archWidth)
					porch_arch(archType, 1, arch2XPos, archWidth)
					porch_arch(archType, 1, arch3XPos, archWidth)
				}
				
				// right
				object {
					arch1x
					rotate <0, -90, 0>
					translate <wallWidth * numOfPanels, 0, 0>
				}
				
				porchSteps(archWidth + (columnThickness * 2))
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