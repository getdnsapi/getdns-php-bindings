getdns-php
==========

A PHP language binding for the getdns API, version 0.4.0.
This implementation is licensed under the New BSD License (BSD-new).

NOTE: THIS IS AN ALPHA RELEASE!

Dependencies:

* PHP 5.x (PHP 5.5.9 was used for development and testing)
* libgetdns 0.1.7 (configured with --with-libevent)
* libgetdns_ext_event 0.1.7
* getdns library header files

The configure script will confirm that the dependencies have been met,
but it will not check version numbers.

To build:

    $ phpize
    $ ./configure --enable-getdns
    $ make
    $ sudo make install

To clean:

    $ make clean
    $ phpize --clean

Note that the following getdns library functions are not
implemented in this extension:

* getdns_context_create_with_memory_functions()
* getdns_context_create_with_extended_memory_functions()
* getdns_context_set_eventloop()
* getdns_context_set_memory_functions()
* getdns_context_set_extended_memory_functions()
* getdns_dict_create_with_memory_functions()
* getdns_dict_create_with_extended_memory_functions()
* getdns_list_create_with_memory_functions()
* getdns_list_create_with_extended_memory_functions()
* getdns_pretty_snprint_dict()
* getdns_pretty_snprint_list()
* getdns_snprint_json_dict()
* getdns_snprint_json_list()

Each makes assumptions about memory management functions
that aren't directly applicable to PHP.

## Documentation

Documentation is written in the DocBook format preferred
by the PHP community. XML input files can be found in the
doc-in directory.

Documentation intended for human consumption is provided in
HTML format and can be found in the doc-out directory. The
documentation root can be found at
doc-out/php-chunked-xhtml/index.html.

## Regression Tests

An incomplete suite of regression tests (written in
[phpt](http://qa.php.net/write-test.php) format) is included
with the extension. Test cases can be found in the tests
directory. All of the tests can be executing by running
"make test" after building the extension as described
above.

## To Do

* Complete testing and test case development.
* A whole bunch of other things not yet listed here. Remember, this
is an ALPHA release.
