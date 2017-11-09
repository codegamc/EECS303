	.arch armv6
	.eabi_attribute 27, 3
	.eabi_attribute 28, 1
	.fpu vfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"pwm2.c"
	.global	ledPin
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
main:
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
	b	.L2
.L3:
	mov	r2, #7
	ldr	r3, .L5
	ldr	r3, [r3]
	mov	r0, r2
	mov	r1, r3
	bl	softPwmWrite
	ldr	r3, .L5
	ldr	r3, [r3]
	add	r3, r3, #1
	ldr	r2, .L5
	str	r3, [r2]
	mov	r0, #20
	bl	delay
.L2:
	ldr	r3, .L5
	ldr	r3, [r3]
	cmp	r3, #99
	ble	.L3
	mov	r3, #7
	mov	r0, r3
	mov	r1, #0
	bl	softPwmWrite
	mov	r3, #0
	mov	r0, r3
	ldmfd	sp!, {fp, pc}
.L6:
	.align	2
.L5:
	.word	brightness
	.size	main, .-main
	.ident	"GCC: (Raspbian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
