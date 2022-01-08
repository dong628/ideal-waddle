#!/bin/bash

a="$(ssh 192.168.31.74 -l Jinglei stat --format=%X /Share/Jinglei/Database.kdbx)"
b="$(stat --format=%X /home/archer/Documents/Database.kdbx)"

c="$(ssh 192.168.31.74 -l Jinglei stat --format=%s /Share/Jinglei/Database.kdbx)"
d="$(stat --format=%s /home/archer/Documents/Database.kdbx)"

if [ $c == $d ]
then
	echo "Everything up-to-date!" > /dev/pts/0
else

	date >> /home/archer/CronScripts/keesync.log

	echo "remote : $a" >> /home/archer/CronScripts/keesync.log
	echo "local  : $b" >> /home/archer/CronScripts/keesync.log

	if [ $a -gt $b ]
	then
		echo "Syncing remote -> local" > /dev/pts/0
		echo "Syncing remote -> local" >> /home/archer/CronScripts/keesync.log
		rsync -av -e "ssh -p 22" Jinglei@192.168.31.74:/Share/Jinglei/Database.kdbx /home/archer/Documents/Database.kdbx >> /home/archer/CronScripts/keesync.log
		cd /home/archer/Documents
		git add Database.kdbx
		git commit -m "Update Database.kdbx"
		git push >> /home/archer/CronScripts/keesync.log
	else
		echo "Syncing local -> remote" > /dev/pts/0
		echo "Syncing local -> remote" >> /home/archer/CronScripts/keesync.log
		rsync -av -e "ssh -p 22" /home/archer/Documents/Database.kdbx  Jinglei@192.168.31.74:/Share/Jinglei/Database.kdbx >> /home/archer/CronScripts/keesync.log
	fi

	echo "Sync Finished!" > /dev/pts/0

	echo >> /home/archer/CronScripts/keesync.log
	echo "------------------------------" >> /home/archer/CronScripts/keesync.log
	echo >> /home/archer/CronScripts/keesync.log
fi
