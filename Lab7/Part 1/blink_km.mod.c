#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xb344870e, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xfe990052, __VMLINUX_SYMBOL_STR(gpio_free) },
	{ 0x979acc4d, __VMLINUX_SYMBOL_STR(gpiod_unexport) },
	{ 0xf20dabd8, __VMLINUX_SYMBOL_STR(free_irq) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xd6b8e852, __VMLINUX_SYMBOL_STR(request_threaded_irq) },
	{ 0x14b94ab8, __VMLINUX_SYMBOL_STR(gpiod_to_irq) },
	{ 0xd3b7a49b, __VMLINUX_SYMBOL_STR(gpiod_set_debounce) },
	{ 0xc1c8e1d4, __VMLINUX_SYMBOL_STR(gpiod_direction_input) },
	{ 0xd225fb38, __VMLINUX_SYMBOL_STR(gpiod_export) },
	{ 0xd5f4eaf7, __VMLINUX_SYMBOL_STR(gpiod_direction_output_raw) },
	{ 0x47229b5c, __VMLINUX_SYMBOL_STR(gpio_request) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x64f8b539, __VMLINUX_SYMBOL_STR(gpiod_set_raw_value) },
	{ 0x717905ad, __VMLINUX_SYMBOL_STR(gpiod_get_raw_value) },
	{ 0xcd387ee9, __VMLINUX_SYMBOL_STR(gpio_to_desc) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "915A98286B51DE9457BD58B");
