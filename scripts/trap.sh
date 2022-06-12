#!/bin/sh

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
