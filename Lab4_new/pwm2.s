	@defining entry point for the program
	.global main
	@defining external functions used in program
	.extern wiringPiSetup
	.extern pinMode
	.extern softPwmCreate
	.extern softPwmWrite
	.extern delay
	.balign 4
	

main:
	
	push {ip, lr}
	bl	wiringPiSetup @calling wiringPisetup
	mov	r4, #7 @stroing pin number on r4
	mov	r0, r4 @moving pin number to r0 since we need that as input 1 below
	mov	r1, #1 @moving value 1 onto r1 since that is the second input to pinMode and 1 defines it as output
	bl	pinMode @calling pinMode
	mov	r4, #7 
	mov	r0, r4 @getting pin number from r4 to be first input of softPwmCreate
	mov	r1, #0 @initial PWM value as second input
	mov	r2, #100 @PWM range as third
	bl	softPwmCreate
	mov r4, #0 @initialize the counter for the increasing phase of our PWM
	b	.L2 @branch to L2, this is situated below L3, because it checks wheter we should branch to L3 or L4 so each time we complete L3, it will fall through to here and do that check
.L3:
	mov	r0, #7 @put pin number as input 1 for softPwmWrite
	mov	r1, r4 @put current PWM value as input 2
	bl	softPwmWrite @ execute softPwmWrite
	add	r4, r4, #1 @increment PWM value so LED brightens
	mov	r0, #40 @want to delay for 40 milliseconds, so put value 40 as input to delay
	bl	delay @execute delay
.L2:
	cmp	r4, #99 @want to go through the entire range of the 100 PWM options, if the counter (r4) is less than 99, we go back to L3, otherwise, we go to L4
	ble	.L3 @repeat L3 whenever PWM brightness is less than or equal to 99
	b	.L4 @move on to dimming part when it is 100 or higher, part 4 is situated below part 5 for the same reason part 2 is below part 3
.L5:
	mov	r0, #7 @pin number is first input to softPwmWrite
	mov	r1, r4 @current PWM value is second input
	bl	softPwmWrite @execute softPwmWrite
	sub	r4, r4, #1 @decrement PWM value so LED dims
	mov	r0, #40 @delaying 40 milliseconds
	bl	delay @executing delay
.L4:
	cmp	r4, #0 @comparing current PWM value to 0 so we know whether to continue with part 5
	bgt	.L5 @branch to part 5 whenever PWM value is greater than 0
	mov	r0, #7 @turning off LED, so put pin number on input 1
	mov	r1, #0 @and value 0 on input 2
	bl	softPwmWrite @execute softPwmWrite with PWM value zero to turn off LED
	pop {ip, pc}