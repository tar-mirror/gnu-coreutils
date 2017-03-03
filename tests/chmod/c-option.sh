#!/bin/sh
# Verify that chmod's --changes (-c) option works.

# Copyright (C) 2000-2012 Free Software Foundation, Inc.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

. "${srcdir=.}/tests/init.sh"; path_prepend_ ./src
print_ver_ chmod

umask 0
file=f
touch $file || framework_failure_
chmod 444 $file || framework_failure_

skip_if_setgid_


chmod u=rwx $file || fail=1
chmod -c g=rwx $file > out || fail=1
chmod -c g=rwx $file > empty || fail=1

test -s empty && fail=1
case "$(cat out)" in
  "mode of 'f' changed from 0744 "?rwxr--r--?" to 0774 "?rwxrwxr--?) ;;
  *) cat out; fail=1 ;;
esac

Exit $fail
