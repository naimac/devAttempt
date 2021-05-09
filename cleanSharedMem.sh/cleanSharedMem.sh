#!/bin/bash

IPCS=` ipcs | grep "[0-9]" | cut -f2 -d " " `

for id in $IPCS; do
	echo ${id}
	ipcrm -m ${id};
done
