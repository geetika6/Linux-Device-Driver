struct file_operations fops=
{
    //.open=dev_open,
    //.release=dev_release
    open:dev_open,
    release:dev_release,
    write:dev_write,
    read:dev_read,
    unlocked_ioctl:dev_ioctl

} ;
