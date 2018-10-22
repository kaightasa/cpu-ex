init:
	li r1, 4
	li r2, 1
calc:
	addi r2, r2, 1
compare:
	cmpw r2, r1
	blt calc
