--TEST--
Test function php_getdns_context_get_num_pending_requests() by calling it with its expected arguments
--FILE--
<?php

$context = 0;
$setFromOS = 1;
$result = php_getdns_context_create($context, $setFromOS);
var_dump($result);

$result = php_getdns_context_get_num_pending_requests($context);
var_dump($result);
php_getdns_context_destroy($context);

?>
--EXPECT--
int(0)
int(0)
