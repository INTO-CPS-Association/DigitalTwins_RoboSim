map OA_1SM dmodel OA_1SM::mobileOA_M to pmodel Turtlebot3_Burger {
	operation move{
		action BaseLink::TBMotorController.av = av
		action BaseLink::TBMotorController.lv = lv
	}
	input event closestDistance?closest_distance {
		equation closest_distance == getCD(TBLiDAR.scan)
	}
	input event closestAngle?closest_angle {
		equation closest_angle == getCA(TBLiDAR.scan)
	}
	}

//function getCD(i:int, scan: LaserScan, closest_distance: real, closest_angle: real): real{
//	postcondition{
//		
//		if(closest_distance == 0)
//		then closest_distance == scan.range_max /\ closest_angle == 0
//		else{}
//		end
//		/\
//		if (i >= len(scan.ranges))
//		then result == closest_angle
//		else{}
//		end
//		
//	}
//}



function getCD(scan: LaserScan): real{
	
	
}
function getCA(scan: LaserScan): real{
	
	
}

datatype LaserScan{
	angle_min: real
	angle_max: real
	angle_increment: real
	time_increment: real
	scan_time: real
	range_min: real
	range_max: real
	ranges: Seq(real)
	intensities: Seq(real)
}

