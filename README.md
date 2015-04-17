getdns-php
==========

A PHP language binding for the getdns API, version 0.1.0.
This implementation is licensed under the New BSD License (BSD-new).

NOTE: THIS IS AN ALPHA RELEASE!

Dependencies:

* libgetdns 0.1.7
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
doc-out/php-chunked-xhtml/index.html. Note that a small
number of asynchronous event management functions remain
undocumented.

## Regression Tests

An incomplete suite of regression tests (written in
[phpt](http://qa.php.net/write-test.php) format) is included
with the extension. Test cases can be found in the tests
directory. All of the tests can be executing by running
"make test" after building the extension as described
above.

## To Do

* Complete the documentation.
* Complete test case development.
* Test and confirm asnynchronous function operation. Limited
testing of `php_getdns_address()` has been done. While the code
"works", asynch operation needs to be confirmed.
* Finish wrapper functions for the following library functions:
  * `getdns_context_set_eventloop()`
* A whole bunch of other things not yet listed here. Remember, this
is an ALPHA release.
