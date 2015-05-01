--TEST--
Test function php_getdns_pretty_print_dict() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);

$dictionary = 0;
$dictionary = php_getdns_context_get_api_information($context);
var_dump($result, $dictionary);

$ppDict = php_getdns_pretty_print_dict($dictionary);
var_dump($ppDict);

php_getdns_dict_destroy($dictionary);
php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(%d)
string(%d) "%A"
