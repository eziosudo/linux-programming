#!/bin/sh

# Trap allows you to catch signals and execute code when they occur.

ctrlc_count=0

no_ctrlc()
{
    let ctrlc_count++
    echo
    if [ $ctrlc_count = 1 ]; then
        echo "Stop that."
    elif [ $ctrlc_count = 2 ]; then
        echo "Once more and I quit."
    else
        echo "ctrlc_count is: $ctrlc_count"
        echo "That's it.  I quit."
        exit
    fi
}

trap no_ctrlc INT

while true
do
    echo Sleeping
    sleep 10
done

trap_in_linuxprograming() {
  # $$表示当前进程的编号 [trap command signal]
  # INT 通常指 CTRL+C 引发的中断
  trap 'rm -f /tmp/my_tmp_file_$$' INT
  echo creating file /tmp/my_tmp_file_$$
  date >/tmp/my_tmp_file_$$

  echo "press interrupt (CTRL+C) to interrupt ...."
  while [ -f /tmp/my_tmp_file_$$ ]; do
    echo File exits
    sleep 1
  done

  echo The file no longer exists

  trap INT
  echo creating file /tmp/my_tmp_file_$$
  date >/tmp/my_tmp_file_$$

  echo "press interrupt (control-C) to interrupt ...."
  while [ -f /tmp/my_tmp_file_$$ ]; do
    echo File exists
    sleep 1
  done

  echo we never get here
  exist 0
}
