#comment test....
start:
	li r3, 0x4000
	li r4, 2
	#shift left...
	slw r3, r3, r4
#shift right...
	srw r3, r3, r4
