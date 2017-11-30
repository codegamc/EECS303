
	.global _start
	.extern	ledPin
	.extern wiringPiSetup
	.extern pinMode
	.extern softPwmCreate
	.extern softPwmWrite
	.section	.rodata
	.align	2
	.type	ledPin, %object
	.size	ledPin, 4
ledPin:
	.word	7
	.global	brightness
	.bss
	.align	2
	.type	brightness, %object
	.size	brightness, 4
brightness:
	.space	4
	.text
	.align	2
	.global	main
	.type	main, %function
_start:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	bl	wiringPiSetup
	mov	r3, #7
	mov	r0, r3
	mov	r1, #1
	bl	pinMode
	mov	r3, #7
	mov	r0, r3
	mov	r1, #0
	mov	r2, #100
	bl	softPwmCreate
	mov r3, #0
	b	.L2
.L3:
	mov	r0, #7
	@ldr	r3, .L7
	@ldr	r3, [r3]
	@mov	r0, r2
	mov	r1, r3
	bl	softPwmWrite
	@ldr	r3, .L7
	@ldr	r3, [r3]
	add	r3, r3, #1
	@ldr	r2, .L7
	@str	r3, [r2]
	mov	r0, #40
	bl	delay
.L2:
	@ldr	r3, .L7
	@ldr	r3, [r3]
	cmp	r3, #99
	ble	.L3
	b	.L4
.L5:
	mov	r0, #7
	@ldr	r3, .L7
	@ldr	r3, [r3]
	@mov	r0, r2
	mov	r1, r3
	bl	softPwmWrite
	@ldr	r3, .L7
	@ldr	r3, [r3]
	sub	r3, r3, #1
	@ldr	r2, .L7
	@str	r3, [r2]
	mov	r0, #40
	bl	delay
.L4:
	@ldr	r3, .L7
	@ldr	r3, [r3]
	cmp	r3, #0
	bgt	.L5
	mov	r0, #7
	@mov	r0, r3
	mov	r1, #0
	bl	softPwmWrite
	mov	r3, #0
	mov	r0, r3
	ldmfd	sp!, {fp, pc}

	
