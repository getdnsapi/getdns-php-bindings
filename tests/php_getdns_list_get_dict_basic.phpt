--TEST--
Test function php_getdns_list_get_dict() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$recList = 0;
$result = php_getdns_context_get_upstream_recursive_servers($context, $recList);
var_dump($result, $recList);

$dict = 0;
$result = php_getdns_list_get_dict($recList, 0, $dict);
var_dump($result, $dict);

php_getdns_context_destroy($context);

?>
--EXPECTF--
int(0)
int(0)
int(%d)
int(0)
int(%d)
