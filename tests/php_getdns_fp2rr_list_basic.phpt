--TEST--
Test function php_getdns_fp2rr_list() by calling it with its expected arguments
--FILE--
<?php

$fileName = "./tests/example.com.db";
$list = 0;
$origin = "foo";
$defaultTTL = 3600;
$result = php_getdns_fp2rr_list($fileName, $list, $origin, $defaultTTL);
$ppList = php_getdns_pretty_print_list($list);
var_dump($result, $list, $ppList);
php_getdns_list_destroy($list);

?>
--EXPECTF--
int(0)
int(%d)
string(%d) "%a"
