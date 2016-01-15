--TEST--
Test function php_getdns_str2rr_dict() by calling it with its expected arguments
--FILE--
<?php

$str = "getdnsapi.net.      3600    IN      SOA     getdnsapi.net. sysadmin.nlnetlabs.nl. 2113125402 450 600 345600 3600\n";
$dict = 0;
$origin = "foo";
$defaultTTL = 3600;
$result = php_getdns_str2rr_dict($str, $dict, $origin, $defaultTTL);
$ppDict = php_getdns_pretty_print_dict($dict);
var_dump($result, $dict, $ppDict);
php_getdns_dict_destroy($dict);

?>
--EXPECTF--
int(0)
int(%d)
string(%d) "%a"
