--TEST--
Test function php_getdns_dict_get_data_type() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$dict = php_getdns_context_get_api_information($context);
$value = 0;
$result = php_getdns_dict_get_data_type($dict, "version_string", $value);
var_dump($result, $value);
php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
int(3)
