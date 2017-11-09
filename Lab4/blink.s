
.global main
.extern system


main:
LDR R0, "echo \"40\" > /sys/class/gpio/export"
	