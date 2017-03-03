#!/usr/bin/perl
# Exercise a bug with pr -m -s

# Copyright (C) 2007-2012 Free Software Foundation, Inc.

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

use strict;

(my $program_name = $0) =~ s|.*/||;

$ENV{PROG} = 'pr';
my $ME = $ENV{PROG};

# Turn off localization of executable's output.
@ENV{qw(LANGUAGE LANG LC_ALL)} = ('C') x 3;

my @Tests =
  (
   ['merge-w-tabs', '-m -s -t',
    {IN=>{1=>"a\tb\tc\n"}},
    {IN=>{2=>"m\tn\to\n"}},
    {IN=>{3=>"x\ty\tz\n"}},
     {OUT=>join("\t", qw(a b c m n o x y z)) . "\n"} ],
  );

my $save_temps = $ENV{DEBUG};
my $verbose = $ENV{VERBOSE};

my $prog = $ENV{PROG} || die "$0: \$PROG not specified in environment\n";
my $fail = run_tests ($program_name, $prog, \@Tests, $save_temps, $verbose);
exit $fail;
