struct file_operations fops=
{
    //.open=dev_open,
    //.release=dev_release
    open:dev_open,
    release:dev_release,
    write:dev_write

} ;
