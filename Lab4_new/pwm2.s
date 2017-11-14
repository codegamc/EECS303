
	.global main

	.extern wiringPiSetup
	.extern pinMode
	.extern softPwmCreate
	.extern softPwmWrite
	.extern delay
	.balign 4
	

main:
	
	push {ip, lr}
	bl	wiringPiSetup
	mov	r4, #7
	mov	r0, r4
	mov	r1, #1
	bl	pinMode
	mov	r4, #7
	mov	r0, r4
	mov	r1, #0
	mov	r2, #100
	bl	softPwmCreate
	mov r4, #0
	b	.L2
.L3:
	mov	r0, #7
	mov	r1, r4
	bl	softPwmWrite
	add	r4, r4, #1
	mov	r0, #40
	bl	delay
.L2:
	cmp	r4, #99
	ble	.L3
	b	.L4
.L5:
	mov	r0, #7
	mov	r1, r4
	bl	softPwmWrite
	sub	r4, r4, #1
	mov	r0, #40
	bl	delay
.L4:
	cmp	r4, #0
	bgt	.L5
	mov	r0, #7
	mov	r1, #0
	bl	softPwmWrite
	pop {ip, pc}

	
