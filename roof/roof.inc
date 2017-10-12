#macro roof(wid, dep, pitch, overhang, tileType)
		
	#local tileThickness = 1;
	#local tileWidth = 4;
	#local tileLength = 6;
	
	#local tilePanelWidth = 50;
	#local tilePanelHeight = 50;
	
	#local rotation = atand(tileThickness / tileLength);
	
	#local tile = object {
		difference {
			cylinder { <tileWidth / 2, tileThickness, 0>, <tileWidth / 2, tileThickness, tileLength>, (tileWidth / 2) } 
			cylinder { <tileWidth / 2, tileThickness, -tileLength>, <tileWidth / 2, tileThickness, tileLength * 2>, (tileWidth / 2) - tileThickness } 
		}
		texture {
			pigment {
				roofColor
			}
		}
		rotate <rotation, 0, 0>
	}
	
	#local panelBuffer = 50;
	#local til =
		union {
			#for (i, 0, 100, tileLength)
				#for (j, 0, 100, tileWidth) 
					object {
						tile
						translate < j, 0, i >
					}
				#end
			#end
		};
	
	// curved tile panel
//	#local tilePanel = object {
//		difference {
//			object { til }
//			box { <-panelBuffer, tileThickness, -panelBuffer> <tilePanelWidth + panelBuffer, -tileWidth, tilePanelHeight + panelBuffer> }
//		}
//	}
	
	// solid tile panel
	#local tilePanel = object {
		box { <0, 0, 0> <100, 1, 100> }
		texture {
			pigment {
				roofColor
			}
		}
	};
	
	#local frontPanel = object {
		difference {
			object {
				tilePanel
				rotate <-pitch, 0, 0>
				translate <-(overhang * 2), 0, -overhang>
			}
			union {
				object {
					box { <-100, -100, 0> <100, 100, 100> }
					translate <0, 0, dep / 2>
				}
				
				object {
					box { <-100, -100, 0> <100, 100, 100> }
					rotate <0, -45, 0>
				}
				
				object {
					box { <0, -100, -200> <100, 100, 100> }
					rotate <0, -45, 0>
					translate <0, 0, wid>
				}
			}
		}
	}
	
	#local leftPanel = object {
		difference {
			object {
				tilePanel
				rotate <0, 90, pitch>
				translate <-overhang, 0, 75>
			}
			union {
				object {
					box { <0, -100, -100> <100, 100, 100> }
					translate <wid / 2, 0, 0>
				}
				
				object {
					box { <-100, -100, 0> <100, 100, 100> }
					rotate <0, 45, 0>
					translate <0, 0, dep>
				}
				
				object {
					box { <0, -100, -100> <100, 100, 100> }
					rotate <0, 45, 0>
				}
			}
		}
	}
	
	#local backPanel = object {
		frontPanel
		rotate <0, 180, 0>
		translate <wid, 0, dep>
	}
	
	#local rightPanel = object {
		leftPanel
		rotate <0, 180, 0>
		translate <wid, 0, dep>
	}
	
	object {
		union {
			object { frontPanel }
			object { leftPanel }
			object { backPanel }
			object { rightPanel }
		}
	}
	
#end

			