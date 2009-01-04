#!/bin/sh
if [ ! -f $1 ]
then
        echo "no test file $1"
        exit 1
fi

TESTNAME="`echo $1 | sed 's/\.t$//'`"
echo $TESTNAME...

awk '{ if ($1 == "%%") hide = 1; if (hide != 1) print; }' <$TESTNAME.t >$TESTNAME.c
awk '{ if (show == 1) print; if ($1 == "%%") show = 1; }' <$TESTNAME.t >$TESTNAME.expect

../picoc $TESTNAME.c 2>&1 >$TESTNAME.out

if [ "x`diff -q $TESTNAME.expect $TESTNAME.out`" != "x" ]
then
        echo "error in test $TESTNAME"
        diff -u $TESTNAME.expect $TESTNAME.out
        rm -f $TESTNAME.c $TESTNAME.expect $TESTNAME.out
        exit 1
fi

rm -f $TESTNAME.c $TESTNAME.expect $TESTNAME.out

