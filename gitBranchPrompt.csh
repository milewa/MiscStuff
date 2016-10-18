#!/bin/tcsh
setenv BRANCH `sh -c 'git rev-parse --is-inside-work-tree 2> /dev/null' | grep 'true'`
if( $BRANCH == "true") then
	setenv BRANCH `git rev-parse --symbolic-full-name --abbrev-ref HEAD
	set prompt="[$BRANCH]%n@%M:%/\% "
else
	unset BRANCH
	set prompt="%n@%M:%/\% "
endif

#Wrote this to set the git branch in the prompt within a cshell
#To use, in your .cshrc add "precmd "source /path/to/this/file"
