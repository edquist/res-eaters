#!/usr/bin/perl -w
use strict;
use Time::HiRes qw(ualarm usleep);

my $work_px  = shift;
my $sleep_px = 100 - $work_px;
my $us_mul   = 500;
my $work_us  = $us_mul * $work_px;
my $sleep_us = $us_mul * $sleep_px;
my $x = 1;

$SIG{ALRM} = sub { usleep $sleep_us; ualarm $work_us; };
ualarm $work_us;

$x = $x + 12345 while 1;

