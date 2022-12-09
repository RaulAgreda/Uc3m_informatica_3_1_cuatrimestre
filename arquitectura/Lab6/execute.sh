#!/bin/sh
for thread in 2 4 8 16
	echo "Thread: $thread"
	for i in 1 2 3 4 5 6
	do
		./$1/counter ${thread} | grep Time
	done

