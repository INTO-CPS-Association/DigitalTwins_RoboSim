package OA_1SM import Mathematics::*


interface ObstacleEvents {
	event closestDistance : real
	event closestAngle : real
}




interface Move {
	move ( av : real , lv : real )
}

controller mobileOA_C {
	cycleDef cycle == 0.1
	uses ObstacleEvents 
	requires Move
	sref stm_ref1 = ObstacleAvoidance
connection mobileOA_C on closestDistance to stm_ref1 on closestDistance
	connection mobileOA_C on closestAngle to stm_ref1 on closestAngle
}

stm ObstacleAvoidance {
	const pi : real = 3.14159
	const randcoef : real = 0.2
	var sign : nat = 1
	var closest_angle : real = 0
	var closest_distance : real = 0
	const min_range : real = 0.2
	const max_range : real = 1.0
	const av_wander : real = 0.7
	const lv_wander : real = 0.6
	var lv : real = 0.0
	var av: real = 0.0
	var NOA_Move : vector ( real , 2 )
	var current_speed : real
	var vel: vector(real,2) //TODO remove once we can just directly ouput values in code generator
	clock T
	var turn : boolean = true
	var wander_done : boolean = false
	var OA_done : boolean = false
	input context { uses ObstacleEvents }
	output context {requires Move  }
	cycleDef cycle == 0.1
	state Wander {
		initial i0
		state Turn {
			entry vel[1] = av_wander*sign; vel[2] = 0.0; NOA_Move = vel
		}
		state Move_Forward {
			entry vel[1] = 0.0; vel[2] = lv_wander; NOA_Move = vel
		}
		state s0 {
		}
		transition t0 {
			from i0
			to s0
		}
		transition t1 {
			from Turn
			to Move_Forward
			condition since ( T ) >= randcoef
			
			action  NOA_Move = vel ; # T ; randcoef = randomcoef ( ) ; sign = random_sign ( ); turn = false; wander_done = true
		}
		transition t2 {
			from Move_Forward
			to Turn
			condition since ( T ) >= randcoef
			action  NOA_Move = vel ; # T ; randcoef = randomcoef ( ); turn = true; wander_done = true
		}
		transition t3 {
			from Move_Forward
			to Move_Forward
			condition since ( T ) < randcoef
			action wander_done = true
		}
		transition t4 {
			from Turn
			to Turn
			condition since ( T ) < randcoef
			action wander_done = true
		}
	transition t5 {
			from s0
			to Turn
			condition turn
		}
		transition t6 {
			from s0
			to Move_Forward
			condition not turn
		}
	}

state OA{
		junction j0
	junction j1
	junction j2
	junction j3
	state VHFEnabled {
		}
		initial i0
		junction j4
		transition t0 {
		from j1
		to j0
		condition ( closest_distance >= min_range ) /\ ( closest_distance < max_range ) /\  (abs ( closest_angle) <= 90) 
		action current_speed = NOA_Move [ 2 ]
	}
	transition t3 {
		from j0
		to j3
		condition ( closest_angle > 0 )
		action av = ( closest_angle - 100 ) * pi / 180 
	}
	transition t4 {
		from j0
		to j3
		condition ( closest_angle <= 0 )
		action av = ( closest_angle + 100 ) * pi / 180
	}
	transition t5 {
		from VHFEnabled
		to j1
		condition $ closestAngle ? closest_angle /\ $ closestDistance ? closest_distance 
	}
	transition t6 {
		from j1
		to VHFEnabled
		condition not ( ( closest_distance >= min_range ) /\ ( closest_distance < max_range ) /\  abs ( closest_angle) <= 90  )
		action lv = NOA_Move [ 2 ] ; av = NOA_Move [ 1 ]; OA_done = true
	}
	transition t9 {
		from j4
		to j2
		condition abs( closest_angle) < 30 
	}
	transition t10 {
		from j2
		to VHFEnabled
		condition ( closest_distance < 0.4 )
		action lv = - 0.4; OA_done = true
	}
	transition t11 {
		from j2
		to VHFEnabled
		condition ( closest_distance >= 0.4 )
		action OA_done = true
	}
	transition t12 {
		from j3
		to j4
		condition ( closest_distance > 0.4 )
		action lv = current_speed / 2
	}
	transition t13 {
		from j3
		to j4
		condition ( closest_distance <= 0.4 )
		action lv = 0.0
	}
transition t1 {
			from i0
			to VHFEnabled
		}
	transition t2 {
			from j4
			to VHFEnabled
			condition abs( closest_angle) >= 30 
			action OA_done = true
		}
	}
	

	initial i1


	transition t2 {
		from i1
		to Wander
	}

transition t0 {
		from Wander
		to OA
		condition wander_done == true
		action wander_done = false
	}
	transition t1 {
		from OA
		to Wander
		condition OA_done == true
		action OA_done = false; $move(av,lv); exec
	}
transition t3 {
		from OA
		to Wander
		condition not $closestDistance \/ not $closestAngle
		action $move(NOA_Move[0],NOA_Move[1]); exec
	}
}







module mobileOA_M {
	robotic platform Turtlebot3_Burger {
	uses ObstacleEvents  provides Move}
	cref ctrl_ref0 = mobileOA_C
	cycleDef cycle == 0.1


	connection Turtlebot3_Burger on closestAngle to ctrl_ref0 on closestAngle ( _async )
	connection Turtlebot3_Burger on closestDistance to ctrl_ref0 on closestDistance ( _async )
}

function abs() : real{
	
}

function random_sign(): nat{
	
}

