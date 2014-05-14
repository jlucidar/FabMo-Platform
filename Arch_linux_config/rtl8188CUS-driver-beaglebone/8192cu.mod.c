#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
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
	{ 0xfc51225e, "module_layout" },
	{ 0xf8568b26, "register_netdevice" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc411a2ab, "complete_and_exit" },
	{ 0xfbc74f64, "__copy_from_user" },
	{ 0xb2f0a763, "_raw_spin_unlock" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xdabdc780, "mutex_destroy" },
	{ 0x15692c87, "param_ops_int" },
	{ 0x67c2fa54, "__copy_to_user" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x97255bdf, "strlen" },
	{ 0xf0c592e5, "dev_set_drvdata" },
	{ 0x558d7366, "find_vpid" },
	{ 0x47939e0d, "__tasklet_hi_schedule" },
	{ 0x9210e001, "netif_carrier_on" },
	{ 0xb08ba1ba, "_raw_spin_lock_bh" },
	{ 0xb5cb2bce, "skb_clone" },
	{ 0x6fcbc405, "dev_get_by_name" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xf7802486, "__aeabi_uidivmod" },
	{ 0x49309ea6, "skb_copy" },
	{ 0xe300bf7, "schedule_work" },
	{ 0x695b2cfd, "down_interruptible" },
	{ 0x2a3aa678, "_test_and_clear_bit" },
	{ 0x109ae26e, "netif_carrier_off" },
	{ 0x4205ad24, "cancel_work_sync" },
	{ 0x671d4447, "usb_kill_urb" },
	{ 0x6e4d8dcc, "remove_proc_entry" },
	{ 0xad3f0674, "filp_close" },
	{ 0x4e830a3e, "strnicmp" },
	{ 0x1976aa06, "param_ops_bool" },
	{ 0x593a99b, "init_timer_key" },
	{ 0xf8712712, "mutex_unlock" },
	{ 0xa06b58a4, "usb_autopm_get_interface" },
	{ 0x85df9b6c, "strsep" },
	{ 0xec67db71, "usb_enable_autosuspend" },
	{ 0x999e8297, "vfree" },
	{ 0x6610861c, "usb_disable_autosuspend" },
	{ 0x91715312, "sprintf" },
	{ 0xca8eb743, "kthread_create_on_node" },
	{ 0x7d11c268, "jiffies" },
	{ 0x2794df0, "skb_trim" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xf37ff0f8, "__netdev_alloc_skb" },
	{ 0xb1616fe1, "netif_rx" },
	{ 0xc0296bd8, "__pskb_pull_tail" },
	{ 0x536ff674, "__init_waitqueue_head" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0x35b6b772, "param_ops_charp" },
	{ 0xfa2a45e, "__memzero" },
	{ 0xd5f2172f, "del_timer_sync" },
	{ 0x5f754e5a, "memset" },
	{ 0xc22e75d2, "_raw_spin_unlock_irqrestore" },
	{ 0xc1d08cba, "usb_deregister" },
	{ 0xc9dd8c1a, "__mutex_init" },
	{ 0x27e1a049, "printk" },
	{ 0x20c55ae0, "sscanf" },
	{ 0x71c90087, "memcmp" },
	{ 0xea75a2f3, "free_netdev" },
	{ 0xfaef0ed, "__tasklet_schedule" },
	{ 0x328a05f1, "strncpy" },
	{ 0x93e46674, "register_netdev" },
	{ 0x9006f9a9, "wireless_send_event" },
	{ 0xcd96e4da, "usb_control_msg" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0x5616f793, "skb_push" },
	{ 0x1ea8c392, "mutex_lock" },
	{ 0x9545af6d, "tasklet_init" },
	{ 0x8834396c, "mod_timer" },
	{ 0xf60cead8, "kill_pid" },
	{ 0xf53d8915, "arm_delay_ops" },
	{ 0xb1bac2d7, "skb_pull" },
	{ 0x38fb9dc2, "device_init_wakeup" },
	{ 0xa03b36ca, "usb_free_coherent" },
	{ 0x7177dad2, "init_net" },
	{ 0x2196324, "__aeabi_idiv" },
	{ 0x80a6aeaa, "dev_kfree_skb_any" },
	{ 0xd79b5a02, "allow_signal" },
	{ 0x59e5070d, "__do_div64" },
	{ 0x82072614, "tasklet_kill" },
	{ 0xa3986035, "flush_signals" },
	{ 0x24201fa2, "skb_queue_tail" },
	{ 0x15a4c41c, "netif_device_attach" },
	{ 0x7a7cbc7d, "usb_submit_urb" },
	{ 0xf704c1da, "usb_get_dev" },
	{ 0x15c30e6, "_raw_spin_unlock_bh" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0x91af69bc, "usb_put_dev" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x5952a882, "__raw_spin_lock_init" },
	{ 0x15130728, "eth_type_trans" },
	{ 0x71e69855, "create_proc_entry" },
	{ 0xf6403164, "wake_up_process" },
	{ 0x166ec38b, "_raw_spin_lock" },
	{ 0xafa620b7, "_raw_spin_lock_irqsave" },
	{ 0x9d6c2e48, "unregister_netdevice_queue" },
	{ 0x44da5d0f, "__csum_ipv6_magic" },
	{ 0x37a0cba, "kfree" },
	{ 0x9d669763, "memcpy" },
	{ 0x2d1cf0d, "dev_alloc_name" },
	{ 0xc9f5df35, "up" },
	{ 0x26344951, "usb_register_driver" },
	{ 0xa4af7012, "skb_dequeue" },
	{ 0x51457dbf, "unregister_netdev" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0x676bbc0f, "_set_bit" },
	{ 0xd2b2afe, "complete" },
	{ 0xb81960ca, "snprintf" },
	{ 0x4ba145fe, "__netif_schedule" },
	{ 0xca54fee, "_test_and_set_bit" },
	{ 0x99bb8806, "memmove" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0x68b60633, "usb_alloc_coherent" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x49ebacbd, "_clear_bit" },
	{ 0x2cfdc126, "skb_put" },
	{ 0xd1b1e58, "wait_for_completion_timeout" },
	{ 0x6d044c26, "param_ops_uint" },
	{ 0x8b21ee5b, "skb_copy_bits" },
	{ 0xd255336c, "dev_get_drvdata" },
	{ 0x2ff973d1, "usb_free_urb" },
	{ 0xa2e84b39, "usb_autopm_put_interface" },
	{ 0x760a0f4f, "yield" },
	{ 0x2b512046, "usb_alloc_urb" },
	{ 0x12985369, "filp_open" },
	{ 0x4cccd119, "alloc_etherdev_mqs" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v0BDAp8191d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp8176d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp8170d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp817Ed*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp817Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp817Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp817Dd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp8754d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp817Fd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp818Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp018Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp17C0d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp8177d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp8178d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp817Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp8191d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1058p0631d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2019pED17d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0DF6p0052d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v7392p7811d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8p8189d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0EB0p9071d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v06F8pE033d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v103Cp1629d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p3308d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v050Dp1102d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2019pAB2Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v20F4p648Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v4855p0090d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v13D3p3357d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0DF6p005Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp5088d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v4856p0091d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0846p9041d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2019p4902d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2019pAB2Ed*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p330Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:vCDABp8010d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0B05p17BAd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp1E1Ed*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04BBp094Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:vCDABp8011d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp0A8Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp317Fd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v13D3p3359d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v13D3p3358d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04F2pAFF7d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04F2pAFF9d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04F2pAFFAd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04F2pAFF8d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04F2pAFFBd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04F2pAFFCd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2019p1201d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p3307d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p330Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p3309d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0586p341Fd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v7392p7822d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2019pAB2Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8p8178d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07AAp0056d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v4855p0091d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v050Dp2102d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v050Dp2103d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v20F4p624Dd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0DF6p0061d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0B05p17ABd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0846p9021d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0846pF001d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0E66p0019d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0E66p0020d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v050Dp1004d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp2E2Ed*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2357p0100d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v06F8pE035d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04BBp0950d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0DF6p0070d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0789p016Dd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0BDAp8186d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "CE388896624E104C8F146BC");
