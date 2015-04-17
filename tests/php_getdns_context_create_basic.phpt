--TEST--
Test function php_getdns_context_create() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);
php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
