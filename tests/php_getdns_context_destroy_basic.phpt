--TEST--
Test function php_getdns_context_destroy() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
$result = php_getdns_context_destroy($context);
var_dump($result);

?>
--EXPECT--
NULL
