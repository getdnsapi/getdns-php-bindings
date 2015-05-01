--TEST--
Test function php_getdns_print_json_list() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$recList = 0;
$result = php_getdns_context_get_upstream_recursive_servers($context, $recList);
var_dump($result, $recList);

$ppList = php_getdns_print_json_list($recList, TRUE);
var_dump($ppList);

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
int(%d)
string(%d) "%A"
