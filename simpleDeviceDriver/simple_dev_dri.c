/******************************
 * Simple Device Driver Structure
 * (to implement System call) 
 * *****************************
 *
 * created by inhoinno, 
 * 15July2020
 * CONTACT : mearrong123@gmail.com 
 *
 * src from : "https://butter-shower.tistory.com/30"
 *
 * */
//--Header Files--
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/init.h>
//----------------
//
//funcation Prototypes & Definitions
int device_open(...){...};
int device_release(...){...};
ssize_t device_write(...){...};
ssize_t device_read(...){...};
//-----------------------------------

//File Operation
static struct file_operations device_fops= {
	.open = device_read,
	.release = device_release,
	.write = device_write,
	.read = device_read,
	.ioctl = ...
};
//----------------



module_init(init_);
module_exit(exit_)




