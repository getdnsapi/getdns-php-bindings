--TEST--
Test function php_getdns_list_get_data_type() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$recList = 0;
$result = php_getdns_context_get_upstream_recursive_servers($context, $recList);
var_dump($result, $recList);

$value = 0;
$result = php_getdns_list_get_data_type($recList, 0, $value);
var_dump($result, $value);

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
int(%d)
int(0)
int(%d)
