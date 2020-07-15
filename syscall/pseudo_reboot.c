/*
 * 2020 07 15 
 * Linux Kernel Development written by Robert Love
 * pg 145
 * 
 * reboot system call?
 * 
 * create by inhoinno
 * 
 *
 *
 * */
SYSCALL_DEFINE4(reboot,
		int, magic1,
		int, magic2,
		unsiged int, cmd,
		void __user *, arg)
{
	char buffer[256];

	/*시스템 재시작의 경우 루트 사용자su 의 명령만 믿어야한다 */
	if(!capable(CAP_SYS_BOOT))
		return -EPERM;

	/*for safety, we use argument name 'magic'*/
	if(magic1 != LINUX_REBOOT_MAGIC1 || 
			(magic2 != LINUX_REBOOT_MAGIC2 &&
			 magic2 != LINUX_REBOOT_MAGIC2A &&
			 magic2 != LINUX_REBOOT_MAGIC2B &&
			 magic2 != LINUX_REBOOT_MAGIC2C))
		return -EINVAL;

	/*pm_power_off 가 설정되지 않은 경우에는, 
	 * power_off 대신 halt같은 쉬운 방법을 대신 사용한다*/
	if((cmd == LINUX_REBOOT_CMD_POWER_OFF) && !pm_power_off)
		cmd = LINUX_REBOOT_CMD_HALT;
	
	lock_kernel();
	switch(cmd){
		case LINUX_REBOOT_CMD_RESTART:
			kernel_restart(NULL);
			break;

		case LINUX_REBOOT_CMD_CAD_ON:
			C_A_D=1;
			break;

		case LINUX_REBOOT_CMD_CAD_OFF:
			C_A_D =0;
			break;

		case LINUX_REBOOT_CMD_HALT :
			kernel_halt();
			unlock_kernel();
			do_exit(0);
			break;

		case LINUX_REBOOT_CMD_POWER_OFF:
			kernel_power_off();
			unlock_kernel();
			do_exit(0);
			break;

		case LINUX_REBOOT_CMD_RESTART2:
			if (strncpy_from_user(&buffer[0],arg,sizeof(buffer)-1)<0){
				unlock_kernel();
				return -EFAULT;
			}
			buffer[sizeof(buffer)-1] = '\0';

			kernel_restart(buffer);
			break;
		default :
			unlock_kernel();
			return -EINVAL;
	}//switch END
	unlock_kernel();
	return 0;
	

}
