--TEST--
Test function php_getdns_context_detach_eventloop() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
$result = php_getdns_context_detach_eventloop($context);
var_dump($result);
$result = php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
