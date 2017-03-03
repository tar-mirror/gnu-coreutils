#!/bin/sh
# Test for assertion failure in "test".

# Copyright (C) 1999-2012 Free Software Foundation, Inc.

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


# This test fails with tail from textutils-2.0.
# It would get something like this:
#   tail: tail.c:718: recheck: Assertion 'valid_file_spec (f)' failed.
#   Aborted
# due to a race condition in which a dev/inode pair is reused.

. "${srcdir=.}/tests/init.sh"; path_prepend_ ./src
print_ver_ tail

# Not "expensive" per se, but sleeping for so long is annoying.
very_expensive_

ok='ok ok ok'

touch a foo
tail --follow=name a foo > err 2>&1 &
tail_pid=$!
# Arrange for the tail process to die after 12 seconds.
(sleep 12; kill $tail_pid) &

echo sleeping for 7 seconds...

# Give the backgrounded 'tail' a chance to start before removing foo.
# Otherwise, without --retry, tail wouldn't try to open 'foo' again.
sleep 1

rm -f foo
sleep 6
echo $ok > f
mv f foo

# echo waiting....
wait

case "$(cat err)" in
  *$ok) ;;
  *) fail=1;;
esac

test $fail = 1 && cat err

Exit $fail
