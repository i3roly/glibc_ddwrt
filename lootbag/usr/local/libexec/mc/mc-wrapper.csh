set MC_USER=`whoami`

if ($?TMPDIR) then
	setenv MC_PWD_FILE $TMPDIR/mc-$MC_USER/mc.pwd.$$
else
	setenv MC_PWD_FILE /tmp/mc-$MC_USER/mc.pwd.$$
endif

/usr/local/bin/mc -P "$MC_PWD_FILE" $*

if (-r "$MC_PWD_FILE") then
	setenv MC_PWD "`cat '$MC_PWD_FILE'`"
	if ("$MC_PWD" != "$cwd" && -d "$MC_PWD") then
		cd "$MC_PWD"
	endif
	unsetenv MC_PWD
endif

rm -f "$MC_PWD_FILE"
unsetenv MC_PWD_FILE
unsetenv MC_USER
