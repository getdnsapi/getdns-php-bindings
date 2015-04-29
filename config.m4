PHP_ARG_ENABLE(getdns,
  [whether to enable the "getdns" extension],
  [ --enable-getdns   Enable getdns support])

if test "$PHP_GETDNS" != "no"; then
  AC_MSG_CHECKING(for libgetdns in default path)
  for i in /usr/local /usr; do
    if test -r $i/lib/libgetdns.so; then
      GETDNS_DIR=$i
      AC_MSG_RESULT(found libgetdns.so in $i)
    fi
  done

  if test -z "$GETDNS_DIR"; then
    AC_MSG_RESULT(not found)
    AC_MSG_ERROR(Please install the libgetdns library)
  fi

  AC_MSG_CHECKING(for libgetdns_ext_event in default path)
  for i in /usr/local /usr; do
    if test -r $i/lib/libgetdns_ext_event.so; then
      GETDNS_EVENT_DIR=$i
      AC_MSG_RESULT(found libgetdns_ext_event.so in $i)
    fi
  done

  if test -z "$GETDNS_EVENT_DIR"; then
    AC_MSG_RESULT(not found)
    AC_MSG_ERROR(Please install the libgetdns_ext_event library)
  fi

  AC_MSG_CHECKING([getdns header files])
  GETDNS_INC_DIR="/usr/local/include/getdns"
  INC_FILES="$GETDNS_INC_DIR/getdns.h $GETDNS_INC_DIR/getdns_extra.h $GETDNS_INC_DIR/getdns_ext_libevent.h"
  for i in $INC_FILES; do
    if test ! -f $i; then
      AC_MSG_ERROR([getdns header files not found in $GETDNS_INC_DIR])
    fi
  done
  AC_MSG_RESULT($GETDNS_INC_DIR)

  PHP_CHECK_LIBRARY(getdns, getdns_context_create,
    [
      AC_DEFINE(HAVE_LIBGETDNS, 1, [ ])
    ],
    [
      AC_MSG_ERROR([Invalid libgetdns.])
    ],
    [
      -L$GETDNS_DIR/lib -lgetdns -lgetdns_ext_event
    ]
  )

  PHP_SUBST(GETDNS_SHARED_LIBADD)
  PHP_ADD_LIBRARY_WITH_PATH(getdns, $GETDNS_DIR/lib, GETDNS_SHARED_LIBADD)
  PHP_ADD_LIBRARY_WITH_PATH(getdns_ext_event, $GETDNS_DIR/lib, GETDNS_SHARED_LIBADD)
  PHP_ADD_INCLUDE($GETDNS_INC_DIR)
  AC_DEFINE(HAVE_GETDNS, 1, [whether the getdns extension is enabled])
  PHP_NEW_EXTENSION(getdns, phpgetdns.c, $ext_shared)
fi
