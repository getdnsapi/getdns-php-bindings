--TEST--
Test function php_getdns_dict_get_names() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$dict = php_getdns_context_get_api_information($context);
$names = 0;
$result = php_getdns_dict_get_names($dict, $names);
var_dump($result, $names);
php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
int(%d)
